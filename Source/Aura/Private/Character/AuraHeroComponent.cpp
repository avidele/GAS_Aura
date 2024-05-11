// Copyright Avidel


#include "Character/AuraHeroComponent.h"

#include "GameFramework/Character.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"

void UAuraHeroComponent::Attack()
{
	const auto PlayerState = Cast<AAuraPlayerState>(GetOwner());
	const auto OwnerPawn = Cast<AAuraPlayerController>(PlayerState->GetOwner())->GetPawn();
	const auto OwnerCharacter = Cast<ACharacter>(OwnerPawn);
	if (!AttackMontage || !OwnerCharacter) return;
	if (CurrentState != ECombat_State::Attack)
	{
		ChangeCombatState(ECombat_State::Attack);
		bWantContinueAttack = false;
		CurrentAttackMontageSection = 0;
		OwnerCharacter->PlayAnimMontage(AttackMontage, 1, AttackMontage->GetSectionName(CurrentAttackMontageSection));
		
	}
	else if (CurrentState == ECombat_State::Attack && CurrentAttackMontageSection < AttackMontage->GetNumSections() - 1)
	{
		bWantContinueAttack = true;
	}
}

bool UAuraHeroComponent::ChangeCombatState(F_Combat_State NextState)
{
	CurrentState = NextState;
	return true;
}

void UAuraHeroComponent::AttackEnd()
{
	const auto PlayerState = Cast<AAuraPlayerState>(GetOwner());
	const auto OwnerPawn = Cast<AAuraPlayerController>(PlayerState->GetOwner())->GetPawn();
	if (const auto OwnerCharacter = Cast<ACharacter>(OwnerPawn); OwnerCharacter && bWantContinueAttack)
	{
		bWantContinueAttack = false;
		if (CurrentAttackMontageSection == AttackMontage->GetNumSections() - 1)
		{
			ChangeCombatState(ECombat_State::Idle);
			CurrentAttackMontageSection = 0;
			return;
		}
		CurrentAttackMontageSection += 1;
		FString Msg = FString::Printf(
		TEXT("Section: %s"), *(AttackMontage->GetSectionName(CurrentAttackMontageSection).ToString()));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, Msg
		);
		OwnerCharacter->PlayAnimMontage(AttackMontage, 1.f, AttackMontage->GetSectionName(CurrentAttackMontageSection));
	}
	else if (!bWantContinueAttack)
	{
		ChangeCombatState(ECombat_State::Idle);
	}
}
