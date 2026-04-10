// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/VirgoEffectActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AVirgoEffectActor::AVirgoEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorMesh"));
}

void AVirgoEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

