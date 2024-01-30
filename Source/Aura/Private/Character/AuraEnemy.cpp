// Copyright Avidel


#include "Character/AuraEnemy.h"
#include "Aura/Aura.h"

AAuraEnenmy::AAuraEnenmy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);
}

void AAuraEnenmy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnenmy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
