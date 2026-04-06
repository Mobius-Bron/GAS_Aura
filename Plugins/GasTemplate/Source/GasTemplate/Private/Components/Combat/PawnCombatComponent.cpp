// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Components/BoxComponent.h"

#include "Character/VirgoCharacterBase.h"

void UPawnCombatComponent::RegisterWeapon(FGameplayTag WeaponTag, AWeaponBase* SpwanWeapon, bool RegisterAsEquippedWeapon)
{
	if (!WeaponTag.IsValid())
	{
		UE_LOG(LogTemp, Display, TEXT("Register WeaponTag is nullptr"));
		return; 
	}
	if (CharacterCarriedWeaponMap.Contains(WeaponTag))
	{
		UE_LOG(LogTemp, Display, TEXT("Register WeaponTag %s is already register"), *WeaponTag.ToString());
		return;
	}

	CharacterCarriedWeaponMap.Emplace(WeaponTag, SpwanWeapon);

	SpwanWeapon->OnWeaponHitTarget.BindUObject(this, &ThisClass::OnHitTargetActor);
	SpwanWeapon->OnWeaponPulledFromTarget.BindUObject(this, &ThisClass::OnPulledFromTargetActor);

	if (RegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = WeaponTag;
	}
}

void UPawnCombatComponent::UnregisterWeapon(FGameplayTag WeaponTag)
{
	if (AWeaponBase* WeaponToDestroy = GetCharacterCarriedWeaponByTag(WeaponTag))
	{
		CharacterCarriedWeaponMap.Remove(WeaponTag);

		WeaponToDestroy->OnWeaponHitTarget.Unbind();
		WeaponToDestroy->OnWeaponPulledFromTarget.Unbind();

		if (CurrentEquippedWeaponTag == WeaponTag)
		{
			CurrentEquippedWeaponTag = FGameplayTag();
		}
	}
}

void UPawnCombatComponent::SpawnAndRegisterWeapon(FGameplayTag WeaponTag, TSubclassOf<AWeaponBase> WeaponClass, FName SpawnAttachName, bool RegisterAsEquippedWeapon)
{
	AVirgoCharacterBase* Character = Cast<AVirgoCharacterBase>(GetOwner());

	if (!Character) { return; }

	// 生成武器
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = Character;
	SpawnParams.Instigator = Character;

	AWeaponBase* SpawnedWeapon = GetWorld()->SpawnActor<AWeaponBase>(
		WeaponClass,
		FVector::ZeroVector,
		FRotator::ZeroRotator,
		SpawnParams
	);

	if (!SpawnedWeapon)
	{
		UE_LOG(LogTemp, Error, TEXT("SpawnAndRegisterWeapon: Failed to spawn weapon of class %s"), *WeaponClass->GetName());
		return;
	}

	// 绑定到指定插槽
	if (!SpawnAttachName.IsNone())
	{
		SpawnedWeapon->AttachToComponent(
			Character->GetMesh(),
			FAttachmentTransformRules::SnapToTargetIncludingScale,
			SpawnAttachName
		);
	}
	RegisterWeapon(WeaponTag, SpawnedWeapon, RegisterAsEquippedWeapon);
}

void UPawnCombatComponent::UnregisterAndDestoryWeapon(FGameplayTag WeaponTag)
{
	if (AWeaponBase* WeaponToDestroy = GetCharacterCarriedWeaponByTag(WeaponTag))
	{
		CharacterCarriedWeaponMap.Remove(WeaponTag);

		WeaponToDestroy->OnWeaponHitTarget.Unbind();
		WeaponToDestroy->OnWeaponPulledFromTarget.Unbind();

		if (CurrentEquippedWeaponTag == WeaponTag)
		{
			CurrentEquippedWeaponTag = FGameplayTag();
		}

		WeaponToDestroy->Destroy();
	}
}

AWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag WeaponTag) const
{
	if (!WeaponTag.IsValid()) 
	{
		UE_LOG(LogTemp, Display, TEXT("Get WeaponTag is nullptr"));
		return nullptr; 
	}
	if (!CharacterCarriedWeaponMap.Contains(WeaponTag)) 
	{ 
		UE_LOG(LogTemp, Display, TEXT("Get WeaponTag %s Cant' Found"), *WeaponTag.ToString());
		return nullptr; 
	}

	if (AWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(WeaponTag))
	{
		return *FoundWeapon;
	}

	return nullptr;
}

AWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

void UPawnCombatComponent::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType DamageType)
{
	if (DamageType == EToggleDamageType::CurrentEquippedWeapon)
	{
		AWeaponBase* WeaponToToggle = GetCharacterCurrentEquippedWeapon();

		if (!WeaponToToggle) { return; }

		if (bShouldEnable)
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		}
		else
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			OverlappedActors.Empty();
		}
	}
}

void UPawnCombatComponent::OnHitTargetActor(AActor* TargetActor)
{

}

void UPawnCombatComponent::OnPulledFromTargetActor(AActor* TargetActor)
{

}
