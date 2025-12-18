#include "RaiderPlayerState.h"
#include "Net/UnrealNetwork.h"

ARaiderPlayerState::ARaiderPlayerState()
{
    bReplicates = true;
}

void ARaiderPlayerState::BeginPlay()
{
    Super::BeginPlay();

    if (HasAuthority())
    {
        AssignRandomRaiderGrade();
    }
}

void ARaiderPlayerState::AssignRandomRaiderGrade()
{
    const int32 RandomIndex = FMath::RandRange(0, static_cast<int32>(ERaiderGrade::Mythic));
    RaiderGrade = static_cast<ERaiderGrade>(RandomIndex);
}

void ARaiderPlayerState::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty>& OutLifetimeProps
) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ARaiderPlayerState, RaiderGrade);
}
