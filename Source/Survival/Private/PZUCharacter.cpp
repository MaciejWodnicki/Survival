#include "PZUCharacter.h"

APZUCharacter::APZUCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	food.SetFullnessMax(200);
	food.SetFullnessPercentage(0.9);
	stamina.SetFullnessMax(50);
	stamina.SetFullnessPercentage(1);
	bliss.SetFullnessMax(400);
	bliss.SetFullness(0);


	stamina.SetFullnessPercentage(0.1);
	bliss.SetFullnessPercentage(0.6);
}

void APZUCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APZUCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	vigorChange = 0;
	foodChange = -0.1;
	staminaChange = 0;

	if (vigor.GetFullnessPercentage() < 1)
	{
		vigorChange += 0.01;
		foodChange += -0.01;
		if (vigor.GetFullnessPercentage() < 0.75)
		{
			vigorChange += 0.015;
			foodChange += -0.015;
			if (vigor.GetFullnessPercentage() < 0.5)
			{
				vigorChange += 0.025;
				foodChange += -0.025;
				if (vigor.GetFullnessPercentage() < 0.25)
				{
					vigorChange += 0.05;
					foodChange += -0.05;
				}
			}
		}
	}

	if (stamina.GetFullnessPercentage() < 1)
	{
		staminaChange += 0.01;
		foodChange += -0.01;
		if (stamina.GetFullnessPercentage() < 0.75)
		{
			staminaChange += 0.015;
			foodChange += -0.015;
			if (stamina.GetFullnessPercentage() < 0.5)
			{
				staminaChange += 0.025;
				foodChange += -0.025;
				if (stamina.GetFullnessPercentage() < 0.25)
				{
					staminaChange += 0.05;
					foodChange += -0.05;
				}
			}
		}
	}
	vigor.AddFullness(DeltaTime * vigorChange);
	food.AddFullness(DeltaTime * foodChange);
	stamina.AddFullness(DeltaTime * staminaChange);
}

void APZUCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float APZUCharacter::GetVigor()
{
	return vigor.GetFullness();
}
float APZUCharacter::GetVigorMax()
{
	return vigor.GetFullnessMax();
}
float APZUCharacter::GetVigorPercentage()
{
	return vigor.GetFullnessPercentage();
}
void APZUCharacter::AddVigor(float toAdd)
{
	vigor.AddFullness(toAdd);
}

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

float APZUCharacter::GetStamina()
{
	return stamina.GetFullness();
}
float APZUCharacter::GetStaminaMax()
{
	return stamina.GetFullnessMax();
}
float APZUCharacter::GetStaminaPercentage()
{
	return stamina.GetFullnessPercentage();
}
void APZUCharacter::AddStamina(float toAdd)
{
	stamina.AddFullness(toAdd);
}

float APZUCharacter::GetBliss()
{
	return bliss.GetFullness();
}
float APZUCharacter::GetBlissMax()
{
	return bliss.GetFullnessMax();
}
float APZUCharacter::GetBlissPercentage()
{
	return bliss.GetFullnessPercentage();
}
void APZUCharacter::AddBliss(float toAdd)
{
	bliss.AddFullness(toAdd);
}