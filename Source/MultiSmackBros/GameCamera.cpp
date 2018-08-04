// Fill out your copyright notice in the Description page of Project Settings.

#include "GameCamera.h"
#include "PlayerControllerBase.h"
#include "MyGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Engine.h"

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


	
	APlayerController* p1 = GetWorld()->GetFirstPlayerController();
	if (p1 != NULL)
	{
		p1->SetViewTarget(this);
	}
	//ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void AGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetWorld()->GetPlayerControllerIterator();
}

void AGameCamera::getplayers()
{
	//UWorld* YourGameWorld = nullptr; // Set this somehow from another UObject or pass it in as an argument or parameter
	//for (TObjectIterator<UYourObject> Itr; Itr; ++Itr)
	//{
	//	// Filter out objects not contained in the target world.
	//	if (Itr->GetWorld() != YourGameWorld)
	//	{
	//		continue;
	//	}
	//	// Do stuff
	//}

	//foreach get player controller
	/*for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{


		playerControllersarray.Add(Iterator);

		APlayerController* controller = *Iterator;
		controller->SetViewTarget(this);
		
	}	
*/
		
		


		/*int i = 0;
		APlayerController* controller = UGameplayStatics::GetPlayerController(this, i);
		controller->SetViewTarget(this);
		++i;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("%i"),i);*/
	

	// need to for each loop set view target
	//TArray<AActor *> controllers;

	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerControllerBase::StaticClass(), controllers);

	//uint8 Len = controllers.Num();
	//for (uint8 i = 0; i < Len; ++i)
	//{
	//	//controllers[i]->GetInstigatorController()->CastToPlayerController();
	//	/*controllers[i]->SetViewTarget(this);*/
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("set +1 view target player"));
	//}
		
}

void AGameCamera::updatecamera()
{
	AMyGameMode* gamemode = (AMyGameMode*)GetWorld()->GetAuthGameMode();

}

