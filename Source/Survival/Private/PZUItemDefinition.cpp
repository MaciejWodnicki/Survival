#include "PZUItemDefinition.h"

FPZUItemDefinition::FPZUItemDefinition()
{
	FPZUItemDefinition::FPZUItemDefinition("Item", 0, 1);
}
FPZUItemDefinition::FPZUItemDefinition(FString name, int value, float weight)
{
	this->name = name;
	this->value = value;
	this->weight = weight;
	this->maxQuantity = 1000;
}

FPZUItemDefinition::~FPZUItemDefinition()
{
}
FString FPZUItemDefinition::GetDataValue(FString key)
{
	return dataValues[key];
}
FPZUItemDefinition& FPZUItemDefinition::SetDataValue(FString key, FString v)
{
	dataValues.Add(key, v);
	return *this;
}
bool FPZUItemDefinition::ContainsDataKey(FString key)
{
	return dataValues.Contains(key);
}