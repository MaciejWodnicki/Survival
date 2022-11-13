#include "PZUTerrainModifier.h"

PZUTerrainModifierAttractionPoint::PZUTerrainModifierAttractionPoint(FVector origin, float radius, float attractionForce)
{
	this->origin = origin;
	this->radius = radius;
	this->attractionForce = attractionForce;
}
void PZUTerrainModifierAttractionPoint::Apply(TArray<FVector>& vertices)
{
	for (auto& v : vertices)
	{
		if (FVector::Dist(origin, v) <= radius)
		{
			FVector direction = origin - v;
			direction.Normalize();
			v += direction * attractionForce;
		}
	}
}