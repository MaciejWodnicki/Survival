#pragma once

#include "CoreMinimal.h"
#include "PZUTerrainMaterial.h"
#include "PZUItemDefinition.h"
#include "PZUItem.h"
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

	UFUNCTION(BlueprintCallable)
		void Initialize();
	UFUNCTION(BlueprintCallable)
		FString GetGameVersion();
	TArray<FVector2D> GetUV(FString texture);

	UFUNCTION(BlueprintCallable)
		UTexture2D* GetTextureFromAssets(FString path);
};
