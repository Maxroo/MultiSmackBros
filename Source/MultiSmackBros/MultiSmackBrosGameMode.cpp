// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MultiSmackBrosGameMode.h"
#include "MultiSmackBrosCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiSmackBrosGameMode::AMultiSmackBrosGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
