// Copyright Avidel

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"


class USplineComponent;
class UAuraAbilitySystemComponent;
struct FGameplayTag;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;
class UAuraConfigInput;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	void Look(const FInputActionValue& InputActionValue);

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;
	
	void Move(const FInputActionValue& InputActionValue);
	void CursorTrace();
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;

private:
	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;	
	
	UAuraAbilitySystemComponent* GetASC();
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UAuraConfigInput> InputConfig;
	
	float FollowTime = 0.f;
	bool bTargeting = false;
	bool bAutoRunning = false;
	float ShortPressThreshold = 0.5f;
	FVector CachedDestination = FVector::ZeroVector;

	// UPROPERTY(EditDefaultsOnly)
	// float AutoRunAcceptanceRadius = 5.f;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;

	// void AutoRun();
};

