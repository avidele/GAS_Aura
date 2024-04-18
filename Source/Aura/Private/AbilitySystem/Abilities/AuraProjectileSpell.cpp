#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "Actor/AuraProjectile.h"
#include "Interaction/CombatInterface.h"
#include "Kismet/KismetSystemLibrary.h"

void UAuraProjectileSpell::ActivateAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo *ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const FGameplayEventData *TriggerEventData) {
  Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}
void UAuraProjectileSpell::SpawnProjectile(
    const FVector &ProjectileTargetLocation) {
  // UKismetSystemLibrary::PrintString(this, "Projectile Spell Activated(C++)",
  // true, false, FLinearColor::Red, 5.0f);
  if (const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
      !bIsServer)
    return;
  if (ICombatInterface *CombatInterface =
          Cast<ICombatInterface>(GetAvatarActorFromActorInfo())) {
    const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
    FTransform SpawnTransform;
    // const FVector TurnDirection = FVector(0.0f, 90.0f, 0.0f);
    SpawnTransform.SetLocation(SocketLocation);
    SpawnTransform.SetRotation(
        (ProjectileTargetLocation - SocketLocation)
            .Rotation()
            .Quaternion());

    AAuraProjectile *Projectile =
        GetWorld()->SpawnActorDeferred<AAuraProjectile>(
            ProjectileClass, SpawnTransform, GetOwningActorFromActorInfo(),
            Cast<APawn>(GetOwningActorFromActorInfo()),
            ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

    // TODO: Give the Projectile a Gameplay Effect Spec for causing Damage.

    Projectile->FinishSpawning(SpawnTransform);
  }
}
