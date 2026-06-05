// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"



DECLARE_LOG_CATEGORY_EXTERN(LogItem, Log, All);
// 이 클래스를 리플렉션 시스템에 등록하는 매크로입니다.
// 언리얼 에디터에서 이 클래스를 블루프린트로 확장할 수 있게 하고, 에디터의 여러 기능과 연동하도록 합니다.
UCLASS()
class BC_CH3_ASSIGNMENT_3_API AItem : public AActor
{// A (Actor 계열), U (Object 계열), F (구조체), T (템플릿), E (열거형) 등
	
	// UCLASS()와 짝을 이루어, 언리얼 헤더툴 (UHT)이 자동 생성한 코드를 삽입해 주는 매크로입니다.
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	
	
protected:	
	// 회전 속도, 클래스 기본값만 수정 가능
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Properties")
	float RotationSpeed = 90.0f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Root Scene Component, 에디터에서 볼 수만 있고 수정 불가
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Item|Components")
	// 루트 컴포넌트를 나타내는 Scene Component 포인터
	USceneComponent* SceneRoot;
	
	
	// Static Mesh, 에디터와 Blueprint에서 수정 가능
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item|Components")
	// Static Mesh Component 포인터
	UStaticMeshComponent* StaticMeshComp;
	
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item|Components")
	UAudioComponent* AudioComp;

	// ===
	
	// 함수를 블루프린트에서 호출 가능하도록 설정
	UFUNCTION(BlueprintCallable, Category="Item|Actions")
	void ResetActorPosition();
		
	// 블루프린트에서 값만 반환하도록 설정
	UFUNCTION(BlueprintPure, Category = "Item|Properties")
	float GetRotationSpeed() const;

	// C++에서 호출되지만 구현은 블루프린트에서 수행
	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUp();
	//
	/*
	virtual void PostInitializeComponents() override;
	virtual void Destroyed() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	*/



	
};
