// Fill out your copyright notice in the Description page of Project Settings.

#include "SplatiatorCharacterTest.h"
#include "TimerManager.h"
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
	
void ASplatiatorCharacterTest::NeutralAttack()
{
	UBoxComponent *hurtBox;

	if ( GetWorldTimerManager().GetTimerRemaining(NeutralAttackTime) <= 0.0f)
	{
		GetWorldTimerManager().SetTimer(NeutralAttackTime, this, &ACharacterBase::CloseDash, 0.5f, false);
		IsNeutralAttack = true;
		hurtBox = CreateDefaultSubobject<UBoxComponent>("Box", false);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Attack");
	}
		
	
}

void ASplatiatorCharacterTest::ExitAttack()
{
	IsNeutralAttack = false;
}

