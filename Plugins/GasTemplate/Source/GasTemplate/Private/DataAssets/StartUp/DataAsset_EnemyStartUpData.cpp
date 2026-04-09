// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUp/DataAsset_EnemyStartUpData.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UVirgoAbilitySystemComponent* InVASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InVASCToGive, ApplyLevel);

	for (const FVirgoCharacterAbilitySet& EnemyAbilitySet : EnemyStartUpAbilitySets)
	{
		if (!EnemyAbilitySet.IsValid()) { continue; }

		FGameplayAbilitySpec AbilitySpec(EnemyAbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InVASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(EnemyAbilitySet.EventTag);

		InVASCToGive->GiveAbility(AbilitySpec);
	}
}
