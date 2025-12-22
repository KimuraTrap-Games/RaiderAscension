#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/TextRenderComponent.h"
#include "InputActionValue.h"  
#include "RaiderCharacter.generated.h"

UCLASS()
class RAIDERASCENSION_API ARaiderCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ARaiderCharacter();

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Movement functions
    void Move(const FInputActionValue& Value);

    void Look(const FInputActionValue& Value);

public:
    // Text to display the RaiderGrade
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    class UTextRenderComponent* RaiderGradeText;

    // Enhanced Input
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputMappingContext* PlayerMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* LookAction;
};
