#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Materials/Material.h"
#include "PZUWorld.h"
#include "PZUGameInstance.h"
#include "PZUTerrain.generated.h"

UCLASS()
class SURVIVAL_API APZUTerrain : public AActor
{
	GENERATED_BODY()

private:
	UProceduralMeshComponent* terrainMesh;
	UMaterial* terrainMaterial;

	UPZUGameInstance* gameInstance;
	


	PZUWorld* sourceWorld;

public:
	int resolution;

	APZUTerrain();
	virtual void BeginPlay() override;
	void SetWorld(PZUWorld* w);
	void Refresh();

	UFUNCTION(BlueprintCallable)
		void MainMenuWorld();

	UFUNCTION(BlueprintCallable)
	UStaticMesh* ConvertProceduralMeshToStaticMesh(UProceduralMeshComponent* proceduralMesh);
	UFUNCTION(BlueprintCallable)
	UProceduralMeshComponent* getProceduralTerrainMesh();

};