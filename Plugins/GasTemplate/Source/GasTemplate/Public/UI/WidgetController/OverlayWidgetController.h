// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/VirgoWidgetController.h"

#include "AbilitySystem/VirgoAttributeSet.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentHealthChangedSignature, float, CurrentHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, MaxMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrenttManaChangedSignature, float, CurrentMana);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GASTEMPLATE_API UOverlayWidgetController : public UVirgoWidgetController
{
	GENERATED_BODY()
	
public:
	virtual void BroadcastInitValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attrbutes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attrbutes")
	FOnCurrentHealthChangedSignature OnCurrentHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attrbutes")
	FOnMaxManaChangedSignature OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attrbutes")
	FOnCurrenttManaChangedSignature OnCurrentManaChanged;

protected:
	void MaxHealthChanged(const FOnAttributeChangeData& Data);
	void CurrentHealthChanged(const FOnAttributeChangeData& Data);
	void MaxManaChanged(const FOnAttributeChangeData& Data);
	void CurrentManaChanged(const FOnAttributeChangeData& Data);
};
