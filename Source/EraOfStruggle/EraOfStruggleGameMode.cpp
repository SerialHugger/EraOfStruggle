// Copyright Epic Games, Inc. All Rights Reserved.

#include "EraOfStruggleGameMode.h"
#include "EraOfStruggleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEraOfStruggleGameMode::AEraOfStruggleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
