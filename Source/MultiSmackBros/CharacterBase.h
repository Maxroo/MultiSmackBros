// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RespawnPoint.h"

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
	bool isInRollEndLag = false;
	bool isPressingUp = false;
	bool isPressingB = false;
	bool isHoldingRight = false;
	bool isHoldingLeft = false;
	UPROPERTY(EditAnywhere)
		float Movespeed;

	FVector addforce;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float DamagePercentage = 0;

	FTimerHandle JumpDelay;
	FTimerHandle DashTimerHandle;
	FTimerHandle UnusedHandle;
	FTimerHandle Smooth;
	FTimerHandle EndRollDelay;
	FTimerHandle HitStun;
	FTimerHandle RespawnDelay;
	FTimerHandle ReleaseB;


	bool CanJump = true;
	bool FreeFall = false;
	bool IsInHitstun = false;

	TArray<AActor*> Spawns;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveRight(float amount);

	virtual void NeutralAttack();

	virtual void UpSpecial();

	virtual void SideSpecial(int dir);

	bool IsDashing;
	bool WasInAir = false;

	void GetDamaged(float damageAmount, FVector hitLocation, FVector pushVector, float hitstunTime);
	void CloseDash();
	void OpenDash();
	void LandDelay();
	void RollRight();
	void RollEnd();
	void RollLeft();
	void IncrementRollLeft();
	void IncrementRollRight();
	void ResetRoll();
	void isPressingBVoid();
	void isPressingUpVoid(float amount);
	void NeutralAttackCheck();
	void ExitHitStun();
	void Death();
	void Respawn();
	void ReleaseBVoid();
};
