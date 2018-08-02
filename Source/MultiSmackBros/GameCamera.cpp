// Fill out your copyright notice in the Description page of Project Settings.

#include "GameCamera.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"

// Sets default values
AGameCamera::AGameCamera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(0.0f, 0.0f, 0.0f));
	OurCameraSpringArm->TargetArmLength = 400.f;
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 3.0f;
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);
	
	
}

// Called when the game starts or when spawned
void AGameCamera::BeginPlay()
{
	Super::BeginPlay();
	//test view blend 
}

// Called every frame
void AGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

