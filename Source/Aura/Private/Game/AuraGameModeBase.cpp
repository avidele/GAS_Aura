// Copyright Avidel


#include "Game/AuraGameModeBase.h"

void AAuraGameModeBase::TravelToLevel(const FName LevelName) {
  if (UWorld *World = GetWorld()) {
    const FString LevelPath = LevelName.ToString();
    World->ServerTravel(LevelPath);
  }
}