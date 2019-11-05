// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
	Ready			UMETA(DisplayName = "Ready"),
	NetworkError	UMETA(DisplayName = "NetworkError"),
	StartGame		UMETA(DisplayName = "StartGame"),
};

/**
 * 
 */
UCLASS()
class OCTOPROTOTYPE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameState CurrentState;

	UFUNCTION(BlueprintCallable)
	FString GetMyIpAddress();
};
