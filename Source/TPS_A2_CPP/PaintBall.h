// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaintBall.generated.h"

UCLASS()
class TPS_A2_CPP_API APaintBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaintBall();

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Model;

	UPROPERTY(EditAnywhere)
	FVector Forward;

	UPROPERTY(EditAnywhere)
		FVector BeginLocation;

	UPROPERTY(EditAnywhere)
	float BallSpeed;

	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent* projectile;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
