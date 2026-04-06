// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VirgoUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GASTEMPLATE_API UVirgoUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UFUNCTION(BlueprintCallable)
	UObject* GetWidgetController();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSetUp();

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UObject> WidgetController;

};
