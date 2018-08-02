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
	virtual void NeutralAttack() override;
	void ExitAttack();

	bool IsNeutralAttack = false;
	FTimerHandle NeutralAttackTime;
};


