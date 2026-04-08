// Fill out your copyright notice in the Description page of Project Settings.


#include "VirgoGameplayTag.h"

namespace VirgoGameplayTags
{
	/* Input Tags */
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Equip, "InputTag.Equip");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Unequip, "InputTag.Unequip");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Attack, "InputTag.Attack");

	/* Shared Tags */
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Dead, "Shared.Status.Dead");

	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact, "Shared.Ability.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Death, "Shared.Ability.Death");

	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_RangedHit, "Shared.Event.RangedHit");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_SpawnBullet, "Shared.Event.SpawnBullet");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact, "Shared.Event.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitPause, "Shared.Event.HitPause");

	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage, "Shared.SetByCaller.BaseDamage");

	/* Player Tags */
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip, "Player.Ability.Equip");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip, "Player.Ability.Unequip");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_HitPause, "Player.Ability.HitPause");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Sword, "Player.Ability.Attack.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_FireBall, "Player.Ability.Attack.FireBall");

	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Sword, "Player.Weapon.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_AuraStaff, "Player.Weapon.AuraStaff");

	/* Enemy Tags */
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_MeleeAttack, "Enemy.Ability.MeleeAttack");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_RangedAttack, "Enemy.Ability.RangedAttack");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon_Sword, "Enemy.Weapon.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon_ShamanStaff, "Enemy.Weapon.ShamanStaff");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon_Slingshot, "Enemy.Weapon.Slingshot");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon_Spear, "Enemy.Weapon.Spear");
}