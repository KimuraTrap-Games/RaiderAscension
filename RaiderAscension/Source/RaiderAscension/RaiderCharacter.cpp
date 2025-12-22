#include "RaiderCharacter.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "RaiderPlayerState.h"
#include "GameFramework/PlayerState.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

ARaiderCharacter::ARaiderCharacter()
{
    // Create the TextRenderComponent
    RaiderGradeText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("RaiderGradeText"));
    RaiderGradeText->SetupAttachment(RootComponent);
    RaiderGradeText->SetRelativeLocation(FVector(0.f, 0.f, 100.f));
    RaiderGradeText->SetHorizontalAlignment(EHTA_Center);
    RaiderGradeText->SetText(FText::FromString("Loading..."));

    // Set size for collision capsule
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

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

    // Update floating text and debug
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

            if (RaiderGradeText)
            {
                RaiderGradeText->SetText(FText::FromString(GradeString));
            }

            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red,
                    FString::Printf(TEXT("%s's Grade: %s"), *GetName(), *GradeString));
            }
        }
    }

    // Add Enhanced Input Mapping
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            if (PlayerMappingContext)
            {
                Subsystem->AddMappingContext(PlayerMappingContext, 0);
            }
        }
    }
}

void ARaiderCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        if (MoveAction)
            EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARaiderCharacter::Move);

        if (LookAction)
            EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARaiderCharacter::Look);
    }
}

void ARaiderCharacter::Move(const FInputActionValue& Value)
{
    FVector2D MovementVector = Value.Get<FVector2D>();
    if (Controller != nullptr)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

        const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

        AddMovementInput(ForwardDirection, MovementVector.Y);
        AddMovementInput(RightDirection, MovementVector.X);
    }
}

void ARaiderCharacter::Look(const FInputActionValue& Value)
{
    FVector2D LookVector = Value.Get<FVector2D>();
    AddControllerYawInput(LookVector.X);
    AddControllerPitchInput(LookVector.Y);
}
