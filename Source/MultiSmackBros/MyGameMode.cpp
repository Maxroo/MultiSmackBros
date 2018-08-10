// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameMode.h"
#include "PlayerControllerBase.h"
#include "CharacterBase.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"


AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = ACharacterBase::StaticClass();
}


void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
	spawnplayer();

}

void AMyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%f"),GetNumPlayers()));
}
void AMyGameMode::spawnplayer()
{
	UGameplayStatics::CreatePlayer(this, -1, true);
	//for (TActorIterator<AGameCamera> actor(GetWorld()); actor; ++actor)
	//{
	//	actor->getplayers();
	//}

}

void AMyGameMode::getplayercontrollers()
{
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		//Iterator.GetIndex();
		//APlayerControllerBase* controller; 
		//*Iterator->Get();
		/*APlayerController* controller = *Iterator;*/
		//playerControllersArray->Add(Iterator->Get());

	}

	for (TActorIterator<APlayerControllerBase> controller(GetWorld()); controller; ++controller)
	{
		//playerControllersArray.Add(controller);
	}

}

void AMyGameMode::getdistancebetweenplayers()
{

	//Distancebetweenallplayer.Add(P1->GetPawn()->GetDistanceTo(P2->GetPawn()));
	//Distancebetweenallplayer.Add(P1->GetPawn()->GetDistanceTo(P3->GetPawn()));
	//Distancebetweenallplayer.Add(P1->GetPawn()->GetDistanceTo(P4->GetPawn()));
	//Distancebetweenallplayer.Add(P2->GetPawn()->GetDistanceTo(P1->GetPawn()));
	//Distancebetweenallplayer.Add(P2->GetPawn()->GetDistanceTo(P3->GetPawn()));
	//Distancebetweenallplayer.Add(P2->GetPawn()->GetDistanceTo(P4->GetPawn()));
	//Distancebetweenallplayer.Add(P3->GetPawn()->GetDistanceTo(P1->GetPawn()));
	//Distancebetweenallplayer.Add(P3->GetPawn()->GetDistanceTo(P2->GetPawn()));
	//Distancebetweenallplayer.Add(P3->GetPawn()->GetDistanceTo(P4->GetPawn()));
	//Distancebetweenallplayer.Add(P4->GetPawn()->GetDistanceTo(P1->GetPawn()));
	//Distancebetweenallplayer.Add(P4->GetPawn()->GetDistanceTo(P2->GetPawn()));
	//Distancebetweenallplayer.Add(P4->GetPawn()->GetDistanceTo(P3->GetPawn()));

}

void AMyGameMode::getplayercharacter()
{
	if (P1->GetPawn())
	{
		PC1 = P1->GetPawn();
	}

	if (P2->GetPawn())
	{
		PC2 = P2->GetPawn();
	}

	if (P3->GetPawn())
	{
		PC3 = P3->GetPawn();
	}

	if (P4->GetPawn())
	{
		PC4 = P4->GetPawn();
	}
}