// Copyright Avidel

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class UAuraHeroComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
public:

	
	AAuraCharacter();
	UFUNCTION()
	UAuraHeroComponent* GetCombatComponent() const;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UStaticMeshComponent> L_Weapon;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UStaticMeshComponent> R_Weapon;

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface */
private:
	virtual void InitAbilityActorInfo() override;

protected:
	virtual void InitializeDefaultAttributes() const override;
};
