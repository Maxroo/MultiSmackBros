// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "GameFramework/Character.h"
#include "SwiftCharacterTest.generated.h"

UCLASS()
class MULTISMACKBROS_API ASwiftCharacterTest : public ACharacterBase
{
	GENERATED_BODY()

protected:
	virtual void NeutralAttack() override;
	virtual void UpSpecial() override;
	virtual void SideSpecial(int dir) override;
	FTimerHandle NeutralAttackDelay;
	bool IsInNeutral = false;

public:	

	void ResetNeutral();
	
};
