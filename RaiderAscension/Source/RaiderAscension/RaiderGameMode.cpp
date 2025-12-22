#include "RaiderGameMode.h"
#include "GameFramework/PlayerController.h"

ARaiderGameMode::ARaiderGameMode()
{
    // Assign your custom classes in the constructor
    PlayerStateClass = ARaiderPlayerState::StaticClass();
    DefaultPawnClass = ARaiderCharacter::StaticClass();
}

void ARaiderGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    if (NewPlayer)
    {
        // Use the template version of GetPlayerState
        ARaiderPlayerState* RPS = Cast<ARaiderPlayerState>(NewPlayer->GetPlayerState<ARaiderPlayerState>());
        if (RPS)
        {
            RPS->AssignRandomRaiderGrade();  // Make sure this exists in your PlayerState
        }
    }
}
