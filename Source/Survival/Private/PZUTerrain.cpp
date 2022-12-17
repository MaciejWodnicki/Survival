#include "PZUTerrain.h"
#include "AssetRegistry/AssetRegistryModule.h" 
#include <RawMesh/Public/RawMesh.h>

APZUTerrain::APZUTerrain()
{
	// wskaznik na instancje gry - obiekt, ktory istnieje do konca dzialania gry
	gameInstance = Cast<UPZUGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	// wskaznik do proceduralnie generowanej siatki
	terrainMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("TerrainMesh"));
	// sciezka do materialu terenu
	FString materialPath = FString(TEXT("/Game/World/M_Terrain"));
	// material terenu
	terrainMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, *materialPath));
	RootComponent = terrainMesh;
	// ilosc kwadratow na scianie bloku terenu
	resolution = 1;

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
	// wskaznik do aktualnej mapy
	FPZUMap* sourceMap = sourceWorld->currentMap;
	// lista wierzcholkow sciany
	TArray<FVector> planeVertices;
	// lista trojkatow sciany
	TArray<int32> planeTriangles;
	double planeStep = static_cast<double>(100) / (double)resolution;

	// konstrukcja sciany bloku
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

	// atrybuty siatki terenu
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
	for (auto& modifier : sourceMap->modifiers)
		modifier->Apply(vertices);

	terrainMesh->CreateMeshSection_LinearColor(0, vertices, triangles, normals, UV0, vertexColors, tangents, true);
	terrainMesh->ContainsPhysicsTriMeshData(true);
	terrainMesh->SetMaterial(0, terrainMaterial);

}
