// Copyright Avidel

#pragma once

#include "AuraHeroComponent.generated.h"
#include "Components/PawnComponent.h"
#include "CoreMinimal.h"

class AAuraPlayerController;
/**
 *
 */
UCLASS()
class AURA_API UAuraHeroComponent : public UPawnComponent
{
	GENERATED_BODY()

	
	UPROPERTY()
	AAuraPlayerController* AuraPlayerController;
	
};
