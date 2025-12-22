#include "RaiderGameMode.h"
#include "RaiderPlayerState.h"
#include "GameFramework/PlayerController.h"

ARaiderGameMode::ARaiderGameMode()
{
    PlayerStateClass = ARaiderPlayerState::StaticClass();
}

void ARaiderGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    if (NewPlayer)
    {
        ARaiderPlayerState* RPS = NewPlayer->GetPlayerState<ARaiderPlayerState>();
        if (RPS)
        {
            RPS->AssignRandomRaiderGrade();
        }
    }
}
