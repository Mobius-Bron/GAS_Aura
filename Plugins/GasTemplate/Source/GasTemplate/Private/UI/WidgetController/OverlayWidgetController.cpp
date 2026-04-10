// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

void UOverlayWidgetController::BroadcastInitValues()
{
	Super::BroadcastInitValues();

	const UVirgoAttributeSet* VirgoAttributeSet = Cast<UVirgoAttributeSet>(AttributeSet);

	OnMaxHealthChanged.Broadcast(VirgoAttributeSet->GetMaxHealth());
	OnCurrentHealthChanged.Broadcast(VirgoAttributeSet->GetCurrentHealth());
	OnMaxManaChanged.Broadcast(VirgoAttributeSet->GetMaxMana());
	OnCurrentManaChanged.Broadcast(VirgoAttributeSet->GetCurrentMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	Super::BindCallbacksToDependencies();

	const UVirgoAttributeSet* VirgoAttributeSet = Cast<UVirgoAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		VirgoAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &ThisClass::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		VirgoAttributeSet->GetCurrentHealthAttribute()).AddUObject(this, &ThisClass::CurrentHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		VirgoAttributeSet->GetMaxManaAttribute()).AddUObject(this, &ThisClass::MaxManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		VirgoAttributeSet->GetCurrentManaAttribute()).AddUObject(this, &ThisClass::CurrentManaChanged);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::CurrentHealthChanged(const FOnAttributeChangeData& Data)
{
	OnCurrentHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data)
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::CurrentManaChanged(const FOnAttributeChangeData& Data)
{
	OnCurrentManaChanged.Broadcast(Data.NewValue);
}
