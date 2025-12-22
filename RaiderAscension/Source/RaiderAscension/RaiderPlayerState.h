#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "RaiderPlayerState.generated.h"

UENUM(BlueprintType)
enum class ERaiderGrade : uint8
{
    Fledgling UMETA(DisplayName = "Fledgling"),
    Bronze    UMETA(DisplayName = "Bronze"),
    Silver    UMETA(DisplayName = "Silver"),
    Gold      UMETA(DisplayName = "Gold"),
    Platinum  UMETA(DisplayName = "Platinum"),
    Mythic    UMETA(DisplayName = "Mythic")
};

UCLASS()
class RAIDERASCENSION_API ARaiderPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    ARaiderPlayerState();

    UPROPERTY(BlueprintReadOnly, Replicated, Category = "Raider")
    ERaiderGrade RaiderGrade;

    UFUNCTION(BlueprintCallable, Category = "Raider")
    void AssignRandomRaiderGrade();

protected:
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
