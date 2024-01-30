// Copyright Avidel

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()
	
public:
	AAuraCharacterBase();

protected:
	virtual void BeginPlay() override;

	//TPointer -> Access Tracking & Lazy Loading
	//USkeletalMeshComponent* Weapon;
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
