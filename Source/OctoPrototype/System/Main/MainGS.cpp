// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGS.h"
#include "UnrealNetwork.h"


void AMainGS::OnRep_CurrentGameState()
{
	DoWhenCurrentGameStateChanged();
}

void AMainGS::DoWhenCurrentGameStateChanged_Implementation()
{
}

void AMainGS::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMainGS, CurrentGameState);
}
