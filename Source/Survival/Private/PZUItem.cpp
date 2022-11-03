#include "PZUItem.h"

FPZUItem::FPZUItem()
{
	ID = "";
	quantity = 1;
}
FPZUItem& FPZUItem::SetInstance(FString _ID, int _quantity)
{
	FPZUItem* item = new FPZUItem();
	item->ID = _ID;
	item->quantity = _quantity;
	return *item;
}
FPZUItem& FPZUItem::None()
{
	return *new FPZUItem();
}