#include "PZUTerrain.h"

APZUTerrain::APZUTerrain()
{
	gameInstance = Cast<UPZUGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	terrainMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("TerrainMesh"));
	FString materialPath = FString(TEXT("/Game/World/M_Terrain"));
	terrainMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, *materialPath));
	RootComponent = terrainMesh;
	resolution = 3;

	SetWorld(new PZUWorld());
}
void APZUTerrain::BeginPlay()
{
	Super::BeginPlay();
	Refresh();

}
void APZUTerrain::SetWorld(PZUWorld* w)
{
	sourceWorld = w;
}
void APZUTerrain::Refresh()
{
	FPZUMap* sourceMap = sourceWorld->currentMap;
	TArray<FVector> planeVertices;
	TArray<int32> planeTriangles;
	double planeStep = static_cast<double>(100) / (double)resolution;

	for (int x = 0; x <= resolution; x++)
		for (int y = 0; y <= resolution; y++)
		{
			planeVertices.Add(FVector(x * planeStep, y * planeStep, 0));

			if (x != resolution && y != resolution)
			{
				planeTriangles.Add(planeVertices.Num() - 1);
				planeTriangles.Add(planeVertices.Num());
				planeTriangles.Add(planeVertices.Num() + resolution);
				planeTriangles.Add(planeVertices.Num());
				planeTriangles.Add(planeVertices.Num() + resolution + 1);
				planeTriangles.Add(planeVertices.Num() + resolution);
			}
		}

	TArray<FVector> vertices;
	TArray<int32> triangles;
	TArray<FVector> normals;
	TArray<FVector2D> UV0;
	TArray<FProcMeshTangent> tangents;
	TArray<FLinearColor> vertexColors;

	for (int x = 0; x < sourceMap->size.X; x++)
		for (int y = 0; y < sourceMap->size.Y; y++)
			for (int z = 0; z < sourceMap->size.Z; z++)
			{
				if (sourceMap->blocks.Contains(FVector(x, y, z)))
				{
					int currentVertices;

					// Top
					if (!sourceMap->blocks.Contains(FVector(x, y, z + 1)))
					{
						currentVertices = vertices.Num();
						for (auto& v : planeVertices)
						{
							vertices.Add(FVector(1 - v.Y, v.X, 0) + FVector(x * 100 + 99, y * 100, z * 100 + 100));
							TArray<FVector2D> uv = gameInstance->GetUV(gameInstance->blockDefinitions[sourceWorld->blockDefinitions[sourceMap->blocks[FVector(x, y, z)]]].textureTop);
							UV0.Add(FVector2d(uv[0].X + v.X / 100 * (uv[1].X - uv[0].X), uv[0].Y + v.Y / 100 * (uv[1].Y - uv[0].Y)));
							normals.Add(FVector(0, 0, 1));
						}
						for (auto& t : planeTriangles)
						{
							triangles.Add(currentVertices + t);
						}
					}

					// North
					if (!sourceMap->blocks.Contains(FVector(x + 1, y, z)))
					{
						currentVertices = vertices.Num();
						for (auto& v : planeVertices)
						{
							vertices.Add(FVector(0, 1 - v.X, 1 - v.Y) + FVector(x * 100 + 100, y * 100 + 99, z * 100 + 99));
							TArray<FVector2D> uv = gameInstance->GetUV(gameInstance->blockDefinitions[sourceWorld->blockDefinitions[sourceMap->blocks[FVector(x, y, z)]]].textureNorth);
							UV0.Add(FVector2d(uv[0].X + v.X / 100 * (uv[1].X - uv[0].X), uv[0].Y + v.Y / 100 * (uv[1].Y - uv[0].Y)));
							normals.Add(FVector(1, 0, 0));
						}
						for (auto& t : planeTriangles)
						{
							triangles.Add(currentVertices + t);
						}
					}

					// East
					if (!sourceMap->blocks.Contains(FVector(x, y + 1, z)))
					{
						currentVertices = vertices.Num();
						for (auto& v : planeVertices)
						{
							vertices.Add(FVector(v.X, 0, 1 - v.Y) + FVector(x * 100, y * 100 + 100, z * 100 + 99));
							TArray<FVector2D> uv = gameInstance->GetUV(gameInstance->blockDefinitions[sourceWorld->blockDefinitions[sourceMap->blocks[FVector(x, y, z)]]].textureWest);
							UV0.Add(FVector2d(uv[0].X + v.X / 100 * (uv[1].X - uv[0].X), uv[0].Y + v.Y / 100 * (uv[1].Y - uv[0].Y)));
							normals.Add(FVector(0, 1, 0));
						}
						for (auto& t : planeTriangles)
						{
							triangles.Add(currentVertices + t);
						}
					}

					// South
					if (!sourceMap->blocks.Contains(FVector(x - 1, y, z)))
					{
						currentVertices = vertices.Num();
						for (auto& v : planeVertices)
						{
							vertices.Add(FVector(0, v.X, 1 - v.Y) + FVector(x * 100, y * 100, z * 100 + 99));
							TArray<FVector2D> uv = gameInstance->GetUV(gameInstance->blockDefinitions[sourceWorld->blockDefinitions[sourceMap->blocks[FVector(x, y, z)]]].textureSouth);
							UV0.Add(FVector2d(uv[0].X + v.X / 100 * (uv[1].X - uv[0].X), uv[0].Y + v.Y / 100 * (uv[1].Y - uv[0].Y)));
							normals.Add(FVector(-1, 0, 0));
						}
						for (auto& t : planeTriangles)
						{
							triangles.Add(currentVertices + t);
						}
					}

					// West
					if (!sourceMap->blocks.Contains(FVector(x, y - 1, z)))
					{
						currentVertices = vertices.Num();
						for (auto& v : planeVertices)
						{
							vertices.Add(FVector(1 - v.X, 0, 1 - v.Y) + FVector(x * 100 + 99, y * 100, z * 100 + 99));
							TArray<FVector2D> uv = gameInstance->GetUV(gameInstance->blockDefinitions[sourceWorld->blockDefinitions[sourceMap->blocks[FVector(x, y, z)]]].textureEast);
							UV0.Add(FVector2d(uv[0].X + v.X / 100 * (uv[1].X - uv[0].X), uv[0].Y + v.Y / 100 * (uv[1].Y - uv[0].Y)));
							normals.Add(FVector(0, -1, 0));
						}
						for (auto& t : planeTriangles)
						{
							triangles.Add(currentVertices + t);
						}
					}

					// Bottom
					if (!sourceMap->blocks.Contains(FVector(x, y, z - 1)))
					{
						currentVertices = vertices.Num();
						for (auto& v : planeVertices)
						{
							vertices.Add(FVector(v.Y, v.X, 0) + FVector(x * 100, y * 100, z * 100));
							TArray<FVector2D> uv = gameInstance->GetUV(gameInstance->blockDefinitions[sourceWorld->blockDefinitions[sourceMap->blocks[FVector(x, y, z)]]].textureBottom);
							UV0.Add(FVector2d(uv[0].X + v.X / 100 * (uv[1].X - uv[0].X), uv[0].Y + v.Y / 100 * (uv[1].Y - uv[0].Y)));
							normals.Add(FVector(0, 0, -1));
						}
						for (auto& t : planeTriangles)
						{
							triangles.Add(currentVertices + t);
						}
					}
				}
			}
	/*for (auto& modifier : sourceMap->modifiers)
		modifier->Apply(vertices);*/

	terrainMesh->CreateMeshSection_LinearColor(0, vertices, triangles, normals, UV0, vertexColors, tangents, true);
	terrainMesh->ContainsPhysicsTriMeshData(true);
	terrainMesh->SetMaterial(0, terrainMaterial);
}
void APZUTerrain::MainMenuWorld()
{
	PZUWorld* mainMenuWorld = new PZUWorld();
	FPZUMap* map = new FPZUMap();
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

	mainMenuWorld->AddMap(*map);
	mainMenuWorld->SetActiveMap(1);

	SetWorld(mainMenuWorld);
	Refresh();
}