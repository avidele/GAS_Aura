// Copyright Avidel

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnenmy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnenmy();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

};
