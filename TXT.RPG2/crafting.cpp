#include "allInclude.h"

int itemValueOutput(int valuableItem, bool shop)
{
	int value{};
	int enchantValue{};
	double durabilityModif{};

	if (shop)
	{
		switch (sItemEnchant[valuableItem])
		{
		case NoSuffix:
			enchantValue = 1;
			break;
		case Fire:
			enchantValue = 3;
			break;
		case Poison:
			enchantValue = 2;
			break;
		default:
			break;
		}

		if (sItemDurability[valuableItem] >= sItemMaxDurability[valuableItem])
		{
			durabilityModif = 1.5;
		}
		else if (sItemDurability[valuableItem] >= sItemMaxDurability[valuableItem] * 0.9)
		{
			durabilityModif = 1;
		}
		else if (sItemDurability[valuableItem] >= sItemMaxDurability[valuableItem] * 0.8)
		{
			durabilityModif = 0.9;
		}
		else if (sItemDurability[valuableItem] >= sItemMaxDurability[valuableItem] * 0.7)
		{
			durabilityModif = 0.8;
		}
		else if (sItemDurability[valuableItem] >= sItemMaxDurability[valuableItem] * 0.6)
		{
			durabilityModif = 0.7;
		}
		else if (sItemDurability[valuableItem] >= sItemMaxDurability[valuableItem] * 0.5)
		{
			durabilityModif = 0.6;
		}
		else if (sItemDurability[valuableItem] >= sItemMaxDurability[valuableItem] * 0.4)
		{
			durabilityModif = 0.5;
		}
		else if (sItemDurability[valuableItem] >= sItemMaxDurability[valuableItem] * 0.3)
		{
			durabilityModif = 0.4;
		}
		else if (sItemDurability[valuableItem] >= sItemMaxDurability[valuableItem] * 0.2)
		{
			durabilityModif = 0.3;
		}
		else if (sItemDurability[valuableItem] >= sItemMaxDurability[valuableItem] * 0.1)
		{
			durabilityModif = 0.2;
		}
		else if (sItemDurability[valuableItem] >= 0)
		{
			durabilityModif = 0.1;
		}

		value = round(enchantValue * sItemLevel[valuableItem] * durabilityModif);
	}
	else
	{
		switch (itemEnchant[valuableItem])
		{
		case NoSuffix:
			enchantValue = 1;
			break;
		case Fire:
			enchantValue = 3;
			break;
		case Poison:
			enchantValue = 2;
			break;
		default:
			break;
		}

		if (itemDurability[valuableItem] >= itemMaxDurability[valuableItem])
		{
			durabilityModif = 1.5;
		}
		else if (itemDurability[valuableItem] >= itemMaxDurability[valuableItem] * 0.9)
		{
			durabilityModif = 1;
		}
		else if (itemDurability[valuableItem] >= itemMaxDurability[valuableItem] * 0.8)
		{
			durabilityModif = 0.9;
		}
		else if (itemDurability[valuableItem] >= itemMaxDurability[valuableItem] * 0.7)
		{
			durabilityModif = 0.8;
		}
		else if (itemDurability[valuableItem] >= itemMaxDurability[valuableItem] * 0.6)
		{
			durabilityModif = 0.7;
		}
		else if (itemDurability[valuableItem] >= itemMaxDurability[valuableItem] * 0.5)
		{
			durabilityModif = 0.6;
		}
		else if (itemDurability[valuableItem] >= itemMaxDurability[valuableItem] * 0.4)
		{
			durabilityModif = 0.5;
		}
		else if (itemDurability[valuableItem] >= itemMaxDurability[valuableItem] * 0.3)
		{
			durabilityModif = 0.4;
		}
		else if (itemDurability[valuableItem] >= itemMaxDurability[valuableItem] * 0.2)
		{
			durabilityModif = 0.3;
		}
		else if (itemDurability[valuableItem] >= itemMaxDurability[valuableItem] * 0.1)
		{
			durabilityModif = 0.2;
		}
		else if (itemDurability[valuableItem] >= 0)
		{
			durabilityModif = 0.1;
		}

		value = round(enchantValue * itemLevel[valuableItem] * durabilityModif);
	}
	return value;
}

void craftGear(int craftItem, int material)
{
	if (resources[material] >= itemBuildReq[craftItem])
	{
		resources[material] -= itemBuildReq[craftItem];
		item[itemsInInventory] = craftItem;
		
		itemMaxDurability[itemsInInventory] = skillLevel[Toolsmanship] * 5;
		itemDurability[itemsInInventory] = itemMaxDurability[itemsInInventory];
		itemRequirement[itemsInInventory] = skillLevel[Toolsmanship];
		itemLevel[itemsInInventory] = stats[Intelligence];
		itemAmount[itemsInInventory] = 1;

		itemsInInventory += 1;
	}
	location = CraftGear;
}

void meltOre(int ore)
{
	if (resources[ore] >= 5)
	{
		resources[ore] -= 5;
		resources[ore + 1] += 1;

		int xpPlus = 100;

		skillTotalXP[Smithing] += xpPlus;
		skillXP[Smithing] += xpPlus;
		expirience += xpPlus;
		totalEXP += xpPlus;
	}
	location = MeltOre;
}

void makeAlloys(int alloy)
{
	switch (alloy)
	{
	case Steel:
	{
		if (resources[Iron] >= 3)
		{
			resources[Iron] -= 3;
			resources[Steel] += 1;

			int xpPlus = 150;

			skillTotalXP[Smithing] += xpPlus;
			skillXP[Smithing] += xpPlus;
			expirience += xpPlus;
			totalEXP += xpPlus;
		}
		break;
	}
	default:
		break;
	}

	location = MakeAlloys;
}

void repairGear(int repairItem)
{
	int itemType = item[repairItem];
	int repairCost = itemBuildReq[itemType] * 0.5;

	if (resources[Gold] >= repairCost)
	{
		resources[Gold] -= repairCost;
		itemDurability[repairItem] = itemMaxDurability[repairItem];
	}

	location = RepairGear;
}