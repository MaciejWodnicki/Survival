#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PZUItem.generated.h"

USTRUCT(BlueprintType)
struct SURVIVAL_API FPZUItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString ID;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int quantity;

	FPZUItem();
	static FPZUItem& SetInstance(FString _ID, int _quantity = 1);
	static FPZUItem& None();
};
