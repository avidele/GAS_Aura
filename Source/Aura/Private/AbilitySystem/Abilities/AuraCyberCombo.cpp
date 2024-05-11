// Copyright Avidel


#include "AbilitySystem/Abilities/AuraCyberCombo.h"

#include "Character/AuraCharacter.h"
#include "Character/AuraHeroComponent.h"
#include "GameFramework/Character.h"


void UAuraCyberCombo::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	if(const AAuraCharacter* AvatarActor = Cast<AAuraCharacter>(GetAvatarActorFromActorInfo()))
	{
		UAuraHeroComponent* AuraHeroComponent =  AvatarActor->GetCombatComponent();
		AuraHeroComponent->Attack();
	}
}

