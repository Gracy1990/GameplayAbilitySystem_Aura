// Copyright Maniform Studio


#include "AbilitySystem/AuraAbilitySystemGlobals.h"

FGameplayEffectContext* UAuraAbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new FGameplayEffectContext();
}
