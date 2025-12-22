#include "RaiderGameMode.h"
#include "GameFramework/PlayerController.h"
#include "RaiderPlayerState.h"
#include "RaiderCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARaiderGameMode::ARaiderGameMode()
{
    // Assign your custom PlayerState
    PlayerStateClass = ARaiderPlayerState::StaticClass();

    // Load the Blueprint class for the Pawn
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/BP_RaiderCharacter.BP_RaiderCharacter_C"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
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
            RPS->AssignRandomRaiderGrade();
        }
    }
}
