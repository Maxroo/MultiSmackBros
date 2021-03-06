// Fill out your copyright notice in the Description page of Project Settings.

#include "GameCamera.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Engine.h"

// Sets default values
AGameCamera::AGameCamera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	SpringArmlength = 300.f;
	//PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(0.0f, 0.0f, 0.0f));
	OurCameraSpringArm->TargetArmLength = SpringArmlength;
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
	defaultpos = GetActorLocation();
}

// Called every frame
void AGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APlayerController* p1 = GetWorld()->GetFirstPlayerController();
	APlayerController* p2 = UGameplayStatics::GetPlayerController(GetWorld(), 1);
	
	setcamera();
	CameraPos = ((updatecamera(p1->GetPawn()) + updatecamera(p2->GetPawn()))) / 2;

	SpringArmlength += updatespringarm(p1->GetPawn(), p2->GetPawn());


	/*GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, p1->GetPawn()->GetActorLocation().ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, updatecamera(p1->GetPawn()).ToString());*/

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

FVector AGameCamera::updatecamera(APawn *playerCharacter)
{
	FVector Location;

	if (playerCharacter)
	{
		Location = playerCharacter->GetActorLocation();

	}
	else
	{
		Location.Set(0.0f, 0.0f, 0.0f);
	}
	
	
	return Location;
}

float AGameCamera::updatespringarm(APawn *PCA, APawn *PCB)
{
	float distance;
	if (PCA && PCB)
	{
		distance = PCA->GetDistanceTo(PCB);
	}
	else
	{
		distance = 0.0f;
	}

	return distance;
}

void AGameCamera::setcamera()
{

	SetActorLocation(FMath::VInterpTo(FVector(GetActorLocation().X,defaultpos.Y,defaultpos.Z), FVector(GetActorLocation().X,CameraPos.Y, CameraPos.Z), FApp::GetDeltaTime(),20.0f));
	
	FMath::Clamp(SpringArmlength, 300.f, 500.f);

	defaultpos = GetActorLocation();
}
