// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/VirgoPlayerState.h"

#include "AbilitySystem/VirgoAbilitySystemComponent.h"
#include "AbilitySystem/VirgoAttributeSet.h"

AVirgoPlayerState::AVirgoPlayerState()
{
	SetReplicates(true);
	SetMinNetUpdateFrequency(120.f);

	VirgoAbilitySystemComponent = CreateDefaultSubobject<UVirgoAbilitySystemComponent>(TEXT("VirgoAbilitySystemComponent"));

	VirgoAttributeSet = CreateDefaultSubobject<UVirgoAttributeSet>(TEXT("VirgoAttributeSet"));
}
