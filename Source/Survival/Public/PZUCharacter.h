#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PZUCharacter.generated.h"

// struktura potrzeby gracza
struct Need
{
private:
	float fullnessMax;
	float fullness;
public:
	Need(float fullnessMax, float fullness)
	{
		this->fullnessMax = fullnessMax;
		this->fullness = fullness;
	}
	Need()
	{
		fullnessMax = 100;
		fullness = 100;
	}
	float GetFullness()
	{
		return fullness;
	}
	float GetFullnessMax()
	{
		return fullnessMax;
	}
	float GetFullnessPercentage()
	{
		return fullness / fullnessMax;
	}
	void SetFullness(float f)
	{
		this->fullness = f;
		if (this->fullness > fullnessMax)
			this->fullness = fullnessMax;
		else if (this->fullness < 0)
			this->fullness = 0;
	}
	void SetFullnessMax(float fMax)
	{
		fullnessMax = fMax;
		if (fullness > fullnessMax)
			fullness = fullnessMax;
	}
	/// <summary>
	/// Sets percentage of value.
	/// </summary>
	/// <param name="percentage">percentage of value (from 0 to 1)</param>
	void SetFullnessPercentage(float percentage)
	{
		SetFullness(fullnessMax * percentage);
	}
	void AddFullness(float toAdd)
	{
		SetFullness(GetFullness() + toAdd);
	}
};

UCLASS()
class SURVIVAL_API APZUCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APZUCharacter();

protected:
	virtual void BeginPlay() override;
	Need health;
	Need food;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float healthChange;
	float foodChange;

	UFUNCTION(BlueprintCallable)
		float GetHealth();
	UFUNCTION(BlueprintCallable)
		float GetHealthMax();
	UFUNCTION(BlueprintCallable)
		float GetHealthPercentage();
	UFUNCTION(BlueprintCallable)
		void AddHealth(float toAdd);

	UFUNCTION(BlueprintCallable)
		float GetFood();
	UFUNCTION(BlueprintCallable)
		float GetFoodMax();
	UFUNCTION(BlueprintCallable)
		float GetFoodPercentage();
	UFUNCTION(BlueprintCallable)
		void AddFood(float toAdd);
};