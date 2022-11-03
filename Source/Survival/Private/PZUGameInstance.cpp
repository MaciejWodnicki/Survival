#include "PZUGameInstance.h"
#include <Runtime/Engine/Public/ImageUtils.h>

void UPZUGameInstance::Initialize()
{
	// TEXTURE ATLAS
	UVAtlas.Add("dirt", TArray<FVector2d>{FVector2d(0, 0), FVector2d(0.25, 0.25)});
	UVAtlas.Add("grass_side", TArray<FVector2d>{FVector2d(0.25, 0), FVector2d(0.5, 0.25)});
	UVAtlas.Add("grass", TArray<FVector2d>{FVector2d(0.5, 0), FVector2d(0.75, 0.25)});
	UVAtlas.Add("stone", TArray<FVector2d>{FVector2d(0.75, 0), FVector2d(1, 0.25)});
	UVAtlas.Add("wood_log_side", TArray<FVector2d>{FVector2d(0, 0.25), FVector2d(0.25, 0.5)});
	UVAtlas.Add("wood_log", TArray<FVector2d>{FVector2d(0.25, 0.25), FVector2d(0.5, 0.5)});
	UVAtlas.Add("leaves", TArray<FVector2d>{FVector2d(0.5, 0.25), FVector2d(0.75, 0.5)});
	UVAtlas.Add("wood_planks", TArray<FVector2d>{FVector2d(0.75, 0.25), FVector2d(1, 0.5)});
	UVAtlas.Add("alder_log", TArray<FVector2d>{FVector2d(0, 0.5), FVector2d(0.25, 0.75)});
	UVAtlas.Add("alder_log_side", TArray<FVector2d>{FVector2d(0.25, 0.5), FVector2d(0.5, 0.75)});
	UVAtlas.Add("iron_plate", TArray<FVector2d>{FVector2d(0.5, 0.5), FVector2d(0.75, 0.75)});
	UVAtlas.Add("hazard_block", TArray<FVector2d>{FVector2d(0.75, 0.5), FVector2d(1, 0.75)});
	UVAtlas.Add("concrete", TArray<FVector2d>{FVector2d(0, 0.75), FVector2d(0.25, 1)});
	UVAtlas.Add("concrete_tiled", TArray<FVector2d>{FVector2d(0.25, 0.75), FVector2d(0.5, 1)});
	UVAtlas.Add("bricks", TArray<FVector2d>{FVector2d(0.5, 0.75), FVector2d(0.75, 1)});
	UVAtlas.Add("sand", TArray<FVector2d>{FVector2d(0.75, 0.75), FVector2d(1, 1)});

	// BLOCKS
	blockDefinitions.Add("dirt", PZUTerrainMaterial("Dirt", 2));
	blockDefinitions["dirt"].SetTextureAll("dirt");

	blockDefinitions.Add("grass", PZUTerrainMaterial("Grass", 3));
	blockDefinitions["grass"].SetTextureSides("grass_side");
	blockDefinitions["grass"].textureTop = "grass";
	blockDefinitions["grass"].textureBottom = "dirt";

	blockDefinitions.Add("stone", PZUTerrainMaterial("Stone", 2));
	blockDefinitions["stone"].SetTextureAll("stone");

	blockDefinitions.Add("wood_log", PZUTerrainMaterial("Wood Log", 3));
	blockDefinitions["wood_log"].SetTextureSides("wood_log_side");
	blockDefinitions["wood_log"].textureTop = "wood_log";
	blockDefinitions["wood_log"].textureBottom = "wood_log";

	blockDefinitions.Add("leaves", PZUTerrainMaterial("Leaves", 2));
	blockDefinitions["leaves"].SetTextureAll("leaves");

	blockDefinitions.Add("wood_planks", PZUTerrainMaterial("Wood Planks", 2));
	blockDefinitions["wood_planks"].SetTextureAll("wood_planks");

	blockDefinitions.Add("alder_log", PZUTerrainMaterial("Wood Log", 3));
	blockDefinitions["alder_log"].SetTextureSides("alder_log_side");
	blockDefinitions["alder_log"].textureTop = "alder_log";
	blockDefinitions["alder_log"].textureBottom = "alder_log";

	blockDefinitions.Add("iron_plate", SPTerrainMaterial("Wood Planks", 2));
	blockDefinitions["iron_plate"].SetTextureAll("iron_plate");

	blockDefinitions.Add("hazard_block", SPTerrainMaterial("Wood Planks", 2));
	blockDefinitions["hazard_block"].SetTextureAll("hazard_block");

	blockDefinitions.Add("concrete", SPTerrainMaterial("Concrete", 2));
	blockDefinitions["concrete"].SetTextureAll("concrete");

	blockDefinitions.Add("concrete_tiled", SPTerrainMaterial("Tield Concrete", 2));
	blockDefinitions["concrete_tiled"].SetTextureAll("concrete_tiled");

	blockDefinitions.Add("bricks", SPTerrainMaterial("Bricks", 2));
	blockDefinitions["bricks"].SetTextureAll("bricks");

	blockDefinitions.Add("sand", SPTerrainMaterial("Sand", 1));
	blockDefinitions["sand"].SetTextureAll("sand");

	// ITEMS
	/*itemDefinitions.Add("undefined", FSPItemDefinition("Undefined", 69, 1));
	itemDefinitions["undefined"]
		.SetDataValue("mesh", "/Game/Items/SM_Item_Undefined")
		.SetDataValue("HIDDEN");
	itemDefinitions.Add("REMOVE", FSPItemDefinition("", 0, 1));
	itemDefinitions["REMOVE"]
		.SetDataValue("mesh", "/Game/Items/SM_Item_Undefined")
		.SetDataValue("HIDDEN");

	itemDefinitions.Add("archway_lock", FSPItemDefinition("Archway Lock", 1, 0.5));
	itemDefinitions["archway_lock"]
		.SetDataValue("mesh", "/Game/Items/Archway_Portal/SM_Archway_Lock");

	itemDefinitions.Add("archway_key", FSPItemDefinition("Archway Key", 1, 0.5));
	itemDefinitions["archway_key"]
		.SetDataValue("mesh", "/Game/Items/Archway_Portal/SM_Archway_Key");

	itemDefinitions.Add("coin", FSPItemDefinition("1 Dollar Coin", 1, 0.01));
	itemDefinitions["coin"]
		.SetDataValue("mesh", "/Game/Items/1DollarCoin/SM_1Dollar_Coin")
		.SetDataValue("class", "currency");

	itemDefinitions.Add("money", FSPItemDefinition("100 Dollar Money", 1, 0.1));
	itemDefinitions["money"]
		.SetDataValue("mesh", "/Game/Items/100DollarMoney/SM_100Dollar_Money")
		.SetDataValue("class", "currency");

	itemDefinitions.Add("axe", FSPItemDefinition("Axe", 1, 0.5));
	itemDefinitions["axe"]
		.SetDataValue("mesh", "/Game/Items/Axe/SM_Axe")
		.SetDataValue("class", "tool")
		.SetDataValue("axe", "100");

	itemDefinitions.Add("stone", FSPItemDefinition("Stone", 1, 1));
	itemDefinitions["stone"]
		.SetDataValue("mesh", "/Game/Items/Stone/SM_Stone");

	itemDefinitions.Add("wood", FSPItemDefinition("Wood", 5, 0.75));
	itemDefinitions["wood"]
		.SetDataValue("mesh", "/Game/Items/WoodLog/SM_WoodLog");

	itemDefinitions.Add("book", FSPItemDefinition("Book", 1, 0.03));
	itemDefinitions["book"]
		.SetDataValue("mesh", "/Game/Items/Book/SM_Book");

	itemDefinitions.Add("blueprint", FSPItemDefinition("Blueprint", 1, 0.02));
	itemDefinitions["blueprint"]
		.SetDataValue("mesh", "/Game/Items/Blueprint/SM_Blueprint");

	itemDefinitions.Add("steak_raw", FSPItemDefinition("Raw Steak", 1, 0.1));
	itemDefinitions["steak_raw"]
		.SetDataValue("mesh", "/Game/Items/SteakRaw/SM_Steak_Raw")
		.SetDataValue("class", "food")
		.SetDataValue("food", "25");

	itemDefinitions.Add("luvdevice_light_housing", FSPItemDefinition("LuvDevice Housing: Light", 1, 0.1));
	itemDefinitions["luvdevice_light_housing"]
		.SetDataValue("mesh", "/Game/Items/LuvDevices/LuvGuns/Light_LuvGun/LuvGun_Light_Housing");

	itemDefinitions.Add("luvdevice_light_core", FSPItemDefinition("LuvDevice Core: Light", 1, 0.1));
	itemDefinitions["luvdevice_light_core"]
		.SetDataValue("mesh", "/Game/Items/LuvDevices/LuvGuns/Light_LuvGun/LuvGun_Light_Core");

	itemDefinitions.Add("luvdevice_light_emitter", FSPItemDefinition("LuvDevice Emitter: Light", 1, 0.1));
	itemDefinitions["luvdevice_light_emitter"]
		.SetDataValue("mesh", "/Game/Items/LuvDevices/LuvGuns/Light_LuvGun/LuvGun_Light_Emitter");

	itemDefinitions.Add("luvdevice_light_memory_card", FSPItemDefinition("LuvDevice Memory Card: Light", 1, 0.1));
	itemDefinitions["luvdevice_light_memory_card"]
		.SetDataValue("mesh", "/Game/Items/LuvDevices/LuvGuns/Light_LuvGun/LuvGun_Light_MemoryCard");*/

	// ITEM RECIPES
	/*itemRecipes.Add
	(
		FSPItemRecipe("crafting_hands")
		.AddIngredient("0", FSPItem::SetInstance("wood"))
		.AddIngredient("1", FSPItem::SetInstance("stone"))
		.AddProduct("3", FSPItem::SetInstance("axe"))
	);*/

	// BUILDINGS
	/*buildingDefinitions.Add("tree_alder", FSPBuildingDefinition("Alder Tree", 1, 250, FVector(50, 50, 400), 25)
		.SetDataValue("mesh", "/Game/Buildings/Tree/SM_Tree")
		.AddDeconstructionResources(FSPItem::SetInstance("wood", 2))
	);
	buildingDefinitions.Add("bush_raspberry", FSPBuildingDefinition("Raspberry Bush", 1, 150, FVector(100, 100, 150), 25)
		.SetDataValue("mesh", "/Game/Buildings/Raspberries/SM_RaspberryBush")
	);
	buildingDefinitions.Add("fireplace", FSPBuildingDefinition("Fireplace", 1, 150, FVector(100, 100, 25), 10)
		.SetDataValue("mesh", "/Game/Buildings/Fireplace/SM_Fireplace")
	);
	buildingDefinitions.Add("workbench_carpenters", FSPBuildingDefinition("Carpenter's Workbench", 1, 150, FVector(200, 100, 100), 5)
		.SetDataValue("mesh", "/Game/Buildings/Carpenters_Workbench/SM_CarpentersWorkbench")
	);
	buildingDefinitions.Add("workbench_luvgun", FSPBuildingDefinition("LuvGun Assembler", 1, 150, FVector(50, 50, 100), 25)
		.SetDataValue("mesh", "/Game/Buildings/LuvDeviceAssembler/SM_LuvDeviceAssembler_Base")
	);*/

	// WINDOW LAYOUTS
	/*windowLayouts.Add
	(
		"crafting_hands",
		FSPWindowLayout("Crafting", false)
		.AddElement(FSPWindowLayoutElement("image", FVector2D(-168, 304), "/Game/Blueprints/Widgets/Fonts/T_Crafting_Input"))
		.AddElement(FSPWindowLayoutElement("slot", FVector2D(-168, 16), "0"))
		.AddElement(FSPWindowLayoutElement("slot", FVector2D(-240, 160), "1"))
		.AddElement(FSPWindowLayoutElement("slot", FVector2D(-96, 160), "2"))
		.AddElement(FSPWindowLayoutElement("image", FVector2D(168, 304), "/Game/Blueprints/Widgets/Fonts/T_Crafting_Output"))
		.AddElement(FSPWindowLayoutElement("slot", FVector2D(168, 16), "3", "output"))
		.AddElement(FSPWindowLayoutElement("slot", FVector2D(96, 160), "4", "output"))
		.AddElement(FSPWindowLayoutElement("slot", FVector2D(240, 160), "5", "output"))
		.AddElement(FSPWindowLayoutElement("button", FVector2D(0, 16), "activate", "Craft"))
	);*/
}
FString UPZUGameInstance::GetGameVersion()
{
	return GAME_VERSION;
}
TArray<FVector2D> UPZUGameInstance::GetUV(FString texture)
{
	return UVAtlas[texture];
}

UTexture2D* UPZUGameInstance::GetTextureFromAssets(FString path)
{
	return Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *path));
}

/*TArray<FString> USPGameInstance::GetCraftingList(FString stationID, FString searchData)
{
	TArray<FString> list;
	TArray<FString> rawList;
	itemDefinitions.GenerateKeyArray(rawList);
	for (auto& i : rawList)
	{
		if (!itemDefinitions[i].ContainsDataKey("HIDDEN") && (searchData.Len() == 0 || i.Contains(searchData)))
		{
			list.Add(i);
		}
	}
	return list;
}
FSPItemDefinition USPGameInstance::GetItemDefinition(FString id)
{
	return itemDefinitions[id];
}
TArray<FString> USPGameInstance::GetItemDefinitionList()
{
	TArray<FString> keys;
	itemDefinitions.GetKeys(keys);
	return keys;
}
UStaticMesh* USPGameInstance::GetItemMesh(FString path)
{
	return Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *path));
}
FString USPGameInstance::GetItemData(FString id, FString key)
{
	if (itemDefinitions[id].ContainsDataKey(key))
		return itemDefinitions[id].GetDataValue(key);
	else
		return "";
}
FString USPGameInstance::GetBuildingData(FString id, FString key)
{
	if (buildingDefinitions[id].ContainsDataKey(key))
		return buildingDefinitions[id].GetDataValue(key);
	else
		return "";
}
void USPGameInstance::SetItemSprite(FString id, UTexture2D* texture2D)
{
	FSPItemDefinition* def = &itemDefinitions[id];
	def->sprite = texture2D;
}
void USPGameInstance::SetItemSpriteFromPath(FString id, FString spritePath)
{
	itemDefinitions[id].sprite = FImageUtils::ImportFileAsTexture2D(spritePath); // Zbagowane na maksa ;-;
}
TArray<FSPItemRecipe> USPGameInstance::GetItemRecipes()
{
	return itemRecipes;
}
FSPBuildingDefinition USPGameInstance::GetBuildingDefinition(FString key)
{
	return buildingDefinitions[key];
}
FSPWindowLayout USPGameInstance::GetWindowLayout(FString window)
{
	return windowLayouts[window];
}*/
/*SPWorld& USPGameInstance::GetTutorialWorld()
{
	return SPWorld::TutorialWorld();
}*/