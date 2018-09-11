// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Master_TestActor.generated.h"


UCLASS()
class TESTPROJECT_API AMaster_TestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaster_TestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	class AMaster_Manager* ManagerReference;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AMaster_Manager* ManagerReferenceBP;

	UFUNCTION(BlueprintCallable)
	TArray<int32> SliceIntArray(UPARAM(ref) TArray<int32>& InArray, int32 Start, int32 End);

};
