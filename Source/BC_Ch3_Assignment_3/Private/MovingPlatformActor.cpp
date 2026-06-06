// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformActor.h"

// Sets default values
AMovingPlatformActor::AMovingPlatformActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	//StaticMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	SetActorLocation(StartLocation);
	

	
}

// Called when the game starts or when spawned
void AMovingPlatformActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("AMovingPlatformActor BeginPlay") , *GetName());
	
	
	SetActorLocation(StartLocation);
	
}

// Called every frame
void AMovingPlatformActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	

	// forward & backward
	
	if (!FMath::IsNearlyZero(MoveSpeed))
	{						
		//UE_LOG(LogTemp, Warning, TEXT("MaxRange: %f") , MaxRange);
		if (bToggleForward == true)
		{
			AddActorLocalOffset(FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f));	
			// AddActorWorldOffset(FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f));
			
			if (GetActorLocation().X > (MaxRange + StartLocation.X))
			{				
				bToggleForward = false;
			}			
				
		}
		else
		{
			AddActorLocalOffset(FVector(-MoveSpeed * DeltaTime, 0.0f, 0.0f));
			
			if (GetActorLocation().X < (StartLocation.X - MaxRange))
				bToggleForward = true;
			
		}		
		
	}	
	
	// up down
	if (!FMath::IsNearlyZero(UpDownSpeed))
	{
		if (bToggleUp == true)
		{
			AddActorLocalOffset(FVector(0.0f,0.0f, UpDownSpeed * DeltaTime));
			
			if (GetActorLocation().Z > (MaxRange + StartLocation.Z))
				bToggleUp = false;
		}
		else
		{
			AddActorLocalOffset(FVector(0.0f,0.0f, -UpDownSpeed * DeltaTime));
			
			if (GetActorLocation().Z < (StartLocation.Z - MaxRange))
				bToggleUp = true;
		}
		
		
	}	
	

}

void AMovingPlatformActor::MovingPlatformActor()
{
	if (!bIsMoving)
	{
		return;	
	}
	else
	{
		SetActorLocation(GetActorLocation() + FVector(MoveSpeed, 0.0f,0.0f ));
	}
	

}

void AMovingPlatformActor::UpDownPlatformActor()
{
	if (!bIsMoving)
	{
		return;	
	}
	else
	{
		SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f,UpDownSpeed ));
	}
	

}

