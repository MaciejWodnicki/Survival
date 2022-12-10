#include "PZUSkeletonActor.h"

// Ustawia wartości domyślne
APZUSkeletonActor::APZUSkeletonActor()
{
	// Ustaw tę actor, aby wywoływać funkcję Tick() w każdej ramce. Możesz wyłączyć tę funkcję, aby zwiększyć wydajność, jeśli jej nie potrzebujesz.
	PrimaryActorTick.bCanEverTick = true;
}

// Wywołuje się, gdy gra się rozpoczyna lub po pojawieniu się
void APZUSkeletonActor::BeginPlay()
{
	Super::BeginPlay();
}

// Wywoływane co klatkę
void APZUSkeletonActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
