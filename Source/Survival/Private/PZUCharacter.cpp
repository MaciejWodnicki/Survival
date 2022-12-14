#include "PZUCharacter.h"

APZUCharacter::APZUCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	// nadanie maksymalnej wartosci najedzenia
	food.SetFullnessMax(200);
	// nadanie procentowego wypelnienia najedzenia
	food.SetFullnessPercentage(0.9);
}

void APZUCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APZUCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// potrzeby gracza: zdrowie i najedzenie
	healthChange = 0;
	foodChange = -0.1;

	// mechanika regeneracji zdrowia
	if (health.GetFullnessPercentage() < 1)
	{
		healthChange += 0.01;
		foodChange += -0.01;
		if (health.GetFullnessPercentage() < 0.75)
		{
			healthChange += 0.015;
			foodChange += -0.015;
			if (health.GetFullnessPercentage() < 0.5)
			{
				healthChange += 0.025;
				foodChange += -0.025;
				if (health.GetFullnessPercentage() < 0.25)
				{
					healthChange += 0.05;
					foodChange += -0.05;
				}
			}
		}
	}

	// nadanie aktualnej wartosci zdrowia i najedzenia
	health.AddFullness(DeltaTime * healthChange);
	food.AddFullness(DeltaTime * foodChange);
}

void APZUCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// metody odpowiedzialne za zdrowie...
float APZUCharacter::GetHealth()
{
	return health.GetFullness();
}
float APZUCharacter::GetHealthMax()
{
	return health.GetFullnessMax();
}
float APZUCharacter::GetHealthPercentage()
{
	return health.GetFullnessPercentage();
}
void APZUCharacter::AddHealth(float toAdd)
{
	health.AddFullness(toAdd);
}

// ...i najedzenie
float APZUCharacter::GetFood()
{
	return food.GetFullness();
}
float APZUCharacter::GetFoodMax()
{
	return food.GetFullnessMax();
}
float APZUCharacter::GetFoodPercentage()
{
	return food.GetFullnessPercentage();
}
void APZUCharacter::AddFood(float toAdd)
{
	food.AddFullness(toAdd);
}