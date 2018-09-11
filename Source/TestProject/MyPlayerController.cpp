// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "MyCheatManager.h"
#include "Master_TestActor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


AMyPlayerController::AMyPlayerController()
{
	CheatClass = UMyCheatManager::StaticClass();
		
}

void AMyPlayerController::Debug_PrintCheat()
{
	UE_LOG(LogBlueprint, Error, TEXT("PlayerController Cheat Called"));


}
