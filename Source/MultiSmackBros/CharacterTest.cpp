// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterTest.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"


ACharacterTest::ACharacterTest()
{
	PrimaryActorTick.bCanEverTick = true;



	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	
	
}
