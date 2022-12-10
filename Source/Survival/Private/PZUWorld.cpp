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

void IslandElevation(int width, int height, int pos_x, int pos_y, FPZUMap& map)
{
	for (int x = 0; x < 255; x++)
		for (int y = 0; y < 355; y++)
			if (x >= 0 && x <= 255 && y >= 0 && y <= 355)
				if ((float)FMath::Pow(x - 128, 2) / FMath::Pow(64, 2) + (float)FMath::Pow(y - 178, 2) / FMath::Pow(96, 2) < 1)
				{
					for (int i = 62; i >= 2; i--)
					{
						if (map.blocks.Contains(FVector(x, y, i - 1)))
						{
							map.blocks.Add(FVector(x, y, i), map.blocks[FVector(x, y, i - 1)]);
						}
						else
						{
							map.blocks.Remove(FVector(x, y, i));
						}
					}
				}
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
	int sizex = 256;
	int sizey = 356;
	int sizez = 64;

	map.size = FVector(sizex, sizey, sizez); // wielkosc mapy


	for (int x = 0;x < sizex;x++)
		for (int y = 0;y < sizey;y++)
		{
			// tworzenie roznorodnego terenu 
			int terrainHeight = 1;
			int terrainHeight2 = 2;
			int terrainHeight3 = 3;
			int terrainHeight4 = 4;

			if (FMath::Floor(FMath::Rand() % 5) == 0) // wstepny ksztalt terenu poza "plaza"
				terrainHeight -= (FMath::Rand() % 4) - 1;
			if (!(x < 64 && y < 72)) // maska terenu ktory mamy stworzyc 
				for (int i = 0;i < terrainHeight + 1;i++)
				{

					map.blocks.Add(FVector(x, y, i), 1); // dodanie blokow

				}

			if (FMath::Floor(FMath::Rand() % 10) == 0) // dodawanie kolejnych warstw terenu 
				terrainHeight2 -= (FMath::Rand() % 4) - 1;
			if (!(x < 100 && y < 105))
				for (int i = 0; i < terrainHeight2 + 1; i++)
				{

					map.blocks.Add(FVector(x, y, i), 1);

				}

			if (FMath::Floor(FMath::Rand() % 10) == 0)
				terrainHeight3 -= (FMath::Rand() % 4) - 1;
			if (!(x < 120 && y < 150))
				for (int i = 0; i < terrainHeight3 + 1; i++)
				{

					map.blocks.Add(FVector(x, y, i), 1);


				}

			if (FMath::Floor(FMath::Rand() % 10) == 0)
				terrainHeight4 -= (FMath::Rand() % 4) - 1;
			if (!(x < 170 && y < 200))
				for (int i = 0; i < terrainHeight4 + 1; i++)
				{

					map.blocks.Add(FVector(x, y, i), 1);


				}

		}

	for (int x = 0; x < sizex; x++)
		for (int y = 0; y < sizey; y++)
		{
			// generowanie plazy
			map.blocks.Add(FVector(x, y, 0), 0);
			if (x < 64 && y < 72)
			{
				map.blocks.Add(FVector(x, y, 0), 12);
			}

			//generowanie drzew
			for (int i = 10; i >= 0; i--)
			{
				if (map.blocks.Contains(FVector(x, y, i)) && map.blocks[FVector(x, y, i)] == 1)
				{
					if (FMath::Floor(FMath::Rand() % 150) == 0)
						AddTree(FVector(x, y, i + 1), map);
					break;
				}
			}

		}



	for (int x = 0; x < 255; x++)
		for (int y = 0; y < 355; y++)
			if (x >= 0 && x <= 255 && y >= 0 && y <= 355)
				if ((float)FMath::Pow(x - 128, 2) / FMath::Pow(64, 2) + (float)FMath::Pow(y - 178, 2) / FMath::Pow(96, 2) < 1)
				{
					for (int i = 62; i >= 2; i--)
					{
						if (map.blocks.Contains(FVector(x, y, i - 1)))
						{
							map.blocks.Add(FVector(x, y, i), map.blocks[FVector(x, y, i - 1)]);
						}
						else
						{
							map.blocks.Remove(FVector(x, y, i));
						}
					}
				}


	for (int x = 0; x < sizex + 1; x++) // obcinanie granicy mapy
		for (int z = 0; z < sizez + 1; z++)
		{
			map.blocks.Remove(FVector(x, -1, z));
			map.blocks.Remove(FVector(x, sizey, z));
		}

	for (int y = 0; y < sizey + 1; y++) // obcinanie granicy mapy
		for (int z = 0; z < sizez + 1; z++)
		{
			map.blocks.Remove(FVector(-1, y, z));
			map.blocks.Remove(FVector(sizex, y, z));
		}


	/*for (int i = 128; i > 32; i -= 8)
	{
		IslandElevation(i, i + 48, 0, 0, map);
	}

	for (int i = 128; i > 32; i -= 8)
	{
		IslandElevation(i, i + 48, 10, 50, map);
	}*/








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
void PZUWorld::SetActiveMap(int index) // ustawienie aktywnej mapy
{
	currentMap = &maps[index];
}
FString PZUWorld::GetTerrainMaterial(int id) // szukanie materialu odpowiedniego bloku
{
	return blockDefinitions[id];
}