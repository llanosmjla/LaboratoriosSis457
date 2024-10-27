// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProjectWidgetGameMode.h"
#include "MyProjectWidgetCharacter.h"
#include "GamePlayerController.h"
#include "CoinHUD.h"
#include "UObject/ConstructorHelpers.h"

AMyProjectWidgetGameMode::AMyProjectWidgetGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AGamePlayerController::StaticClass();
	HUDClass = ACoinHUD::StaticClass();

}
