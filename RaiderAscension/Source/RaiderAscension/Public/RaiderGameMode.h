#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RaiderPlayerState.h"
#include "RaiderGameMode.generated.h"

UCLASS()
class RAIDERASCENSION_API ARaiderGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ARaiderGameMode();

    virtual void PostLogin(APlayerController* NewPlayer) override;
};
