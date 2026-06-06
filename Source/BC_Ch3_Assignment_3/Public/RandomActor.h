// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomActor.generated.h"


// #define ITEM_ROTATION_CATEGORY "Rotation"
// const FString이나 static const char* 같은 변수로 빼는 방식은 추천하지 않아요.
//  static const char* RotationCategory = "Rotation";
// 이런 식은 C++ 변수라서, 언리얼 헤더 툴이 UPROPERTY 메타데이터를 해석하는 단계에서 원하는 대로 처리되지 않을 수 있어요.

/*
 
가장 흔한 방식: Category = "Rotation"
반복을 줄이고 싶다면: #define ITEM_ROTATION_CATEGORY "Rotation"
FString, std::string, const char* 변수로 빼는 방식은 피하는 게 좋아요

 */

UCLASS()
class BC_CH3_ASSIGNMENT_3_API ARandomActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARandomActor();

	// properties
protected:
	// Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomActor|Components")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RandomActor|Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;

	
	// property
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RandomActor|Properties")
	FVector StartLocation = FVector(0.0f, 0.0f, 0.0f);
	
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
	
	UFUNCTION(BlueprintCallable, Category="RandomActor|Actions")
	void MoveRandom();
	
	
	
private:
	FTimerHandle MoveTimerHandle;
};
