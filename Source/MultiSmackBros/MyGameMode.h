// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PlayerControllerBase.h"
#include "CharacterBase.h"
#include "GameFramework/Actor.h"
#include "GameCamera.h"
#include "MyGameMode.generated.h"

/**
*
*/
UCLASS()
class MULTISMACKBROS_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()


public:
	AMyGameMode();

	FVector Spawnpoint1;
	FVector Spawnpoint2;
	FVector Spawnpoint3;
	FVector Spawnpoint4;





	// Called when the game starts or when spawned

	APlayerController* P1;
	APlayerController* P2;
	APlayerController* P3;
	APlayerController* P4;

	APawn* PC1;
	APawn* PC2;
	APawn* PC3;
	APawn* PC4;



	TArray<APlayerControllerBase> playerControllersArray;
	TArray<float> Distancebetweenallplayer;


protected:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void spawnplayer();
	void getplayercontrollers();
	void getdistancebetweenplayers();
	void getplayercharacter();
};
