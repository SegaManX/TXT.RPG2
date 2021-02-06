#include "allInclude.h"

int sItem[100]{};
int sItemMaxDurability[100]{};
int sItemDurability[100]{};
int sItemAmount[100]{};
int sItemEnchant[100]{};
int sItemLevel[100]{};
int sItemRequirement[100]{};
int sItemValue[100]{};
int itemsInStore{};

int generateItemSuffix()
{
	int waste{ rand() };
	int randomNum{ rand() % LastSuffixEnchant};
	return randomNum;
}

int generateItemDurability()
{
	int waste{ rand() };
	int randomNum{ rand() % (level * 5) + 1};
	return randomNum;
}

int generateItemLevel()
{
	int waste{ rand() };
	int randomNum{ rand() % level + 1 };
	return randomNum;
}

int generateItemReq()
{
	int waste{ rand() };
	int randomNum{ rand() % (level * 3) + 1 };
	return randomNum;
}

void generateItem(int itemType)
{
	switch (itemType)
	{
	case Sword:
	{
		sItem[itemsInStore] = Sword;
		sItemMaxDurability[itemsInStore] = generateItemDurability();
		sItemDurability[itemsInStore] = sItemMaxDurability[itemsInStore];
		sItemLevel[itemsInStore] = generateItemLevel();
		sItemRequirement[itemsInStore] = generateItemReq();
		sItemEnchant[itemsInStore] = generateItemSuffix();
		sItemAmount[itemsInStore] = 1;
		itemsInStore += 1;
		break;
	}
	case Bow:
	{
		sItem[itemsInStore] = Bow;
		sItemMaxDurability[itemsInStore] = generateItemDurability();
		sItemDurability[itemsInStore] = sItemMaxDurability[itemsInStore];
		sItemLevel[itemsInStore] = generateItemLevel();
		sItemRequirement[itemsInStore] = generateItemReq();
		sItemEnchant[itemsInStore] = generateItemSuffix();
		sItemAmount[itemsInStore] = 1;
		itemsInStore += 1;
		break;
	}
	case Staff:
	{
		sItem[itemsInStore] = Staff;
		sItemMaxDurability[itemsInStore] = generateItemDurability();
		sItemDurability[itemsInStore] = sItemMaxDurability[itemsInStore];
		sItemLevel[itemsInStore] = generateItemLevel();
		sItemRequirement[itemsInStore] = generateItemReq();
		sItemEnchant[itemsInStore] = generateItemSuffix();
		sItemAmount[itemsInStore] = 1;
		itemsInStore += 1;
		break;	
	}
	case Torch:
	{
		sItem[itemsInStore] = Torch;
		sItemMaxDurability[itemsInStore] = 10;
		sItemDurability[itemsInStore] = sItemMaxDurability[itemsInStore];
		sItemAmount[itemsInStore] = 1;
		sItemLevel[itemsInStore] = 1;
		sItemEnchant[itemsInStore] = NoSuffix;
		itemsInStore += 1;
		break;
	}
	default:
		break;
	}
}