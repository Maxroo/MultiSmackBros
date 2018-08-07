// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyGameMode.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "PlayerControllerBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameCamera.generated.h"

UCLASS()
class MULTISMACKBROS_API AGameCamera : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	AGameCamera();
	AActor* myactor;




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* OurCameraSpringArm;
	UCameraComponent* OurCamera;

	//APlayerController* P1;
	//APlayerController* P2;
	//APlayerController* P3;
	//APlayerController* P4;
	//TArray<APlayerControllerBase> playerControllersarray;

	//UPROPERTY(Category = "AutoPlayerActivation", EditAnywhere)
	//	TEnumAsByte<EAutoReceiveInput::Type> AutoActivateForPlayer;

	float SpringArmlength;
	FVector CameraPos;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void getplayers();
	FVector updatecamera(APawn *playerCharacter);
	float updatespringarm(APawn *PCA, APawn *PCB);

};
