// Copyright Maniform Studio

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
public:
	AAuraCharacter();
	void PossessedBy(AController* NewController);
	void OnRep_PlayerState();

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** end Combat Interface */

	virtual void InitAbilityActorInfo() override;
	
};
