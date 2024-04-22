// Copyright Avidel


#include "Player/StarRailPlayerController.h"

void AStarRailPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
