#include "PZUWorld.h"

void AddTree(FVector location, FPZUMap& map) // dodawanie drzewa
{
	for (int x = -2;x < 3;x++)
		for (int y = -2;y < 3;y++)
		{
			map.blocks.Add(location + FVector(x, y, 3), 4);
			map.blocks.Add(location + FVector(x, y, 4), 4);
		}
	for (int x = -1;x < 2;x++)
		for (int y = -1;y < 2;y++)
		{
			map.blocks.Add(location + FVector(x, y, 5), 4);
		}

	map.blocks.Add(location, 3);
	map.blocks.Add(location + FVector(0, 0, 1), 3);
	map.blocks.Add(location + FVector(0, 0, 2), 3);
	map.blocks.Add(location + FVector(0, 0, 3), 3);
	map.blocks.Add(location + FVector(0, 0, 4), 3);
	map.blocks.Add(location + FVector(0, 0, 6), 4);
}

PZUWorld::PZUWorld() 
{
	// ladowanie definicji blokow
	blockDefinitions.Add(0, "dirt");
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
	blockDefinitions.Add(12, "sand");

	FPZUMap map;
	int sizex = 128;
	int sizey = 128;
	int sizez = 64;

	map.size = FVector(sizex, sizey, sizez); // wielkosc mapy

	for (int x = 0;x < sizex;x++)
		for (int y = 0;y < sizey;y++)
		{
			map.blocks.Add(FVector(x, y, 0), 1);
			if (x < 128 && y < 24)
			{
				map.blocks.Add(FVector(x, y, 0), 12);
			}


			for (int z = 0; z < 32; z++)
			{
				if (sizey - y == 100 - z)
				{
					for (int i = 0; i < z; i++)
					{
						map.blocks.Add(FVector(x, y + 70, i), 2);
					}
				}

			}


			// Perlin Noise 2D Surface
			// tworzenie roznorodnego terenu 
			int terrainHeight = FMath::Rand() % 2; 
			if (!(x < 128 && y < 24))
			for (int i = 1;i < terrainHeight + 1;i++)
			{

				map.blocks.Add(FVector(x, y, i), *map.blocks.Find(FVector(x, y, 0)));
			}

		
		}


	for (int x = 0; x < sizex + 1; x++)
		for (int z = 0; z < sizez + 1; z++)
		{
			map.blocks.Remove(FVector(x, -1, z));
			map.blocks.Remove(FVector(x, sizey, z));
		}

	for (int y = 0; y < sizey + 1; y++)
		for (int z = 0; z < sizez + 1; z++)
		{
			map.blocks.Remove(FVector(-1, y, z));
			map.blocks.Remove(FVector(sizex, y, z));
		}


	AddTree(FVector(5, 8, 1), map);

	maps.Add(map);
	SetActiveMap(0);

}
PZUWorld::~PZUWorld()
{
}

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