#include "RaiderCharacter.h"
#include "Components/TextRenderComponent.h"

ARaiderCharacter::ARaiderCharacter()
{
    // Create the TextRenderComponent
    RaiderGradeText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("RaiderGradeText"));
    RaiderGradeText->SetupAttachment(RootComponent);
    RaiderGradeText->SetRelativeLocation(FVector(0.f, 0.f, 100.f)); // Above head
    RaiderGradeText->SetHorizontalAlignment(EHTA_Center);
    RaiderGradeText->SetText(FText::FromString("Loading..."));
}

void ARaiderCharacter::BeginPlay()
{
    Super::BeginPlay();
}
