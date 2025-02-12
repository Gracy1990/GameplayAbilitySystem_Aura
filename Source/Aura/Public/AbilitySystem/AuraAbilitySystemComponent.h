// Copyright Maniform Studio

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "AuraAbilitySystemComponent.generated.h"


// Delegate taking a reference to a FGameplayTagContainer (AssetTags)
DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, FGameplayTagContainer&);

/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet();

	FEffectAssetTags EffectAssetTags;

protected:

	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);

};
