// Fill out your copyright notice in the Description page of Project Settings.

#include "HurtBox.h"
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"


// Sets default values
AHurtBox::AHurtBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	hurtArea = CreateDefaultSubobject<UBoxComponent>(TEXT("HurtB"));
	//hurtArea->SetBoxExtent()


}

// Called when the game starts or when spawned
void AHurtBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHurtBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

