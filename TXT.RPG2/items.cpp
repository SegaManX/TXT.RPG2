#include "allInclude.h"

int itemCount{99};
int item[100]{};
int itemMaxDurability[100]{};
int itemDurability[100]{};
int itemAmount[100]{};
int itemEnchant[100]{};
int itemLevel[100]{};
int itemRequirement[100]{};
int itemsInInventory{};
int shownItems{};
bool itemShown[100]{};
int itemNum{1};
int potions[10]{};

std::string itemName[100]{"", "Sword","Bow","Staff", "Torch"};
int itemBuildReq[100]	 {0,  2,      3,    3,       1};
bool rangedWeapon[100]	 {0,  0,      1,    0,       0 };
bool magicWeapon[100]	 {0,  0,      0,    1,       0 };

int damageOutput()
{
	int damage{};
	double levelModif{};
	double skillModif{};
	int skillReq{};

	if (item[lastWeapon] == Sword)
	{
		levelModif = 0.1 * itemLevel[lastWeapon];
		
		if (itemRequirement[lastWeapon] == 0)
		{
			itemRequirement[lastWeapon] = 1;
		}

		skillReq = round((skillLevel[Swordsmanship] / itemRequirement[lastWeapon]));

		switch (skillReq)
		{
			case 1:
				skillModif = 1;
				break;
			case 2:
				skillModif = 2;
				break;
			case 3:
				skillModif = 5;
				break;
			case 4:
				skillModif = 7;
				break;
			case 5:
				skillModif = 10;
				break;
			default:
				skillModif = 10;
				break;
		}

		damage = 1 * levelModif + skillModif;
	}
	else if (item[lastWeapon] == Bow)
	{
		levelModif = 0.2 * itemLevel[lastWeapon];

		skillReq = round((skillLevel[Bowmanship] / itemRequirement[lastWeapon]));

		switch (skillReq)
		{
		case 1:
			skillModif = 1;
			break;
		case 2:
			skillModif = 2;
			break;
		case 3:
			skillModif = 5;
			break;
		case 4:
			skillModif = 7;
			break;
		case 5:
			skillModif = 10;
			break;
		default:
			skillModif = 10;
			break;
		}

		damage = 1 * levelModif + skillModif;
	}
	else if (item[lastWeapon] == Staff)
	{
		levelModif = 0.05 * itemLevel[lastWeapon];

		skillReq = round((skillLevel[Arcanum] / itemRequirement[lastWeapon]));

		switch (skillReq)
		{
		case 1:
			skillModif = 1;
			break;
		case 2:
			skillModif = 2;
			break;
		case 3:
			skillModif = 5;
			break;
		case 4:
			skillModif = 7;
			break;
		case 5:
			skillModif = 10;
			break;
		default:
			skillModif = 10;
			break;
		}

		damage = spellDamage[lastSpell] * levelModif + skillModif;
		
 	}
	else
	{
		damage = 1;
	}

	return damage;
}



void suffix(int itemEnchant)
{
	switch (itemEnchant)
	{
	case NoSuffix:
		std::cout << " ";
		break;
	case Fire:
		std::cout << " of Fire ";
		break;
	case Poison:
		std::cout << " of Poison ";
		break;
	case Ice:
		std::cout << " of Ice ";
		break;
	default:
		break;
	}
}

void sword()
{
	for (int i{}; i < itemCount; i++)
	{

		if (item[i] == 1 && skillLevel[Swordsmanship] >= itemRequirement[i])
		{
			std::cout << itemNum << " - ";
			itemNum += 1;
			if (i == lastWeapon)
			{
				std::cout << "E: ";
			}
			std::cout << itemAmount[i] << "x ";
			std::cout << "Level " << itemLevel[i] << " ";
			std::cout << "Sword";
			suffix(itemEnchant[i]);
			std::cout << "- Durability: " << itemDurability[i] << "/" << itemMaxDurability[i] << "\n";
			shownItems += 1;
			itemShown[i] = true;
		}
		
	}
}

void bow()
{
	for (int i{}; i < itemCount; i++)
	{
		if (item[i] == 2 && skillLevel[Bowmanship] >= itemRequirement[i])
		{
			std::cout << itemNum << " - ";
			itemNum += 1;
			if (i == lastWeapon)
			{
				std::cout << "E: ";
			}
			std::cout << itemAmount[i] << "x ";
			std::cout << "Level " << itemLevel[i] << " ";
			std::cout << "Bow";
			suffix(itemEnchant[i]);
			std::cout << "- Durability: " << itemDurability[i] << "/" << itemMaxDurability[i] << "\n";
			shownItems += 1;
			itemShown[i] = true;

		}
	}
}

void staff()
{
	for (int i{}; i < itemCount; i++)
	{
		if (item[i] == 3 && skillLevel[Arcanum] >= itemRequirement[i])
		{
			std::cout << itemNum << " - ";
			itemNum += 1;
			if (i == lastWeapon)
			{
				std::cout << "E: ";
			}
			std::cout << itemAmount[i] << "x ";
			std::cout << "Level " << itemLevel[i] << " ";
			std::cout << "Staff";
			suffix(itemEnchant[i]);
			std::cout << "- Durability: " << itemDurability[i] << "/" << itemMaxDurability[i] << "\n";
			shownItems += 1;
			itemShown[i] = true;

		}
	}
}

void torch()
{
	for (int i{}; i < itemCount; i++)
	{
		if (item[i] == 4)
		{
			std::cout << itemNum << " - ";
			itemNum += 1;
			if (i == lastWeapon)
			{
				std::cout << "E: ";
			}
			std::cout << itemAmount[i] << "x ";
			std::cout << "Torch";
			std::cout << " - Durability: " << itemDurability[i] << "/" << itemMaxDurability[i] << "\n";
			shownItems += 1;
			itemShown[i] = true;

		}
	}
}

void utilityItems()
{
	std::cout << "\nUtility Items: \n\n";
	torch();
}

void combatItems()
{
	shownItems = 0;
	for (int i : itemShown)
	{
		i = false;
	}
	itemNum = 1;
	std::cout << "\nCombat Items: \n\n";
	sword();
	bow();
	staff();
}

void allItems()
{
	combatItems(); // always has to be first
	utilityItems();
}