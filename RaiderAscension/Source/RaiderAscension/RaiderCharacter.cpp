#include "RaiderCharacter.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "RaiderPlayerState.h"
#include "GameFramework/PlayerState.h"

ARaiderCharacter::ARaiderCharacter()
{
    // Create the TextRenderComponent
    RaiderGradeText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("RaiderGradeText"));
    RaiderGradeText->SetupAttachment(RootComponent);
    RaiderGradeText->SetRelativeLocation(FVector(0.f, 0.f, 100.f)); // Above head
    RaiderGradeText->SetHorizontalAlignment(EHTA_Center);
    RaiderGradeText->SetText(FText::FromString("Loading..."));

    // Set size for collision capsule
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

    // Basic movement settings
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);

    // Replicate this character
    bReplicates = true;
    SetReplicateMovement(true);
}

void ARaiderCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerState* PS = GetPlayerState())
    {
        if (ARaiderPlayerState* RPS = Cast<ARaiderPlayerState>(PS))
        {
            FString GradeString;
            switch (RPS->RaiderGrade)
            {
            case ERaiderGrade::Fledgling: GradeString = "Fledgling"; break;
            case ERaiderGrade::Bronze:    GradeString = "Bronze"; break;
            case ERaiderGrade::Silver:    GradeString = "Silver"; break;
            case ERaiderGrade::Gold:      GradeString = "Gold"; break;
            case ERaiderGrade::Platinum:  GradeString = "Platinum"; break;
            case ERaiderGrade::Mythic:    GradeString = "Mythic"; break;
            default: GradeString = "Unknown"; break;
            }

            RaiderGradeText->SetText(FText::FromString(GradeString));
        }
    }
}
