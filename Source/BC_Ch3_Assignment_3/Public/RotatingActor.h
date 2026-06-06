// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class BC_CH3_ASSIGNMENT_3_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
protected:
	
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor|Components")
	TObjectPtr<USceneComponent> SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="RotatingActor|Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;
	*/
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotatingActor|Components")
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MovingPlatformActor|Components")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotatingActor|Components")
	UStaticMeshComponent* StaticMeshComp;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotatingActor|Properties")
	float RotationSpeed = 100.0f;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotatingActor|Properties")
	bool bRotateOnPitch = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotatingActor|Properties")
	bool bRotateOnYaw = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotatingActor|Properties")
	bool bRotateOnRoll = false;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MovingPlatformActor|Properties")
	FVector StartLocation = FVector(0.0f, 0.0f, 0.0f);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
