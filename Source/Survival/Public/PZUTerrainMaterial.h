#pragma once

#include "CoreMinimal.h"
#include "Materials/Material.h"

class SURVIVAL_API PZUTerrainMaterial
{
private:
	FString name;
	float value;

public:
	PZUTerrainMaterial(FString name, float value);
	~PZUTerrainMaterial();

	FString textureTop;
	FString textureNorth;
	FString textureEast;
	FString textureSouth;
	FString textureWest;
	FString textureBottom;

	void SetTextureAll(FString terrainTextureId);
	void SetTextureSides(FString terrainTextureId);
};
