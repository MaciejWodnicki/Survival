#pragma once

#include "CoreMinimal.h"

class SURVIVAL_API PZUTerrainModifier
{
public:
	virtual void Apply(TArray<FVector>& vertices) = 0;
};
class PZUTerrainModifierAttractionPoint : public PZUTerrainModifier
{
public:
	FVector origin;
	float radius;
	float attractionForce;

	PZUTerrainModifierAttractionPoint(FVector origin, float radius, float attractionForce);
	virtual void Apply(TArray<FVector>& vertices) override;
};