// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"


class UBoxComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UFloatingPawnMovement;
class UArrowComponent;


UCLASS()
class P38CPP_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> Left;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> Right;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UFloatingPawnMovement> Movement;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadOnly)
	TObjectPtr<UArrowComponent> Arrow;

	UPROPERTY(VisibleAnywhere, Category = "Data", BlueprintReadWrite)
	float MoveSpeed = 300.f;

	UPROPERTY(VisibleAnywhere, Category = "Data", BlueprintReadWrite)
	float RotateSpeed = 60.f;

	UPROPERTY(VisibleAnywhere, Category = "Data", BlueprintReadWrite)
	float Boost = 0.5f;

};
