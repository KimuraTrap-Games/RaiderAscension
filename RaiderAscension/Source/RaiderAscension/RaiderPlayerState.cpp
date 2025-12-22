#include "RaiderPlayerState.h"
#include "Net/UnrealNetwork.h"

ARaiderPlayerState::ARaiderPlayerState()
{
    RaiderGrade = ERaiderGrade::Fledgling;
}

void ARaiderPlayerState::BeginPlay()
{
    Super::BeginPlay();
}

void ARaiderPlayerState::AssignRandomRaiderGrade()
{
    int32 RandomIndex = FMath::RandRange(0, 5); // 0–5 for 6 grades
    RaiderGrade = static_cast<ERaiderGrade>(RandomIndex);
}

void ARaiderPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ARaiderPlayerState, RaiderGrade);
}
