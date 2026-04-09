// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/EnemyCombatComponent.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "VirgoGameplayTag.h"
#include "Character/VirgoEnemyCharacter.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* TargetActor)
{
	if (OverlappedActors.Contains(TargetActor)) { return; }
	if (AVirgoEnemyCharacter* Character = Cast<AVirgoEnemyCharacter>(TargetActor)) { return; }

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

void UEnemyCombatComponent::OnPulledFromTargetActor(AActor* TargetActor)
{
}
