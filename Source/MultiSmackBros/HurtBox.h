// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HurtBox.generated.h"

UCLASS()
class MULTISMACKBROS_API AHurtBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHurtBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UBoxComponent *hurtArea;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
