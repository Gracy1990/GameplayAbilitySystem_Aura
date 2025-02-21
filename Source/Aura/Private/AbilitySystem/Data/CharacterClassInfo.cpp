// Copyright Maniform Studio


#include "AbilitySystem/Data/CharacterClassInfo.h"

FCharacterClassDefaultInfo UCharacterClassInfo::GetClassDefaultInfo(ECharacterClass CharacterClass)
{
    return CharacterClassInformation.FindChecked(CharacterClass);
}
