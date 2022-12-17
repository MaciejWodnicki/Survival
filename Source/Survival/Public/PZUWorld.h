#pragma once

#include "PZUMap.h"
#include "PZUTerrainMaterial.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"

class SURVIVAL_API PZUWorld
{
private:
	TArray<FPZUMap> maps;

public:
	PZUWorld();
	~PZUWorld();

	void AddMap(FPZUMap& map);
	void SetActiveMap(int index);

	FString GetTerrainMaterial(int id);
	FPZUMap* currentMap = nullptr;

	TMap<int32, FString> blockDefinitions;
};
