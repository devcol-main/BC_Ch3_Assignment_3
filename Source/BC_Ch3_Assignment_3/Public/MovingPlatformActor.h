// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatformActor.generated.h"

UCLASS()
class BC_CH3_ASSIGNMENT_3_API AMovingPlatformActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatformActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MovingPlatformActor|Components")
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MovingPlatformActor|Components")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MovingPlatformActor|Components")
	UStaticMeshComponent* StaticMeshComp;
	
	
	
	//UFUNCTION
	UFUNCTION(BlueprintCallable, Category="MovingPlatformActor|Actions")
	void MovingPlatformActor();
	
	//UFUNCTION
	UFUNCTION(BlueprintCallable, Category="MovingPlatformActor|Actions")
	void UpDownPlatformActor();
	
	//BlueprintNativeEvent:  C++ 기본 구현 가능 + 블루프린트에서 오버라이드 가능

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MovingPlatformActor|Properties")
	bool bIsMoving = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MovingPlatformActor|Properties")
	FVector StartLocation = FVector(0.0f, 0.0f, 0.0f);
		
	// Foward & Backward
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MovingPlatformActor|Properties")
	float MoveSpeed = 10.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "MovingPlatformActor|Properties")
	float MaxRange = 100.0f;
	
	
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MovingPlatformActor|Properties")
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MovingPlatformActor|Properties")
	float UpDownSpeed = 10.0f;
	
};
