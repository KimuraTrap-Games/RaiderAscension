#include "RaiderGameMode.h"
#include "GameFramework/PlayerController.h"

ARaiderGameMode::ARaiderGameMode()
{
    // Set the PlayerState class to your custom class
    PlayerStateClass = ARaiderPlayerState::StaticClass();
}

void ARaiderGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    if (NewPlayer)
    {
        ARaiderPlayerState* RPS = Cast<ARaiderPlayerState>(NewPlayer->GetPlayerState());
        if (RPS)
        {
            RPS->AssignRandomGrade(); // Make sure this function exists in RaiderPlayerState
        }
    }
}
