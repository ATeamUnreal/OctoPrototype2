// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class OCTOPROTOTYPE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	FString GetMyIpAddress();

	void HandleNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString);	

	UFUNCTION(BlueprintCallable)
	void ClientTravel(FString path);
};
