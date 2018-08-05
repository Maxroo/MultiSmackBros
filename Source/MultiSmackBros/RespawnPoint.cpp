// Fill out your copyright notice in the Description page of Project Settings.

#include "RespawnPoint.h"
#include "Components/BillboardComponent.h"


// Sets default values
ARespawnPoint::ARespawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UBillboardComponent *ShowWhere;
	ShowWhere = CreateDefaultSubobject<UBillboardComponent>(TEXT("KBox"));

}

// Called when the game starts or when spawned
void ARespawnPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARespawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
