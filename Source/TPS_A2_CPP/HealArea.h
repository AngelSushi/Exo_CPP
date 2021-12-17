#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealArea.generated.h"

UCLASS()
class TPS_A2_CPP_API AHealArea : public AActor {
	GENERATED_BODY()
	
public:	
	AHealArea();

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	float Damage;

	UPROPERTY(EditAnywhere)
	bool Heal;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
