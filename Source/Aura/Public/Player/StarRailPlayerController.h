// Copyright Avidel

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StarRailPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AStarRailPlayerController : public APlayerController
{
	GENERATED_BODY()
	public:
	virtual void BeginPlay() override;
};
