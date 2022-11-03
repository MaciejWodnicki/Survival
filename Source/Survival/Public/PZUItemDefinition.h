#pragma once

#include "CoreMinimal.h"
#include "PZUItemDefinition.generated.h"

USTRUCT(BlueprintType)
struct SURVIVAL_API FPZUItemDefinition
{
	GENERATED_BODY()

private:
	TMap<FString, FString> dataValues;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int value;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float weight;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* sprite = nullptr;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int maxQuantity;

	FPZUItemDefinition();
	FPZUItemDefinition(FString name, int value, float weight);
	~FPZUItemDefinition();
	FString GetDataValue(FString key);
	FPZUItemDefinition& SetDataValue(FString key, FString v = "");
	bool ContainsDataKey(FString key);
};
