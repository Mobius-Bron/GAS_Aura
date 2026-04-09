// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/VirgoWidgetController.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"

void UVirgoWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& InWCParams)
{
	PlayerController = InWCParams.PlayerController;
	PlayerState = InWCParams.PlayerState;
	AbilitySystemComponent = InWCParams.AbilitySystemComponent;
	AttributeSet = InWCParams.AttributeSet;
}
