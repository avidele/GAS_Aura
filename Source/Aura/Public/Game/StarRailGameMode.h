#pragma once
#include "AuraGameModeBase.h"
#include "StarRailGameMode.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Game))
class AStarRailGameMode : public AAuraGameModeBase {
  GENERATED_BODY()
public:
  void BeginPlay() override;
};
