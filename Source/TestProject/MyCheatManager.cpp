// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCheatManager.h"
#include "Engine/World.h"
#include "MyPlayerController.h"

void UMyCheatManager::MyDebugFunction() 
{
	UE_LOG(LogBlueprint, Error, TEXT("Cheat Manager Exec Call"));
	
	AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetOuter());
	FString Name = PlayerController->GetName();
	UE_LOG(LogBlueprint, Error, TEXT("Exec Name %s"), *Name);
	PlayerController->Debug_PrintCheat();
	
}