// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/LyraPlayerState.h"
#include "RaiderPlayerState.generated.h"

UENUM()
enum class ERaiderGrade : uint8
{
	E UMETA(DisplayName = "E");
	D UMETA(DisplayName = "D");
	C UMETA(DisplayName = "C");
	B UMETA(DisplayName = "B");
	A UMETA(DisplayName = "A");
	S UMETA(DisplayName = "S");
};


UCLASS()
class ASYNCMIXIN_API ARaiderPlayerState : public ALyraPlayerState
{
	GENERATED_BODY()

public:
	ARaiderPlayerState();

protected:
	// Grade of the Raider
	UPROPERTY(ReplicatedUsing = OnRep_RaiderGrade, BlueprintReadOnly, Category="Raider")
	ERaiderGrade RaiderGrade;

	// Called when RaiderGrade is changed
	UFUNCTION()
	void OnRep_RaiderGrade();

	// Required for replication
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UFUNCTION(BlueprintCallable, Category = "Raider")
	ERaiderGrade GetRaiderGrade() const { return RaiderGrade; }

	void AssignRandomRaiderGrade();
};
