// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameMode.h"
#include "PlayerControllerBase.h"
#include "CharacterBase.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"


AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = ACharacterBase::StaticClass();
}


void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::CreatePlayer(this, -1, true);
	UGameplayStatics::CreatePlayer(this, -1, true);
}

void AMyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%f"),GetNumPlayers()));
}
void AMyGameMode::spawnplayer()
{
}
