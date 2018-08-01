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

	TapTherhold = 0.5f;
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

	if(GetCharacterMovement()->IsFalling() && CanJump == true )
	{
		GetCharacterMovement()->bOrientRotationToMovement = false;
		WasInAir = true;
		CanJump = false;
	}
	else if (!GetCharacterMovement()->IsFalling())
	{
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



}

void ACharacterBase::MoveRight(float amount)
{
	FTimerHandle DashTimerHandle;
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Bool: %s"), hold ? TEXT("true") : TEXT("false")));
		
	/*if (Controller != nullptr && !FMath::IsNearlyZero(amount))
		{*/
			
				
			if (FMath::Abs(amount) >= 0.8f)
			{
				if (!hold)

					Tapcount++;
					hold = true;
					if(!candash)
					{
					OpenDash();
					GetWorldTimerManager().SetTimer(DashTimerHandle, this, &ACharacterBase::CloseDash, TapTherhold, false);
					}
				if (candash && Tapcount == 2)
				{

					GetCharacterMovement()->MaxWalkSpeed = 1000;
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Dashing"));

				} else
				{

					GetCharacterMovement()->MaxWalkSpeed = 600;
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("StopDashing"));
				}

			}
				if (FMath::Abs(amount) <= 0.1f)
				{
					hold = false;
					if (!candash)
					{
						Tapcount = 0;
					}
					if(candash && Tapcount ==2)
					{Tapcount = 0;}
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
}

<<<<<<< HEAD
		
	
	
	
	
	
	
	checkdooncefordash = false;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dashing"));
=======
void ACharacterBase::OpenDash()
{
	candash = true;
>>>>>>> 41b29d19d499817584f6e418c9894589aa4b941e
}

void ACharacterBase::LandDelay()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	CanJump = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "DelayOver");
}

void ACharacterBase::RollRight()
{
	isInvincible = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "isInvincible");
	ACharacterBase::LaunchCharacter(FVector(0, -1750, 0), true, true);
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ACharacterBase::RollEnd, .15, false);




















}
// roll 163 - 190
// LaunCharacter test
//LaunchCharacter(FVector(addforce.X*Dashdistance, 0, 0), false, true);
//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dashing"));
void ACharacterBase::RollEnd()
{
	isInvincible = false;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "isNotInvincible");
	GetCharacterMovement()->StopMovementImmediately();
}
void ACharacterBase::RollLeft()
{
	isInvincible = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "isInvincible");
	ACharacterBase::LaunchCharacter(FVector(0, 1750, 0), true, true);
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ACharacterBase::RollEnd, 0.15, false);





















}