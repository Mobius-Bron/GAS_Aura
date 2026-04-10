// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/VirgoAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "VirgoGameplayTag.h"
#include "GAS_FunctionLibrary.h"

UVirgoAttributeSet::UVirgoAttributeSet()
{
	InitMaxHealth(100.0f);
	InitCurrentHealth(50.0f);
	InitMaxMana(100.0f);
	InitCurrentMana(50.0f);
	InitAttackPower(1.0f);
	InitDefensePower(1.0f);
}

void UVirgoAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UVirgoAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVirgoAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVirgoAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVirgoAttributeSet, CurrentMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVirgoAttributeSet, AttackPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVirgoAttributeSet, DefensePower, COND_None, REPNOTIFY_Always);
}

void UVirgoAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.0f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);
	}
	if (Data.EvaluatedData.Attribute == GetCurrentManaAttribute())
	{
		const float NewCurrentMana = FMath::Clamp(GetCurrentMana(), 0.0f, GetMaxMana());

		SetCurrentHealth(NewCurrentMana);
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.0f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		UE_LOG(LogTemp, Warning, TEXT("Health: %f"), NewCurrentHealth);

		// 触发通知
		// 死亡
		if (NewCurrentHealth <= 0.0f)
		{
			UGAS_FunctionLibrary::AddGameplayTagToActorIfNone(
				Data.Target.GetAvatarActor(), 
				VirgoGameplayTags::Shared_Status_Dead
			);
		}
		// 血量变化
	}
}

void UVirgoAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVirgoAttributeSet, MaxHealth, OldValue);
}

void UVirgoAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVirgoAttributeSet, CurrentHealth, OldValue);
}

void UVirgoAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVirgoAttributeSet, MaxMana, OldValue);
}

void UVirgoAttributeSet::OnRep_CurrentMana(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVirgoAttributeSet, CurrentMana, OldValue);
}

void UVirgoAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVirgoAttributeSet, AttackPower, OldValue);
}

void UVirgoAttributeSet::OnRep_DefensePower(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVirgoAttributeSet, DefensePower, OldValue);
}
