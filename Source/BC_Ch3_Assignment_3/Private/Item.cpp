// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "Components/AudioComponent.h"

DEFINE_LOG_CATEGORY(LogItem)

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);	
	
	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	AudioComp->SetupAttachment(SceneRoot);

	
	
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("Item BeginPlay") , *GetName());
	// SetActorLocation(FVector NewLocation): 액터 위치 이동
	// SetActorRotation(FRotator NewRotation): 액터 회전
	// SetActorScale3D(FVector NewScale): 액터 스케일 변경
	
	// GetActorLocation(), GetActorRotation(), GetActorScale3D(): 현재 Transform 정보 가져오기
	
	
	// SetActorTransform(FTransform NewTransform): 위치·회전·스케일을 한 번에 설정
	/*
	FVector NewLocation = FVector(300, 0.0f, 0.0f);
	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);
	FVector NewScale = FVector(2.0f);
	
	SetActorTransform(FTransform(NewRotation, NewLocation, NewScale));
	
	SetActorLocation(NewLocation);
	*/
	
	// 블루프린트에서 구현한 함수를 C++에서 호출함
	OnItemPickedUp();
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	/*
	if (!FMath::IsNearlyZero(UpDownSpeed))
	{		
		AddActorLocalOffset(FVector(0.0f, 0.0f, UpDownSpeed * DeltaTime));
	}
	
	//AddActorLocalRotation();	
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
	*/
	
	
}

/*

void AItem::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AItem::Destroyed()
{
	Super::Destroyed();
}

void AItem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

*/


// BlueprintCallable 함수 구현
void AItem::ResetActorPosition()
{
	// (0, 0, 0) 위치로 되돌립니다.
	SetActorLocation(FVector::ZeroVector); // == FVector(0.0f, 0.0f, 0.0f);
}

float AItem::GetRotationSpeed() const
{
	return RotationSpeed;
}

