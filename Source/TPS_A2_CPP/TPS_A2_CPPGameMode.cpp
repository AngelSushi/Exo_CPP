// Copyright Epic Games, Inc. All Rights Reserved.

#include "TPS_A2_CPPGameMode.h"
#include "TPS_A2_CPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATPS_A2_CPPGameMode::ATPS_A2_CPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
