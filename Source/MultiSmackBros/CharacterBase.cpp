// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine.h"


// Sets default values
ACharacterBase::ACharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 1800.0f, 0.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = .7f;
	GetCharacterMovement()->GravityScale = 1.3f;

	TapTherhold = 0.2f;
	Dashdistance = 500.0f;
	addforce = GetActorForwardVector();
	Deltatime = 0.0f;
	Movespeed = 10.0f;
	candash = false;
	Tapcount = 0;
	hold = false;
	
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->SetActorLocation(FVector(this->GetActorLocation().X, this->GetActorLocation().Y, this->GetActorLocation().Z));

	if (GetCharacterMovement()->IsFalling() && CanJump == true)
	{
		GetCharacterMovement()->bOrientRotationToMovement = false;
		WasInAir = true;
		CanJump = false;
	}
	else if (!GetCharacterMovement()->IsFalling())
	{
		FreeFall = false;
		if (WasInAir == true)
		{
			WasInAir = false;
			GetWorldTimerManager().SetTimer(JumpDelay, this, &ACharacterBase::LandDelay, 1.0f, false, .25f);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "GotHere");
		}
	}
}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterBase::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("RollRight", IE_Pressed, this, &ACharacterBase::RollRight);
	PlayerInputComponent->BindAction("RollLeft", IE_Pressed, this, &ACharacterBase::RollLeft);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ACharacterBase::NeutralAttack);
	PlayerInputComponent->BindAction("Special", IE_Pressed, this, &ACharacterBase::isPressingBVoid);
	PlayerInputComponent->BindAxis("Up", this, &ACharacterBase::isPressingUpVoid);

}

void ACharacterBase::MoveRight(float amount)
{

	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Bool: %s"), hold ? TEXT("true") : TEXT("false")));

	/*if (Controller != nullptr && !FMath::IsNearlyZero(amount))
	{*/


	if (FMath::Abs(amount) >= 0.6f)
	{
		if (!candash && !hold)
		{
			OpenDash();
			GetWorldTimerManager().SetTimer(DashTimerHandle, this, &ACharacterBase::CloseDash, TapTherhold, false);
		}
		if (!hold)
		{

			Tapcount++;
			hold = true;
		}
		if (candash && Tapcount > 1 && !IsDashing)
		{

			GetCharacterMovement()->MaxWalkSpeed = 2000;
			GetCharacterMovement()->MaxAcceleration = 5000;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Dashing"));
			IsDashing = true;


		}
		else if (!hold)
		{
			//IsDashing = false;
			//GetCharacterMovement()->MaxWalkSpeed = 600;
			//GetCharacterMovement()->MaxAcceleration = 200;
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("StopDashing"));
		}

	}
	else if (FMath::Abs(amount) <= 0.1f)
	{
		hold = false;
		if (!candash)
		{
			Tapcount = 0;
		}
		if (candash && Tapcount == 2)
		{
			Tapcount = 0;
		}
		if (IsDashing)
		{
			IsDashing = false;
			GetCharacterMovement()->MaxWalkSpeed = 600;
			GetCharacterMovement()->MaxAcceleration = 600;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("StopDashing"));
		}

	}
	//AddMovementInput(this->GetActorForwardVector(), amount*Movespeed, false);
	AddMovementInput(FVector(0.f, -1.f, 0.f), amount);
	//}
}


void ACharacterBase::NeutralAttack()
{














}

void ACharacterBase::CloseDash()
{
	if (!hold)
	{
		Tapcount = 0;
	}
	candash = false;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Dash Closed"));
}


//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dashing"));

void ACharacterBase::OpenDash()
{
	candash = true;

}

void ACharacterBase::LandDelay()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	CanJump = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "DelayOver");
}

void ACharacterBase::RollRight()
{
	if (FreeFall == false) {
		if (isInRollEndLag == false) {
			DisableInput(Cast<APlayerController>(GetController()));
			isInvincible = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "isInvincible");
			//ACharacterBase::LaunchCharacter(FVector(0, -1750, 0), true, true);
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &ACharacterBase::RollEnd, .1, false);
			GetWorldTimerManager().SetTimer(Smooth, this, &ACharacterBase::IncrementRollRight, .01, true);
			/*while (GetWorldTimerManager().GetTimerElapsed(UnusedHandle) < 0.15)
			{
			this->AddActorWorldOffset(FVector(0, 10, 0), true, nullptr, ETeleportType::None);
			}*/
		}
	}















}
// roll 163 - 190
// LaunCharacter test
//LaunchCharacter(FVector(addforce.X*Dashdistance, 0, 0), false, true);
//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dashing"));
void ACharacterBase::RollEnd()
{
	EnableInput(Cast<APlayerController>(GetController()));
	isInvincible = false;
	FreeFall = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "isNotInvincible");
	GetWorldTimerManager().ClearTimer(Smooth);
	isInRollEndLag = true;
	GetWorldTimerManager().SetTimer(EndRollDelay, this, &ACharacterBase::ResetRoll, .3, false, .3);
	//GetCharacterMovement()->StopMovementImmediately();
}
void ACharacterBase::RollLeft()
{
	if (FreeFall == false) {
		if (isInRollEndLag == false) {
			DisableInput(Cast<APlayerController>(GetController()));
			isInvincible = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "isInvincible");
			//ACharacterBase::LaunchCharacter(FVector(0, 1750, 0), true, true);

			GetWorldTimerManager().SetTimer(UnusedHandle, this, &ACharacterBase::RollEnd, 0.1, false);
			GetWorldTimerManager().SetTimer(Smooth, this, &ACharacterBase::IncrementRollLeft, 0.01, true);
			/*for (float f = GetWorldTimerManager().GetTimerElapsed(UnusedHandle); f < .15; f += .001)
			{
			this->AddActorWorldOffset(FVector(0, 2, 0), true, nullptr, ETeleportType::None);
			}
			/*while (GetWorldTimerManager().GetTimerElapsed(UnusedHandle) < 0.15)
			{
			this->AddActorWorldOffset(FVector(0, 10, 0), true, nullptr, ETeleportType::None);
			}*/

		}
	}



















}

void ACharacterBase::IncrementRollLeft()
{
	this->AddActorWorldOffset(FVector(0, 15, 0), true, nullptr, ETeleportType::None);
}


void ACharacterBase::IncrementRollRight()
{
	this->AddActorWorldOffset(FVector(0, -15, 0), true, nullptr, ETeleportType::None);
}

void ACharacterBase::ResetRoll()
{
	isInRollEndLag = false;
}

void ACharacterBase::UpSpecial()
{




}

void ACharacterBase::GetDamaged(float damageAmount, FVector hitLocation, FVector pushVector)
{
	DamagePercentage += damageAmount;
	FVector pushForce;
	pushForce = hitLocation - GetActorLocation();
	pushForce.Normalize();
	GetCharacterMovement()->Launch(FVector(0.0f, pushVector.Y * DamagePercentage * -pushForce.Y, pushVector.Z * DamagePercentage));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::FromInt(damageAmount));

}
void ACharacterBase::isPressingBVoid()
{
	isPressingB = true;
}
void ACharacterBase::isPressingUpVoid(float amount)
{
	if (amount >= 0) {
		isPressingUp = true;
	}
	else
	{
		isPressingUp = false;
	}
}