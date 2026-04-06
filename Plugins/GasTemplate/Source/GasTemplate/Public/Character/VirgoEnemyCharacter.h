// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/VirgoCharacterBase.h"
#include "AbilitySystemInterface.h"
#include "VirgoEnemyCharacter.generated.h"

class UBehaviorTreeComponent;

class UEnemyCombatComponent;
class UDataAsset_EnemyStartUpData;
class AVirgoAIController;

/**
 * 
 */
UCLASS()
class GASTEMPLATE_API AVirgoEnemyCharacter :  public AVirgoCharacterBase
{
	GENERATED_BODY()
	
public:
	AVirgoEnemyCharacter();

	/* IAbilitySystemInterface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/* IAbilitySystemInterface */

	/* IPawnCombatInterface */
	virtual UPawnCombatComponent* GetCombatComponent() const override;
	/* IPawnCombatInterface */

	void BeginPlay() override;

	void PossessedBy(AController* NewController) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Virgo|Combat")
	UEnemyCombatComponent* EnemyCombatComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<UDataAsset_EnemyStartUpData> EnemyStartUpConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	TObjectPtr<AVirgoAIController> VirgoAIController;

private:
	void InitEnemyStartUpData();

public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }
};
