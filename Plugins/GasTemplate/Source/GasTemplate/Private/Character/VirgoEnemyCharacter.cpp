// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/VirgoEnemyCharacter.h"
#include "Engine/AssetManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

#include "AbilitySystem/VirgoAbilitySystemComponent.h"
#include "AbilitySystem/VirgoAttributeSet.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "DataAssets/StartUp/DataAsset_StartUpDataBase.h"
#include "DataAssets/StartUp/DataAsset_EnemyStartUpData.h"
#include "AI/VirgoAIController.h"

AVirgoEnemyCharacter::AVirgoEnemyCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 300.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;

	VirgoAbilitySystemComponent = CreateDefaultSubobject<UVirgoAbilitySystemComponent>(TEXT("VirgoAbilitySystemComponent"));

	VirgoAttributeSet = CreateDefaultSubobject<UVirgoAttributeSet>(TEXT("VirgoAttributeSet"));

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("EnemyCombatComponent"));

	// AI
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("BehaviorTreeComponent");

	VirgoAIController = CreateDefaultSubobject<AVirgoAIController>("VirgoAIController");
}

UAbilitySystemComponent* AVirgoEnemyCharacter::GetAbilitySystemComponent() const
{
	return GetVirgoAbilitySystemComponent();
}

UPawnCombatComponent* AVirgoEnemyCharacter::GetCombatComponent() const
{
	return GetEnemyCombatComponent();
}

void AVirgoEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	VirgoAbilitySystemComponent->InitAbilityActorInfo(this, this);
	InitEnemyStartUpData();
}

void AVirgoEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	VirgoAIController = Cast<AVirgoAIController>(NewController);
}

void AVirgoEnemyCharacter::InitEnemyStartUpData()
{
	if (EnemyStartUpConfig.IsNull()) { return; }

	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		EnemyStartUpConfig.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if (UDataAsset_StartUpDataBase* LoadedData = EnemyStartUpConfig.Get())
				{
					LoadedData->GiveToAbilitySystemComponent(VirgoAbilitySystemComponent);
				}
			}
		)
	);
}
