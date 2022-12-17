#include "skeletonEnemy/BTT_FindRandomLocation.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_Skelly_FindRandomLocation::UBTTask_Skelly_FindRandomLocation()
{
	NodeName = TEXT("Find Random Location");

	// przyjmuje tylko wektory
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_Skelly_FindRandomLocation, BlackboardKey));

}

EBTNodeResult::Type UBTTask_Skelly_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FNavLocation Location{};

	AAIController* AIController = OwnerComp.GetAIOwner();
	const APawn* AIPawn = AIController->GetPawn();

	// znajdz pozycje
	const FVector Origin = AIPawn->GetActorLocation();

	const UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());

	bool found = NavSystem->GetRandomPointInNavigableRadius(Origin, SearchRadius, Location);

	if (IsValid(NavSystem) && found)
	{
		
		AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName,
			Location.Location);
	}

	// wysyla sygnal o pozytywnym zakonczeniu zadania
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

FString UBTTask_Skelly_FindRandomLocation::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
}
