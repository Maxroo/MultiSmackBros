// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "SplatiatorCharacterTest.generated.h"

/**
 * 
 */
UCLASS()
class MULTISMACKBROS_API ASplatiatorCharacterTest : public ACharacterBase
{
	GENERATED_BODY()


protected:


	virtual void BeginPlay() override;
	bool IsInNeutral = false;
	virtual void NeutralAttack() override;

	FTimerHandle NeutralAttackDelay;


public:

	void ResetNeutral();
};


