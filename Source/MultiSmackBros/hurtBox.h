// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Engine.h"
#include "hurtBox.generated.h"


UCLASS()
class MULTISMACKBROS_API AhurtBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AhurtBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FTimerHandle ActiveTime;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void GetDestroyed();
	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);
	
};
