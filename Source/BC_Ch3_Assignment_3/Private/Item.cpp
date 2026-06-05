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
	
	// 1-4 hw
	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	AudioComp->SetupAttachment(StaticMeshComp);
	
	// Static Mesh를 코드에서 설정
	// ConstructorHelpers::FObjectFinder<T> 
		// Unreal Engine에서 특정 리소스를 경로 기반으로 로드하는 클래스입니다.
		// TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"):리소스의 경로를 나타냅니다. 리소스의 경로를 해당하는 에셋을 우클릭하고 Copy Reference를 해서 붙여넣기를 합니다.
		// Game은 Unreal Engine에서 프로젝트의 Content 폴더를 나타냅니다.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
	
	//.Succeeded()
		//지정된 경로에서 리소스를 성공적으로 찾았는지 확인합니다.
		//경로가 잘못되었거나 리소스 파일이 누락된 경우 실패하며, 이후 설정 함수가 호출되지 않습니다.
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	
	// SetStaticMesh(), SetMaterial()
		// 성공적으로 로드된 Static Mesh를 StaticMeshComp에 설정합니다.
		//로드된 Material을 StaticMeshComp의 특정 머티리얼 슬롯에 적용합니다. 여기서는 첫 번째 머티리얼 슬롯 (Index 0)에 Material이 설정됩니다. 
	

	// Material을 코드에서 설정
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	
	//
	
	static ConstructorHelpers::FObjectFinder<UAudioComponent> AudioAsset(TEXT("/Game/Resources/Audio/Crate_Break_Cue.Crate_Break_Cue"));
	
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Item BeginPlay") , *GetName());
	
}

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

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

