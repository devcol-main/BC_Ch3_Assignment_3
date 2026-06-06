// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnActor.generated.h"

UCLASS()
class BC_CH3_ASSIGNMENT_3_API ASpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnActor();
	
protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SpawnActor|Components")
	TObjectPtr<USceneComponent> SceneRoot;
	
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnActor|Properties")
	TSubclassOf<AActor> MovingPlatformActor;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnActor|Properties")
	TSubclassOf<AActor> RotatingPlatformActor;	
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RandomActor|Properties")
	TSubclassOf<AActor> ActorToSpawn;
	
	//
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="SpawnActor|Properties")
	int32 SpawnCount = 3;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RandomActor|Properties")
	float MinRandom = 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RandomActor|Properties")
	float MaxRandom = 200.0f;
	 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
