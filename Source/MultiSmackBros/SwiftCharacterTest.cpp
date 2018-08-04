// Fill out your copyright notice in the Description page of Project Settings.

#include "SwiftCharacterTest.h"
#include "hurtBox.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "Engine.h"


void ASwiftCharacterTest::NeutralAttack()
{
	FName handSocketName = TEXT("TestHitBox");

	AhurtBox *NeutralHB;

	if (!IsInNeutral && !FreeFall) {
		GetWorldTimerManager().SetTimer(NeutralAttackDelay, this, &ASwiftCharacterTest::ResetNeutral, 0.5f, false);
		FVector Location(this->GetActorLocation());
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Instigator = this;
		NeutralHB = GetWorld()->SpawnActor<AhurtBox>(Location, Rotation, SpawnInfo);
		NeutralHB->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, handSocketName);
		DisableInput(Cast<APlayerController>(GetController()));
		NeutralHB->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Attack"));
		IsInNeutral = true;
	}
}

void ASwiftCharacterTest::UpSpecial()
{

}
void ASwiftCharacterTest::ResetNeutral()
{
	IsInNeutral = false;
	EnableInput(Cast<APlayerController>(GetController()));
}

