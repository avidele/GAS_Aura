// Copyright Avidel

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "EEC_DamageExecCalculation.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UEEC_DamageExecCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public:
	UEEC_DamageExecCalculation();
	
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
