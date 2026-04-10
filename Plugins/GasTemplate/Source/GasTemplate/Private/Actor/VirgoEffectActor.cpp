// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/VirgoEffectActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AbilitySystemInterface.h"

#include "AbilitySystem/VirgoAbilitySystemComponent.h"
#include "AbilitySystem/VirgoAttributeSet.h"
#include "Character/VirgoHeroCharacter.h"

// Sets default values
AVirgoEffectActor::AVirgoEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SetRootComponent(SphereComponent);

	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorMesh"));
	ActorMesh->SetupAttachment(SphereComponent);
	ActorMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AVirgoEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ActorGameplayEffect == nullptr) { return; }

	if(AVirgoHeroCharacter* VirgoHeroCharacter = Cast<AVirgoHeroCharacter>(OtherActor))
	{
		if (IAbilitySystemInterface* ASInterface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			UGameplayEffect* EffectCDO = ActorGameplayEffect->GetDefaultObject<UGameplayEffect>();
			ASInterface->GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(
				EffectCDO,
				1,
				ASInterface->GetAbilitySystemComponent()->MakeEffectContext()
			);
		}
		Destroy();
	}
}

void AVirgoEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AVirgoEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ThisClass::EndOverlap);
}

