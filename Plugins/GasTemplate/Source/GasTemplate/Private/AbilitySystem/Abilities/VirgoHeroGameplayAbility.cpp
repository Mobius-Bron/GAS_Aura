// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/VirgoHeroGameplayAbility.h"

#include "VirgoGameplayTag.h"
#include "Character/VirgoHeroCharacter.h"
#include "Controller/VirgoController.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "AbilitySystem/VirgoAbilitySystemComponent.h"

AVirgoHeroCharacter* UVirgoHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedVirgoHeroCharacter.IsValid())
	{
		CachedVirgoHeroCharacter = Cast<AVirgoHeroCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedVirgoHeroCharacter.IsValid() ? CachedVirgoHeroCharacter.Get() : nullptr;
}

AVirgoController* UVirgoHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedVirgoController.IsValid())
	{
		CachedVirgoController = Cast<AVirgoController>(CurrentActorInfo->PlayerController);
	}

	return CachedVirgoController.IsValid() ? CachedVirgoController.Get() : nullptr;
}

UHeroCombatComponent* UVirgoHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
