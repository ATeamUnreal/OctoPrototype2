// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "SocketSubsystem.h"
#include <IPAddress.h>
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void UMyGameInstance::Init()
{
	Super::Init();
	GetEngine()->OnNetworkFailure().AddUObject(this, &UMyGameInstance::HandleNetworkFailure);

}

FString UMyGameInstance::GetMyIpAddress()
{
	FString IpAddr("NONE");
	bool canBind = false;
	TSharedRef<FInternetAddr> LocalIp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, canBind);
	if (LocalIp->IsValid())
	{
		IpAddr = LocalIp->ToString(false);
	}

	return IpAddr;
}

void UMyGameInstance::HandleNetworkFailure(UWorld * World, UNetDriver * NetDriver, ENetworkFailure::Type FailureType, const FString & ErrorString)
{
	UE_LOG(LogClass, Warning, TEXT("ERRRROR String : %s"), *ErrorString);
	//World->NextURL = FString("/Game/Maps/NetworkError");
	
	
	APlayerController* PC = GetFirstLocalPlayerController();
	if (PC && PC->IsValidLowLevel())
	{
		UE_LOG(LogClass, Warning, TEXT("Travel!!"));
		PC->ClientTravel("/Game/Maps/NetworkError", ETravelType::TRAVEL_Absolute);	
	}

}

void UMyGameInstance::ClientTravel(FString path)
{
	APlayerController* PC = GetFirstLocalPlayerController();
	if (PC && PC->IsValidLowLevel())
	{
		PC->ClientTravel(path, ETravelType::TRAVEL_Absolute);
	}
}

