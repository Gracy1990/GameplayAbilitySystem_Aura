// Copyright Maniform Studio


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			// Title
			"<Title>ARCANE SHARDS/>\n\n"

			// Level
			"<small>Level: </><Level>%d</>\n"
			// ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			// Cooldown
			"<small>Cooldown: </><Cooldown>%.1f</>\n\n"

			"<Default>Summon a shard of arcane energy, "
			"causing radial arcane damage of </>"

			// Damage
			"<Damage>%d</><Default> at the shard origin.</>"),

			//Values
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
	else
	{
		return FString::Printf(TEXT(
			// Title
			"<Title>NEXT LEVEL:</>\n\n"

			// Level
			"<small>Level: </><Level>%d</>\n"
			// ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			// Cooldown
			"<small>Cooldown: </><Cooldown>%.1f</>\n\n"

			// Additional Number of Shock Targets
			"<Default>Summon %d shards of arcane energy, causing radial arcane damage of</>"

			// Damage
			"<Damage>%d</><Default> at the shard origin.</>"),

			//Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, MaxNumShards),
			ScaledDamage);
	}
}

FString UArcaneShards::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);

	return FString::Printf(TEXT(
		// Title
		"<Title>ARCANE SHARDS</>\n\n"

		// Level
		"<small>Level: </><Level>%d</>\n"
		// ManaCost
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		// Cooldown
		"<small>Cooldown: </><Cooldown>%.1f</>\n\n"

		// Additional Number of Shock Targets
		"<Default>Summon %d shards of arcane energy, causing radial arcane damage of</>"

		// Damage
		"<Damage>%d</><Default> at the shard origin.</>"),

		//Values
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, MaxNumShards),
		ScaledDamage);
}
