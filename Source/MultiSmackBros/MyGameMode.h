// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
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


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void spawnplayer();
};
