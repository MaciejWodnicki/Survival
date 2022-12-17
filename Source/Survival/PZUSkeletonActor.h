#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PZUSkeletonActor.generated.h"

UCLASS()
class SURVIVAL_API APZUSkeletonActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Ustawia wartości domyślne właściwości tego actor
	APZUSkeletonActor();

protected:
	// Wywołuje się, gdy gra się rozpoczyna lub po pojawieniu się
	virtual void BeginPlay() override;

public:
	// Wywoływane co klatkę
	virtual void Tick(float DeltaTime) override;
};
