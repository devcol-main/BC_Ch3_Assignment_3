// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomActor.h"

// Sets default values
ARandomActor::ARandomActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	//StaticMeshComp->SetRelativeLocation(StartLocation);
	SetActorLocation(StartLocation);
	
}

// Called when the game starts or when spawned
void ARandomActor::BeginPlay()
{
	Super::BeginPlay();
	
	//
	GetWorld()->GetTimerManager().SetTimer(
	 MoveTimerHandle,
	 this,
	 &ARandomActor::MoveRandom,
	 1.0f,
	 true
	 );
}

// Called every frame
void ARandomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARandomActor::MoveRandom()
{
	//SetActorLocation(FVector(FMath::RandRange(-100.0f, 100.0f), FMath::RandRange(-100.0f, 100.0f), FMath::RandRange(-100.0f, 100.0f)));
	SetActorLocation(FVector(FMath::FRandRange(MinRandom, MaxRandom), FMath::FRandRange(MinRandom, MaxRandom), FMath::FRandRange(MinRandom, MaxRandom)));

}

