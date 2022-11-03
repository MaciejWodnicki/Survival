#include "PZUWorld.h"

PZUWorld::PZUWorld()
{
	/*blockDefinitions.Add(0, "dirt");
	blockDefinitions.Add(1, "grass");
	blockDefinitions.Add(2, "stone");
	blockDefinitions.Add(3, "wood_log");
	blockDefinitions.Add(4, "leaves");
	blockDefinitions.Add(5, "wood_planks");
	blockDefinitions.Add(6, "alder_log");
	blockDefinitions.Add(7, "iron_plate");
	blockDefinitions.Add(8, "hazard_block");

	blockDefinitions.Add(9, "concrete");
	blockDefinitions.Add(10, "concrete_tiled");
	blockDefinitions.Add(11, "bricks");
	blockDefinitions.Add(12, "sand");*/

	/*FSPMap lobby;

	int baseX = 0;
	int baseWidth = 17;
	int baseY = 23;
	int baseHeight = 48;

	int headquartersX = 2;
	int headquartersWidth = 15;
	int headquartersY = 25;
	int headquartersHeight = 46;
	int headquartersZ = 2;
	int headquartersDepth = 10;

	lobby.size = FVector(64, 64, 64);

	for (int i = 0;i < 64; i++)
		for (int j = 0;j < 64; j++)
		{
			if (FMath::Pow(i - 31, 2) + FMath::Pow(j - 35, 2) <= FMath::Pow(17, 2))
				lobby.blocks.Add(FVector(i, j, 0), 12);
			if (FMath::Pow(i - 31, 2) + FMath::Pow(j - 35, 2) <= FMath::Pow(12, 2))
			{
				lobby.blocks.Add(FVector(i, j, 2), 1);
			}
			if (FMath::Pow(i - 31, 2) + FMath::Pow(j - 35, 2) <= FMath::Pow(13, 2))
			{
				lobby.blocks.Add(FVector(i, j, 1), 2);
			}
		}

	for (int i = 28;i < 33; i++)
		for (int j = 0;j < 38; j++)
		{
			lobby.blocks.Add(FVector(i, j, 1), 5);
			lobby.blocks.Add(FVector(i, j, 2), 5);
		}
	for (int j = 33;j < 38; j++)
		for (int i = 0;i < 33; i++)
		{
			lobby.blocks.Add(FVector(i, j, 1), 5);
			lobby.blocks.Add(FVector(i, j, 2), 5);
		}
	for (int i = baseX; i < baseWidth; i++)
		for (int j = baseY; j < baseHeight; j++)
		{
			lobby.blocks.Add(FVector(i, j, 0), 2);
			lobby.blocks.Add(FVector(i, j, 1), 2);
			lobby.blocks.Add(FVector(i, j, 2), 1);
		}
	for (int i = headquartersX; i < headquartersWidth; i++)
		for (int j = headquartersY; j < headquartersHeight; j++)
			for (int k = headquartersZ; k < headquartersDepth; k++)
			{
				if (i == headquartersX || i == headquartersWidth - 1 || j == headquartersY ||
					j == headquartersHeight - 1 || k == headquartersZ || k == headquartersDepth - 1)
					lobby.blocks.Add(FVector(i, j, k), 9);
				if (k == headquartersZ)
					lobby.blocks.Add(FVector(i, j, k), 10);
			}
	lobby.blocks.Remove(FVector(headquartersWidth - 1, 35, 3));
	lobby.blocks.Remove(FVector(headquartersWidth - 1, 35, 4));
	lobby.blocks.Remove(FVector(headquartersWidth - 1, 35, 5));
	lobby.blocks.Remove(FVector(headquartersWidth - 1, 34, 3));
	lobby.blocks.Remove(FVector(headquartersWidth - 1, 34, 4));
	lobby.blocks.Remove(FVector(headquartersWidth - 1, 34, 5));
	lobby.blocks.Remove(FVector(headquartersWidth - 1, 36, 3));
	lobby.blocks.Remove(FVector(headquartersWidth - 1, 36, 4));
	lobby.blocks.Remove(FVector(headquartersWidth - 1, 36, 5));

	//lobby.modifiers.Add(new SPTerrainModifierAttractionPoint(FVector(400, 400, 600), 1500, 150));

	lobby.buildings.Add(FSPMapElementBuilding(FTransform(FRotator(0, -90, 0), FVector(1345, 3000, 300), FVector(1, 1, 1)),
		FSPBuilding::GetInstance("workbench_carpenters")));

	lobby.buildings.Add(FSPMapElementBuilding(FTransform(FRotator(0, 0, 0), FVector(2605, 4275, 300), FVector(1, 1, 1)),
		FSPBuilding::GetInstance("tree_alder")));
	lobby.buildings.Add(FSPMapElementBuilding(FTransform(FRotator(0, 20, 0), FVector(3055, 4090, 300), FVector(1, 1, 1)),
		FSPBuilding::GetInstance("tree_alder")));
	lobby.buildings.Add(FSPMapElementBuilding(FTransform(FRotator(0, -30, 0), FVector(2718, 3000, 300), FVector(1, 1, 1)),
		FSPBuilding::GetInstance("tree_alder")));

	lobby.buildings.Add(FSPMapElementBuilding(FTransform(FRotator(0, 0, 0), FVector(2797, 4121, 300), FVector(1, 1, 1)),
		FSPBuilding::GetInstance("bush_raspberry")));
	lobby.buildings.Add(FSPMapElementBuilding(FTransform(FRotator(0, 0, 0), FVector(3388, 3425, 300), FVector(1, 1, 1)),
		FSPBuilding::GetInstance("bush_raspberry")));
	lobby.buildings.Add(FSPMapElementBuilding(FTransform(FRotator(0, 0, 0), FVector(3584, 4315, 300), FVector(1, 1, 1)),
		FSPBuilding::GetInstance("bush_raspberry")));

	lobby.items.Add(FSPMapElementItem(FTransform(FRotator(88, -102, 90), FVector(1347, 2936, 400), FVector(1, 1, 1)),
		FSPItem::SetInstance("axe")));
	lobby.items.Add(FSPMapElementItem(FTransform(FRotator(0, 90, 0), FVector(1321, 2999, 400), FVector(1, 1, 1)),
		FSPItem::SetInstance("book")));
	lobby.items.Add(FSPMapElementItem(FTransform(FRotator(0, 100, 180), FVector(1360, 3040, 400), FVector(1, 1, 1)),
		FSPItem::SetInstance("steak_raw", 3)));
	lobby.items.Add(FSPMapElementItem(FTransform(FRotator(0, 100, 180), FVector(1321, 3137, 332), FVector(1, 1, 1)),
		FSPItem::SetInstance("stone")));

	maps.Add(lobby);
	SetActiveMap(0);*/
}
PZUWorld::~PZUWorld()
{
}
/*PZUWorld& PZUWorld::MainMenuWorld()
{
	SPWorld* world = new SPWorld();

	FSPMap* map = new FSPMap();
	map->size = FVector(24, 18, 8);

	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 18; j++)
		{
			map->blocks.Add(FVector(i, j, 0), 1);
		}
	for (int i = 0; i < 24; i++)
		for (int j = 1; j < 4; j++)
		{
			map->blocks.Add(FVector(23, i, j), 9);
		}

	int wipX = 18;
	int wipZ = 1;
	int wipMaterialIndex = 8;
	for (int i = 2; i < 16; i++)
		for (int j = 1; j < 9; j++)
		{
			map->blocks.Add(FVector(wipX + 1, i, j), 11);
		}
	// Text "WIP"
	map->blocks.Add(FVector(wipX, 3, wipZ + 5), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 3, wipZ + 4), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 3, wipZ + 3), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 3, wipZ + 2), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 4, wipZ + 1), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 5, wipZ + 2), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 5, wipZ + 3), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 6, wipZ + 1), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 7, wipZ + 2), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 7, wipZ + 3), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 7, wipZ + 4), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 7, wipZ + 5), wipMaterialIndex);

	map->blocks.Add(FVector(wipX, 9, wipZ + 1), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 9, wipZ + 2), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 9, wipZ + 3), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 9, wipZ + 5), wipMaterialIndex);

	map->blocks.Add(FVector(wipX, 11, wipZ + 1), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 11, wipZ + 2), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 11, wipZ + 3), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 11, wipZ + 4), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 11, wipZ + 5), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 12, wipZ + 3), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 12, wipZ + 5), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 13, wipZ + 3), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 13, wipZ + 5), wipMaterialIndex);
	map->blocks.Add(FVector(wipX, 14, wipZ + 4), wipMaterialIndex);

	//pile of cubes
	map->blocks.Add(FVector(16, 2, 1), 0);
	map->blocks.Add(FVector(15, 1, 1), 2);
	map->blocks.Add(FVector(14, 0, 1), 3);
	map->blocks.Add(FVector(15, 0, 2), 4);
	map->blocks.Add(FVector(16, 1, 2), 5);
	map->blocks.Add(FVector(16, 0, 3), 7);

	world->AddMap(*map);
	world->SetActiveMap(0);

	return *world;
}*/
/*SPWorld& SPWorld::TutorialWorld()
{
	SPWorld* world = new SPWorld();

	return *world;
}*/
void PZUWorld::AddMap(FPZUMap& map)
{
	maps.Add(map);
}
void PZUWorld::SetActiveMap(int index)
{
	currentMap = &maps[index];
}
FString PZUWorld::GetTerrainMaterial(int id)
{
	return blockDefinitions[id];
}