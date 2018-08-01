// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class MULTISMACKBROS_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

	UPROPERTY(EditAnywhere)
		float Dashdistance;
	bool hold;
	int32 Tapcount;
	float Deltatime;
	float LastTaptime;
	float TapTherhold;
	float CurrentTime;
	bool candash;
	bool isInvincible = false;
	UPROPERTY(EditAnywhere)
		float Movespeed;

	FVector addforce;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle JumpDelay;
	bool CanJump = true;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveRight(float amount);
	virtual void NeutralAttack();
	bool WasInAir = false;
	void CloseDash();
	void OpenDash();

	void LandDelay();
	void RollRight();
	void RollEnd();
	void RollLeft();
};
