#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LavaArea.generated.h"

UCLASS()
class TPS_A2_CPP_API ALavaArea : public AActor
{
	GENERATED_BODY()
	
public:	
	ALavaArea();

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	FVector SpawnVector;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
