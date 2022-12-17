#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_FindRandomLocation.generated.h"

/**
 * Task znajduje lokacje w danym promieniu 
 */
UCLASS()
class SURVIVAL_API UBTTask_Skelly_FindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_Skelly_FindRandomLocation();

private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowPrivateAccess = true))
		float SearchRadius{ 500.f };
	
};
