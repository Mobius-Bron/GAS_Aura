// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/VirgoHUD.h"

void AVirgoHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
