// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/Script/Engine.StaticMesh'/Game/P38/Meshes/SM_Rocket.SM_Rocket'"));

	if (SM_Body.Succeeded())
	{
		Body->SetStaticMesh(SM_Body.Object);
	}
	Body->SetRelativeRotation(FRotator(-90.f, 0, 0));

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));

	Movement->InitialSpeed = 2000.f;
	Movement->MaxSpeed = 2000.f;
	Movement->ProjectileGravityScale = 0.f;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(0.3f);

	OnActorBeginOverlap.AddDynamic(this, &AMyActor::ProcessBeginOverlap);

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Test()
{
	UE_LOG(LogTemp, Warning, TEXT("테스트 함수 입니다."));
}

void AMyActor::ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag(TEXT("Player")))
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("%s"), *OtherActor->GetName());

	UGameplayStatics::ApplyDamage(OtherActor,
		100.f,
		nullptr,
		this,
		UDamageType::StaticClass()
	);

	// 상속된 블루프린트에서 기획자가 함수를 구현할 수 있도록 함
	CallCPPToDefaultExcuteBP(100);

	Destroy();
}

void AMyActor::CallCPPToDefaultExcuteBP_Implementation(int Damage)
{
	UE_LOG(LogTemp, Warning, TEXT("이건 CPP 호출"), Damage);
}
