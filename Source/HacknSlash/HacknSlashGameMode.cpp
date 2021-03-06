// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "HacknSlashGameMode.h"
#include "HacknSlashCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHacknSlashGameMode::AHacknSlashGameMode()
{
	
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Blueprint/BaseCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
