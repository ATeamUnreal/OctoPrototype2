// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MainGS.generated.h"

UENUM(BlueprintType)
enum class EMainGameState : uint8
{
	Initialize		UMETA(DisplayName = "Initialize"),
	Playing			UMETA(DisplayName = "Playing"),
	GameOver		UMETA(DisplayName = "GameOver"),
	Loading			UMETA(DisplayName = "Loading")
};

/**
 * 
 */
UCLASS()
class OCTOPROTOTYPE_API AMainGS : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_CurrentGameState")
	EMainGameState CurrentGameState;
	

	UFUNCTION(BlueprintCallable)
	void OnRep_CurrentGameState();


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DoWhenCurrentGameStateChanged();
	void DoWhenCurrentGameStateChanged_Implementation();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
