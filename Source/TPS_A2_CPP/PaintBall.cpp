// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintBall.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
// Sets default values
APaintBall::APaintBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));


	//MeshComponent->SetStaticMesh(CreateDefaultSubobject<USphereComponent>());
	RootComponent = MeshComponent;

	projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	projectile->SetUpdatedComponent(MeshComponent);
	projectile->InitialSpeed = 1000.f;
	projectile->MaxSpeed = 1000.f;
	projectile->ProjectileGravityScale = 0.0f;
	
	
	MeshComponent->OnComponentHit.AddDynamic(this, &APaintBall::OnHit);
}

// Called when the game starts or when spawned
void APaintBall::BeginPlay()
{
	SetActorLocation(BeginLocation);
	Super::BeginPlay();
	
}

// Called every frame
void APaintBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APaintBall::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {

}
