// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NativeGameplayTags.h"
#include "GameplayTagContainer.h"

#include "DataTypes/VirgoEnumTypes.h"
#include "GAS_FunctionLibrary.generated.h"

class UPawnCombatComponent;
class UAbilitySystemComponent;
class UVirgoAbilitySystemComponent;
class AVirgoCharacterBase;

/**
 * 
 */
UCLASS()
class GASTEMPLATE_API UGAS_FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static UPawnCombatComponent* NativeGetCombatComponentFromActor(AActor* InActor);

	static UVirgoAbilitySystemComponent* NativeGetVirgoASCFromActor(AActor* InActor);

	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Virgo|Combat", meta = (DisplayName = "Get pawn combat component", ExpandEnumAsExecs = "ValidType"))
	static UPawnCombatComponent* BP_GetCombatComponentFromActor(AActor* InActor, EVirgoValidType& ValidType);

	UFUNCTION(BlueprintCallable, Category = "Virgo|Ability")
	static void TryActiveAbilityByEventTag(UAbilitySystemComponent* ASC, const FGameplayTag& EventTag);

	UFUNCTION(BlueprintCallable, Category = "Virgo|MontionWarping")
	static void SetFacingTarget(AVirgoCharacterBase* Character, const FName& TargetName, const FVector& FacingLocation);
};
