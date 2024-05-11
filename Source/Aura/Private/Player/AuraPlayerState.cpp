// Copyright Avidel


#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Character/AuraHeroComponent.h"
#include "Net/UnrealNetwork.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystem = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AuraAbilitySystem");
	AbilitySystem->SetIsReplicated(true);
	AbilitySystem->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("Attribute Set");
	NetUpdateFrequency = 100.f;

	HeroComponent = CreateDefaultSubobject<UAuraHeroComponent>("HeroComponent");
	AbilitySystem->SetIsReplicated(true);
}

void AAuraPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAuraPlayerState, Level);
}

void AAuraPlayerState::OnRep_Level(int32 OldLevel)
{
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}

int32 AAuraPlayerState::GetPlayerLevel() const
{
	return Level;
}

UAuraHeroComponent* AAuraPlayerState::GetHeroCombatComponent()
{
	return HeroComponent;
}
