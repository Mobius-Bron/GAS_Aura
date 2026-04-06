// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/VirgoAbilitySystemComponent.h"
#include "VirgoAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GASTEMPLATE_API UVirgoAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UVirgoAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, Category = "Attribute|Health", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UVirgoAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attribute|Health", ReplicatedUsing = OnRep_CurrentHealth)
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UVirgoAttributeSet, CurrentHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attribute|Attack", ReplicatedUsing = OnRep_AttackPower)
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UVirgoAttributeSet, AttackPower);

	UPROPERTY(BlueprintReadOnly, Category = "Attribute|Defense", ReplicatedUsing = OnRep_DefensePower)
	FGameplayAttributeData DefensePower;
	ATTRIBUTE_ACCESSORS(UVirgoAttributeSet, DefensePower);
	
	// Meta Attribute (´«µÝÖµ)
	UPROPERTY(BlueprintReadOnly, Category = "Attribute|Damage")
	FGameplayAttributeData DamageTaken;
	ATTRIBUTE_ACCESSORS(UVirgoAttributeSet, DamageTaken);

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	// Replicate
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CurrentHealth(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_AttackPower(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_DefensePower(const FGameplayAttributeData& OldValue);
};
