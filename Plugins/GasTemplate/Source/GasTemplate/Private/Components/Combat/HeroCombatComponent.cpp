// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/HeroCombatComponent.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "VirgoGameplayTag.h"
#include "Items/Weapons/VirgoHeroWeapon.h"
#include "Character/VirgoHeroCharacter.h"

AVirgoHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag WeaponTag) const
{
	AWeaponBase* FoundWeapon = GetCharacterCarriedWeaponByTag(WeaponTag);

	AVirgoHeroWeapon* FoundHeroWeapon = Cast<AVirgoHeroWeapon>(FoundWeapon);

	return FoundHeroWeapon;
}

AVirgoHeroWeapon* UHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
	return GetHeroCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

void UHeroCombatComponent::OnHitTargetActor(AActor* TargetActor)
{
	if (OverlappedActors.Contains(TargetActor)) { return; }
	if (AVirgoHeroCharacter* HeroCharacter = Cast<AVirgoHeroCharacter>(TargetActor)) { return; }

	OverlappedActors.AddUnique(TargetActor);

	FGameplayEventData EventData;
	EventData.Instigator = GetOwingPawn();
	EventData.Target = TargetActor;

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwingPawn(),
		VirgoGameplayTags::Shared_Event_MeleeHit,
		EventData
	);

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwingPawn(),
		VirgoGameplayTags::Shared_Event_HitPause,
		FGameplayEventData()
	);
}

void UHeroCombatComponent::OnPulledFromTargetActor(AActor* TargetActor)
{

}
