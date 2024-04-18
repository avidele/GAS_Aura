// Copyright Avidel


#include "Learning/AINavCharacter.h"

// Sets default values
AAINavCharacter::AAINavCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// int32 Sum = 0;
	// ParallelFor(10000, [&Sum](int32 Index)
	// {
	// 	Sum += Index;
	// 	UE_LOG(LogTemp, Warning, TEXT("Sum: %d"), Sum);
	// });                          
	// FCriticalSection Mutex;
	// ParallelFor(10000, [&Mutex](int32 Index)
	// {
	// 	if (Index % 5 == 0)
	// 	{
	// 		Mutex.Lock();
	// 		Index++;
	// 		UE_LOG(LogTemp, Warning, TEXT("Index2: %d"), Index);
	// 		Mutex.Unlock();
	// 	}
	// 	else
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("Index2: %d"), Index);
	// 	}
	// });

}

// Called when the game starts or when spawned
void AAINavCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAINavCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAINavCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

