
#include "LavaArea.h"
#include "TPS_A2_CPPCharacter.h"
#include "TPS_A2_CPPGameMode.h"

ALavaArea::ALavaArea() {
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;


}

void ALavaArea::BeginPlay() {
	Super::BeginPlay();

	GLog->Log("egin");
	MeshComponent->OnComponentHit.AddDynamic(this, &ALavaArea::OnHit);
	
}

void ALavaArea::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void ALavaArea::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	ATPS_A2_CPPCharacter* character = Cast<ATPS_A2_CPPCharacter>(OtherActor);
	ATPS_A2_CPPGameMode* gm = Cast<ATPS_A2_CPPGameMode>(GetWorld()->GetAuthGameMode());

	if (character == nullptr)
		return;

	gm->RestartPlayer(character->GetController());
	character->SetActorLocation(SpawnVector);


	//GetWorld()->DestroyActor(character);
	
}

