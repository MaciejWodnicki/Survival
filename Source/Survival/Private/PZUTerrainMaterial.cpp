#include "PZUTerrainMaterial.h"

PZUTerrainMaterial::PZUTerrainMaterial(FString name, float value)
{
	this->name = name;
	this->value = value;
}
PZUTerrainMaterial::~PZUTerrainMaterial()
{
}
void PZUTerrainMaterial::SetTextureAll(FString terrainTextureId)
{
	textureTop = terrainTextureId;
	textureNorth = terrainTextureId;
	textureEast = terrainTextureId;
	textureSouth = terrainTextureId;
	textureWest = terrainTextureId;
	textureBottom = terrainTextureId;
}
void PZUTerrainMaterial::SetTextureSides(FString terrainTextureId)
{
	textureNorth = terrainTextureId;
	textureEast = terrainTextureId;
	textureSouth = terrainTextureId;
	textureWest = terrainTextureId;
}
