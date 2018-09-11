// Fill out your copyright notice in the Description page of Project Settings.

#include "Master_TestActor.h"
#include "Algo/Reverse.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
AMaster_TestActor::AMaster_TestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//static ConstructorHelpers::FObjectFinder<UClass> YourBPOb(TEXT("/Game/Master_TestActorBP"));
	//if (YourBPOb.Object != NULL)
	//{
		// ManagerReferenceBP = Cast(YourBPOb.Object->GeneratedClass);
	//}
}

// Called when the game starts or when spawned
void AMaster_TestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMaster_TestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
double start = FPlatformTime::Seconds();

// put code you want to time here.




TArray<int32> AMaster_TestActor::SliceIntArray(UPARAM(ref) TArray<int32>& InArray, int32 Start, int32 End)
{
	UE_LOG(LogBlueprint, Warning, TEXT("Slice Start %d, End %d"), Start, End);
	double s = FPlatformTime::Seconds();

	TArray<int32> OutArray;

	if (End > InArray.Num())
		End = InArray.Num();
	if (Start < 0)
		Start = 0;

	//for (int Index = InArray.Num() - 1; Index >= 0 ; Index--)
	// for (int Index = 0; Index < InArray.Num(); Index++)

	// UE_LOG(LogBlueprint, Error, TEXT("Array: %d"), InArray.Num());

	for (int Index = InArray.Num() - 1; Index >= 0; Index--)
	{
		int32 Item = InArray[Index];
		// UE_LOG(LogBlueprint, Warning, TEXT("item: %d"), Item);
		// UE_LOG(LogBlueprint, Error, TEXT("index: %d"), Index);
		// Index >= Start and Index < End
		if (Index >= Start && Index < End)
		{	
			
			// UE_LOG(LogBlueprint, Warning, TEXT("NewItems: %d"), Item);
			OutArray.Add(InArray[Index]);
			InArray.RemoveAt(Index);
		}
	}
	double e = FPlatformTime::Seconds();
	UE_LOG(LogTemp, Warning, TEXT("code executed in %12f seconds."), e - s);

	FString InArrayString("[ ");
	for (auto& Item : InArray) 
	{
		// UE_LOG(LogBlueprint, Warning, TEXT("InArray after split: %d"), Item);
		// InArrayString += FString(", %d", Item);
		InArrayString += FString(FString::FromInt(Item) + ", ");
	}
	InArrayString.RemoveAt(InArrayString.Len() - 1, 2);
	InArrayString += FString("]");
	UE_LOG(LogBlueprint, Warning, TEXT("InArray %s"), *InArrayString);



	Algo::Reverse(OutArray);

	FString OutArrayString("[ ");
	for (auto& Item : OutArray)
	{
		OutArrayString += FString(FString::FromInt(Item) + ", ");
		//UE_LOG(LogBlueprint, Warning, TEXT("OutArray after split: %d"), Item);
	}
	OutArrayString.RemoveAt(OutArrayString.Len() - 1, 2);
	OutArrayString += FString("]");
	UE_LOG(LogBlueprint, Warning, TEXT("OutArray %s"), *OutArrayString);
	
	
	return OutArray;
}

