// Copyright Maniform Studio

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "AuraAbilitySystemLibrary.h"
#include "AuraAbilitySystemComponent.generated.h"



// Delegate taking a reference to a FGameplayTagContainer (AssetTags)
DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, FGameplayTagContainer&);
DECLARE_MULTICAST_DELEGATE_OneParam(FAbilitiesGiven, UAuraAbilitySystemComponent*);

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
	FAbilitiesGiven AbilitiesGivenDelegate;

	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);
	bool bStartupAbilitiesGiven = false;

	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

protected:

	UFUNCTION(Client, Reliable)
	void ClientEffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);

};
