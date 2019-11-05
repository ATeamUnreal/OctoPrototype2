// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGM.h"
#include "MyGameInstance.h"

void AMainGM::PreLogin(const FString & Options, const FString & Address, const FUniqueNetIdRepl & UniqueId, FString & ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
}
