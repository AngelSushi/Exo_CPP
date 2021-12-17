
#include "JumpPad.h"
#include "TPS_A2_CPPCharacter.h"

AJumpPad::AJumpPad() {
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Meshee"));
	RootComponent = MeshComponent;
}

void AJumpPad::BeginPlay() {
	Super::BeginPlay();

	MeshComponent->OnComponentHit.AddDynamic(this,&AJumpPad::OnHit);
	
}

// Called every frame
void AJumpPad::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AJumpPad::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {

	ATPS_A2_CPPCharacter* character = Cast<ATPS_A2_CPPCharacter>(OtherActor);
	
	if (character == nullptr)
		return;

	character->LaunchCharacter(FVector(0,0,2000),false,true);
	
}

