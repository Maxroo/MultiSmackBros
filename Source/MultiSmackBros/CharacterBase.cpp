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
	checkdooncefordash = true;



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
}

void ACharacterBase::MoveRight(float amount)
{
	if (Controller != nullptr && !FMath::IsNearlyZero(amount))
	{

		//AddMovementInput(this->GetActorForwardVector(), amount*Movespeed, false);
		if (FMath::Abs(amount) >= 0.8f && checkdooncefordash)
		{
				Dash();
			/*UWorld* GetTime = nullptr;
			if ((GetTime->GetRealTimeSeconds() - LastTaptime) <= TapTherhold)
			{
				LastTaptime = GetTime->GetRealTimeSeconds();
			}
			else
			{
				LastTaptime = GetTime->GetRealTimeSeconds();
			}
			checkdooncefordash = false;*/




















				checkdooncefordash = false;
		}

		if (amount <= 0.1f && !checkdooncefordash)
		{
			checkdooncefordash = true;
		}
		AddMovementInput(FVector(0.f, -1.f, 0.f), amount);
	}
}

void ACharacterBase::NeutralAttack()
{














}

void ACharacterBase::Dash()
{

		
	
	
	
	
	
	
	
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dashing"));
}

void ACharacterBase::LandDelay()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	CanJump = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "DelayOver");
}

void ACharacterBase::Roll(float dir)
{
	
























}
// roll 163 - 190
// LaunCharacter test
//LaunchCharacter(FVector(addforce.X*Dashdistance, 0, 0), false, true);
//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dashing"));