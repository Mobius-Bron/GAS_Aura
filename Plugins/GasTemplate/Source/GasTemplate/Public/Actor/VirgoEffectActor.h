// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VirgoEffectActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class GASTEMPLATE_API AVirgoEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AVirgoEffectActor();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> ActorMesh;

};
