// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnActor.h"

#include "RandomActor.h"

// Sets default values
ASpawnActor::ASpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

}

// Called when the game starts or when spawned
void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();
	
	
	
	
	FRotator SpawnRotation = GetActorRotation();
	
	//GetWorld()->SpawnActor<ARandomActor>(SpawnLocation, SpawnRotation);
	
	for (int i = 0; i < SpawnCount; i++)
	{
		FVector SpawnLocation = FVector(FMath::FRandRange(MinRandom, MaxRandom), FMath::FRandRange(MinRandom, MaxRandom), FMath::FRandRange(MinRandom, MaxRandom));
		
		if (ActorToSpawn != nullptr)
		GetWorld()->SpawnActor<AActor>( ActorToSpawn, 
		SpawnLocation,
		SpawnRotation);
	}
	
	for (int i = 0; i < SpawnCount; i++)
	{
		FVector SpawnLocation = FVector(FMath::FRandRange(MinRandom, MaxRandom), FMath::FRandRange(MinRandom, MaxRandom), FMath::FRandRange(MinRandom, MaxRandom));
		
		if (MovingPlatformActor != nullptr)
			GetWorld()->SpawnActor<AActor>( MovingPlatformActor, 
			SpawnLocation,
			SpawnRotation);
	}
	
	for (int i = 0; i < SpawnCount; i++)
	{
		FVector SpawnLocation = FVector(FMath::FRandRange(MinRandom, MaxRandom), FMath::FRandRange(MinRandom, MaxRandom), FMath::FRandRange(MinRandom, MaxRandom));
		
		if (RotatingPlatformActor != nullptr)
			GetWorld()->SpawnActor<AActor>( RotatingPlatformActor, 
			SpawnLocation,
			SpawnRotation);
	}
	
}

// Called every frame
void ASpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

