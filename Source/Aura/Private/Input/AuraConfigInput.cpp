// Copyright Avidel


#include "Input/AuraConfigInput.h"

const UInputAction* UAuraConfigInput::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
	bool bLogNotFound) const
{
	for (const FAuraInputAction& InputAction : AbilityInputActions)
	{
		if (InputAction.InputTag.MatchesTag(InputTag))
		{
			return InputAction.InputAction;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("InputTag %s not found in %s"), *InputTag.ToString(), *GetName());
	}
	return nullptr;
}
