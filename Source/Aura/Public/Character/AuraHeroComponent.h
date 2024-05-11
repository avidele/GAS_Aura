// Copyright Avidel

#pragma once

#include "Components/PawnComponent.h"
#include "CoreMinimal.h"
#include "AuraHeroComponent.generated.h"
class AAuraPlayerController;
/**
 *
 */
UENUM()
enum ECombat_State : uint8
{
	Idle = 0,
	Attack = 1,
	Defense = 2,
	B_Hit = 3,
	SP_Attack = 4,
	Dodge = 5,
};

UCLASS(BlueprintType)
class AURA_API UAuraHeroComponent : public UPawnComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,Category = "AttackMontage")
	TObjectPtr<UAnimMontage> AttackMontage;
	
	UFUNCTION(BlueprintCallable,Category = "AttackComponent")
	virtual void Attack();
	
	//Debug line
	UPROPERTY(EditAnywhere,Category="Debug")
	bool bUseDebug = false;

	UPROPERTY(EditAnywhere,Category="AttackPerformance",meta=(EditCondition = "bUseAttackPerformance"))
	bool bUseTrailParticle;

	UPROPERTY(EditAnywhere,Category="AttackPerformance",meta=(EditCondition = "bUseTrailParticle"))
	UParticleSystem* TrailParticle;

public:	
	typedef int32 F_Combat_State;
	F_Combat_State CurrentState ;
	bool ChangeCombatState(F_Combat_State NextState);

	UFUNCTION()
	void AttackEnd();
	
private:
	bool bWantContinueAttack;
	int CurrentAttackMontageSection;
};
