#include "HealArea.h"
#include "TPS_A2_CPPCharacter.h"

AHealArea::AHealArea() {
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;

	MeshComponent->OnComponentHit.AddDynamic(this, &AHealArea::OnHit);
	Damage = 2;
	Heal = true;
}

void AHealArea::BeginPlay() {
	Super::BeginPlay();
	
}

void AHealArea::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AHealArea::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	ATPS_A2_CPPCharacter* character = Cast<ATPS_A2_CPPCharacter>(OtherActor);

	if (character == nullptr)
		return;

	character->Health += Heal ? Damage : Damage * -1;

	GLog->Log("Votre vie est de : " + FString::FromInt(character->Health));

}

