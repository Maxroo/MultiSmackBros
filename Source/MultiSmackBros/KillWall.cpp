// Fill out your copyright notice in the Description page of Project Settings.

#include "KillWall.h"
#include "Components/BoxComponent.h"
#include "CharacterBase.h"

// Sets default values
AKillWall::AKillWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UBoxComponent *BoxArea;
	BoxArea = CreateDefaultSubobject<UBoxComponent>(TEXT("KBox"));
	BoxArea->SetBoxExtent(FVector(1000, 100, 10));
	BoxArea->bGenerateOverlapEvents = true;
	BoxArea->OnComponentBeginOverlap.AddDynamic(this, &AKillWall::BeginOverlap);

}

// Called when the game starts or when spawned
void AKillWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKillWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKillWall::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult) 
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Called"));
	if(Cast<ACharacterBase>(OtherActor) != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dead"));
		Cast<ACharacterBase>(OtherActor)->Death();
	}
	

}

