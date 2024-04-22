#pragma once
#include "CoreMinimal.h"
#include "AuraEffectActor.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h"
#include "AuraProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class AURA_API AAuraProjectile : public AAuraEffectActor
{
	GENERATED_BODY()
public:
	AAuraProjectile();

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

	protected:
	virtual void BeginPlay() override;
	
	virtual void OnOverlap(AActor* TargetActor) override;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraComponent> OnHitNiagaraComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> ShootSound;
};
