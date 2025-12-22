#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/TextRenderComponent.h"
#include "RaiderCharacter.generated.h"

UCLASS()
class RAIDERASCENSION_API ARaiderCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ARaiderCharacter();

protected:
    virtual void BeginPlay() override;

public:
    // Text to display the RaiderGrade
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    class UTextRenderComponent* RaiderGradeText;
};
