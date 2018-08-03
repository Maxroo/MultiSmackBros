// Fill out your copyright notice in the Description page of Project Settings.

#include "SplatiatorCharacterTest.h"
#include "hurtBox.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "Engine.h"


void ASplatiatorCharacterTest::NeutralAttack()
{
	FName handSocketName = TEXT("Hand");

	AhurtBox *NeutralHB;

	if(!IsInNeutral){
	GetWorldTimerManager().SetTimer(NeutralAttackDelay, this, &ASplatiatorCharacterTest::ResetNeutral, 0.5f, false);
	FVector Location(this->GetActorLocation());
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	NeutralHB = GetWorld()->SpawnActor<AhurtBox>(Location, Rotation, SpawnInfo);
	NeutralHB->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, handSocketName);
	NeutralHB->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Attack"));
	IsInNeutral = true;
	}
}

void ASplatiatorCharacterTest::ResetNeutral()
{
	IsInNeutral = false;
}
