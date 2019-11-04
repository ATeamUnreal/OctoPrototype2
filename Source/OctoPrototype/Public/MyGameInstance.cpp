// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "SocketSubsystem.h"
#include <IPAddress.h>

void UMyGameInstance::Init()
{
	Super::Init();

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

