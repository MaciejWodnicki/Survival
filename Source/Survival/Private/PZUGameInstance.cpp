#include "PZUGameInstance.h"
#include <Runtime/Engine/Public/ImageUtils.h>

void UPZUGameInstance::Initialize()
{
	// TEXTURE ATLAS
	// atlas tekstur definiuje pozycje kazdej tekstury uzywanej przez bloki
	UVAtlas.Add("dirt", TArray<FVector2d>{FVector2d(0, 0), FVector2d(0.25, 0.25)});
	UVAtlas.Add("grass_side", TArray<FVector2d>{FVector2d(0.25, 0), FVector2d(0.5, 0.25)});
	UVAtlas.Add("grass", TArray<FVector2d>{FVector2d(0.5, 0), FVector2d(0.75, 0.25)});
	UVAtlas.Add("stone", TArray<FVector2d>{FVector2d(0.75, 0), FVector2d(1, 0.25)});
	UVAtlas.Add("wood_log_side", TArray<FVector2d>{FVector2d(0, 0.25), FVector2d(0.25, 0.5)});
	UVAtlas.Add("wood_log", TArray<FVector2d>{FVector2d(0.25, 0.25), FVector2d(0.5, 0.5)});
	UVAtlas.Add("leaves", TArray<FVector2d>{FVector2d(0.5, 0.25), FVector2d(0.75, 0.5)});
	UVAtlas.Add("wood_planks", TArray<FVector2d>{FVector2d(0.75, 0.25), FVector2d(1, 0.5)});
	UVAtlas.Add("alder_log", TArray<FVector2d>{FVector2d(0, 0.5), FVector2d(0.25, 0.75)});
	UVAtlas.Add("alder_log_side", TArray<FVector2d>{FVector2d(0.25, 0.5), FVector2d(0.5, 0.75)});
	UVAtlas.Add("iron_plate", TArray<FVector2d>{FVector2d(0.5, 0.5), FVector2d(0.75, 0.75)});
	UVAtlas.Add("hazard_block", TArray<FVector2d>{FVector2d(0.75, 0.5), FVector2d(1, 0.75)});
	UVAtlas.Add("concrete", TArray<FVector2d>{FVector2d(0, 0.75), FVector2d(0.25, 1)});
	UVAtlas.Add("concrete_tiled", TArray<FVector2d>{FVector2d(0.25, 0.75), FVector2d(0.5, 1)});
	UVAtlas.Add("bricks", TArray<FVector2d>{FVector2d(0.5, 0.75), FVector2d(0.75, 1)});
	UVAtlas.Add("sand", TArray<FVector2d>{FVector2d(0.75, 0.75), FVector2d(1, 1)});

	// BLOCKS
	// definicje mozliwych materialow blokow
	blockDefinitions.Add("dirt", PZUTerrainMaterial("Dirt", 2)); // definicja bloku: wyswietlana nazwa bloku i wartosc
	blockDefinitions["dirt"].SetTextureAll("dirt"); // SetTextureAll - tekstura nakladana jest na wszystkie sciany bloku

	blockDefinitions.Add("grass", PZUTerrainMaterial("Grass", 3));
	blockDefinitions["grass"].SetTextureSides("grass_side"); // SetTextureSides - tekstura nakladana na 4 boczne sciany bloku
	blockDefinitions["grass"].textureTop = "grass";
	blockDefinitions["grass"].textureBottom = "dirt";

	blockDefinitions.Add("stone", PZUTerrainMaterial("Stone", 2));
	blockDefinitions["stone"].SetTextureAll("stone");

	blockDefinitions.Add("wood_log", PZUTerrainMaterial("Wood Log", 3));
	blockDefinitions["wood_log"].SetTextureSides("wood_log_side");
	blockDefinitions["wood_log"].textureTop = "wood_log";
	blockDefinitions["wood_log"].textureBottom = "wood_log";

	blockDefinitions.Add("leaves", PZUTerrainMaterial("Leaves", 2));
	blockDefinitions["leaves"].SetTextureAll("leaves");

	blockDefinitions.Add("wood_planks", PZUTerrainMaterial("Wood Planks", 2));
	blockDefinitions["wood_planks"].SetTextureAll("wood_planks");

	blockDefinitions.Add("alder_log", PZUTerrainMaterial("Wood Log", 3));
	blockDefinitions["alder_log"].SetTextureSides("alder_log_side");
	blockDefinitions["alder_log"].textureTop = "alder_log";
	blockDefinitions["alder_log"].textureBottom = "alder_log";

	blockDefinitions.Add("iron_plate", PZUTerrainMaterial("Wood Planks", 2));
	blockDefinitions["iron_plate"].SetTextureAll("iron_plate");

	blockDefinitions.Add("hazard_block", PZUTerrainMaterial("Wood Planks", 2));
	blockDefinitions["hazard_block"].SetTextureAll("hazard_block");

	blockDefinitions.Add("concrete", PZUTerrainMaterial("Concrete", 2));
	blockDefinitions["concrete"].SetTextureAll("concrete");

	blockDefinitions.Add("concrete_tiled", PZUTerrainMaterial("Tield Concrete", 2));
	blockDefinitions["concrete_tiled"].SetTextureAll("concrete_tiled");

	blockDefinitions.Add("bricks", PZUTerrainMaterial("Bricks", 2));
	blockDefinitions["bricks"].SetTextureAll("bricks");

	blockDefinitions.Add("sand", PZUTerrainMaterial("Sand", 1));
	blockDefinitions["sand"].SetTextureAll("sand");

	// ITEMS
	// definicje przedmiotow
	itemDefinitions.Add("undefined", FPZUItemDefinition("Undefined", 69, 1)); // domyslna instancja przedmiotu
	itemDefinitions["undefined"]
		.SetDataValue("mesh", "/Game/Items/SM_Item_Undefined") // metadane przedmiotu
		.SetDataValue("HIDDEN");
	itemDefinitions.Add("REMOVE", FPZUItemDefinition("", 0, 1)); // przedmiot "REMOVE" jest pomocnicza definicja bioraca udzial przy podmianie przedmiotu trzymanego przez gracza
	itemDefinitions["REMOVE"]
		.SetDataValue("mesh", "/Game/Items/SM_Item_Undefined")
		.SetDataValue("HIDDEN");

}
FString UPZUGameInstance::GetGameVersion()
{
	return GAME_VERSION;
}
TArray<FVector2D> UPZUGameInstance::GetUV(FString texture)
{
	return UVAtlas[texture];
}

UTexture2D* UPZUGameInstance::GetTextureFromAssets(FString path)
{
	return Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *path));
}