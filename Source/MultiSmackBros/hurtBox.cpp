// Fill out your copyright notice in the Description page of Project Settings.

#include "hurtBox.h"


// Sets default values
AhurtBox::AhurtBox()
{


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UBoxComponent *hurtArea;
	hurtArea = CreateDefaultSubobject<UBoxComponent>(TEXT("HBox"));
	hurtArea->SetBoxExtent(FVector(30.0f, 30.0f, 30.0f));
	hurtArea->SetHiddenInGame(false);
	hurtArea->SetVisibility(true);

}

// Called when the game starts or when spawned
void AhurtBox::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Spawned"));
	GetWorldTimerManager().SetTimer(ActiveTime, this, &AhurtBox::GetDestroyed, 0.5f, false);
	
}

// Called every frame
void AhurtBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AhurtBox::GetDestroyed() 
{
	this->Destroy();
}

