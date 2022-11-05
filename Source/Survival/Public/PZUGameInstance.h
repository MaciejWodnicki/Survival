#pragma once

#include "CoreMinimal.h"
#include "PZUTerrainMaterial.h"
#include "PZUItemDefinition.h"
#include "PZUItem.h"
//#include "SPItemRecipe.h"
//#include "SPBuildingDefinition.h"
//#include "SPWindowLayout.h"
#include "Engine/GameInstance.h"
#include "PZUGameInstance.generated.h"

UCLASS()
class SURVIVAL_API UPZUGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	TMap<FString, TArray<FVector2D>> UVAtlas;

public:
	const FString GAME_VERSION = "Pre-alpha 0.0.1";

	TMap<FString, PZUTerrainMaterial> blockDefinitions;
	TMap<FString, FPZUItemDefinition> itemDefinitions;
	//TArray<FSPItemRecipe> itemRecipes;
	//TMap<FString, FSPBuildingDefinition> buildingDefinitions;
	//TMap<FString, FSPWindowLayout> windowLayouts;

	UFUNCTION(BlueprintCallable)
		void Initialize();
	UFUNCTION(BlueprintCallable)
		FString GetGameVersion();
	TArray<FVector2D> GetUV(FString texture);

	UFUNCTION(BlueprintCallable)
		UTexture2D* GetTextureFromAssets(FString path);

	/*UFUNCTION(BlueprintCallable)
		TArray<FString> GetCraftingList(FString stationID, FString searchData);
	UFUNCTION(BlueprintCallable)
		FSPItemDefinition GetItemDefinition(FString id);
	UFUNCTION(BlueprintCallable)
		TArray<FString> GetItemDefinitionList();
	UFUNCTION(BlueprintCallable)
		UStaticMesh* GetItemMesh(FString path);
	UFUNCTION(BlueprintCallable)
		FString GetItemData(FString id, FString key);
	UFUNCTION(BlueprintCallable)
		FString GetBuildingData(FString id, FString key);
	UFUNCTION(BlueprintCallable)
		void SetItemSprite(FString id, UTexture2D* texture2D);
	UFUNCTION(BlueprintCallable)
		void SetItemSpriteFromPath(FString id, FString spritePath);
	UFUNCTION(BlueprintCallable)
		TArray<FSPItemRecipe> GetItemRecipes();
	UFUNCTION(BlueprintCallable)
		FSPBuildingDefinition GetBuildingDefinition(FString key);
	UFUNCTION(BlueprintCallable)
		FSPWindowLayout GetWindowLayout(FString window);*/

		//UFUNCTION(BlueprintCallable)
			//SPWorld& GetTutorialWorld();
};
