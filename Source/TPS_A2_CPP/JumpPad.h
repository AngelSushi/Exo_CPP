
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JumpPad.generated.h"

UCLASS()
class TPS_A2_CPP_API AJumpPad : public AActor
{
	GENERATED_BODY()
	
public:	
	AJumpPad();

	UPROPERTY()
	class USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComponent;


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
