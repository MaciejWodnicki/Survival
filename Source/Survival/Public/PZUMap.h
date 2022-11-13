#pragma once

#include "PZUTerrainModifier.h"
//#include "PZUMapElementItem.h"
//#include "PZUMapElementBuilding.h"
#include "CoreMinimal.h"
#include "PZUMap.generated.h"

USTRUCT(BlueprintType)
struct SURVIVAL_API FPZUMap
{
	GENERATED_BODY()

public:
	FPZUMap();
	~FPZUMap();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector size;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<FVector, int32> blocks;

	TArray<PZUTerrainModifier*> modifiers;

	/*UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FSPMapElementItem> items;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FSPMapElementBuilding> buildings;*/
};
