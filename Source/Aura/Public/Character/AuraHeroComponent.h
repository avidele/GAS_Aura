// Copyright Avidel

#pragma once
#include "Components/PawnComponent.h"
#include "CoreMinimal.h"
#include "AuraHeroComponent.generated.h"

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
