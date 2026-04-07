// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Widget/VirgoUserWidget.h"
#include "VirgoHUD.generated.h"

/**
 * 
 */
UCLASS()
class GASTEMPLATE_API AVirgoHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TObjectPtr<UVirgoUserWidget> OverlayWidget;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UVirgoUserWidget> OverlayWidgetClass;
};
