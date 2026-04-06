// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VirgoWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class GASTEMPLATE_API UVirgoWidgetController : public UObject
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerController> VirgoController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerState> VirgoPlayerState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> VirgoASC;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAttributeSet> VirgoAttributeSet;
};
