// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/VirgoUserWidget.h"

void UVirgoUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSetUp();
}

UObject* UVirgoUserWidget::GetWidgetController()
{
	return WidgetController;
}
