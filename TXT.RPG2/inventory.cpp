#include "allInclude.h"

int resources[7]{};

void statScreen()
{
	AgainStats:
	std::system("cls");
	std::cout << "Unused statpoints: " << statPoint << "\n\n";
	int i{};
	for (int value : stats)
	{
		switch (i)
		{
		case MaxHp:
			std::cout << "1. - Hp: " << stats[MaxHp] / 5 << '\n';
			break;
		case MaxStamina:
			std::cout << "2. - Stamina: " << stats[MaxStamina] / 5 << '\n';
			break;
		case Strength:
			std::cout << "3. - Strength: " << stats[Strength] << '\n';
			break;
		case Defence:
			std::cout << "4. - Defence: " << stats[Defence] << '\n';
			break;
		case Agility:
			std::cout << "5. - Agility: " << stats[Agility] << '\n';
			break;
		case Perception:
			std::cout << "6. - Perception: " << stats[Perception] << '\n';
			break;
		case Intelligence:
			std::cout << "7. - Intelligence: " << stats[Intelligence] << '\n';
			break;
		case Charisma:
			std::cout << "8. - Charisma: " << stats[Charisma] << '\n';
			break;

		default:
			break;
		}
		i++;
	}
	std::cout << "\n";
	if (statPoint > 0)
	{
		std::cout << "0 - Back\n1 - 8 - Upgrade Stat\n-1 - -8 Downgrade Stat\n";

		
		int x{};
		std::cin >> x;
		if (x > 0 && x < 9)
		{
			statPoint -= 1;
			switch (x)
			{
				case 1:
					stats[MaxHp] += 5;
					stats[Hp] += 5;
					break;
				case 2:
					stats[MaxStamina] += 5;
					stats[Stamina] += 5;
					break;
				case 3:
					stats[Strength] += 1;
					break;
				case 4:
					stats[Defence] += 1;
					break;
				case 5:
					stats[Agility] += 1;
					break;
				case 6:
					stats[Perception] += 1;
					break;
				case 7:
					stats[Intelligence] += 1;
					break;
				case 8:
					stats[Charisma] += 1;
					break;
				default:
					break;
			}

			location = StatScreen;
		}
		else if (x < 0 && x > -9)
		{
			switch (x)
			{
			case -1:
				if (stats[MaxHp] > 5 && statLockLevel[MaxHp] > stats[MaxHp])
				{
					stats[MaxHp] -= 5;
					stats[Hp] -= 5;
					statPoint += 1;
				}
				break;
			case -2:
				if (stats[MaxStamina] > 5 && statLockLevel[MaxStamina] > stats[MaxStamina])
				{
					stats[MaxStamina] -= 5;
					stats[Stamina] -= 5;
					statPoint += 1;
				}
				break;
			case -3:
				if (stats[Strength] > 1 && statLockLevel[Strength] > stats[Strength])
				{
					stats[Strength] -= 1;
					statPoint += 1;
				}
				break;
			case -4:
				if (stats[Defence] > 1 && statLockLevel[Defence] > stats[Defence])
				{
					stats[Defence] -= 1;
					statPoint += 1;
				}
				break;
			case -5:
				if (stats[Agility] > 1 && statLockLevel[Agility] > stats[Agility])
				{
					stats[Agility] -= 1;
					statPoint += 1;
				}
				break;
			case -6:
				if (stats[Perception] > 1 && statLockLevel[Perception] > stats[Perception])
				{
					stats[Perception] -= 1;
					statPoint += 1;
				}
				break;
			case -7:
				if (stats[Intelligence] > 1 && statLockLevel[Intelligence] > stats[Intelligence])
				{
					stats[Intelligence] -= 1;
					statPoint += 1;
				}
				break;
			case -8:
				if (stats[Charisma] > 1 && statLockLevel[Charisma] > stats[Charisma])
				{
					stats[Charisma] -= 1;
					statPoint += 1;
				}
				break;
			default:
				break;
			}

			location = StatScreen;
		}
		else if (x == 0)
		{
			location = Backpack;
			lockStats();
		}
		else
		{
			goto AgainStats;
		}
	}
	else
	{
		std::cout << "0 - Back\n-1 - -8 Downgrade Stat\n";

		int x{};
		std::cin >> x;
		if (x < 0 && x > -9)
		{
			switch (x)
			{
			case -1:
				if (stats[MaxHp] > 5 && statLockLevel[MaxHp] > stats[MaxHp])
				{
					stats[MaxHp] -= 5;
					stats[Hp] -= 5;
					statPoint += 1;
				}
				break;
			case -2:
				if (stats[MaxStamina] > 5 && statLockLevel[MaxStamina] > stats[MaxStamina])
				{
					stats[MaxStamina] -= 5;
					stats[Stamina] -= 5;
					statPoint += 1;
				}
				break;
			case -3:
				if (stats[Strength] > 1 && statLockLevel[Strength] > stats[Strength])
				{
					stats[Strength] -= 1;
					statPoint += 1;
				}
				break;
			case -4:
				if (stats[Defence] > 1 && statLockLevel[Defence] > stats[Defence])
				{
					stats[Defence] -= 1;
					statPoint += 1;
				}
				break;
			case -5:
				if (stats[Agility] > 1 && statLockLevel[Agility] > stats[Agility])
				{
					stats[Agility] -= 1;
					statPoint += 1;
				}
				break;
			case -6:
				if (stats[Perception] > 1 && statLockLevel[Perception] > stats[Perception])
				{
					stats[Perception] -= 1;
					statPoint += 1;
				}
				break;
			case -7:
				if (stats[Intelligence] > 1 && statLockLevel[Intelligence] > stats[Intelligence])
				{
					stats[Intelligence] -= 1;
					statPoint += 1;
				}
				break;
			case -8:
				if (stats[Charisma] > 1 && statLockLevel[Charisma] > stats[Charisma])
				{
					stats[Charisma] -= 1;
					statPoint += 1;
				}
				break;
			default:
				break;
			}

			location = StatScreen;
		}
		else if (x == 0)
		{
			location = Backpack;
			lockStats();
		}
		else
		{
			goto AgainStats;
		}
	}
}

void skillScreen()
{
	std::system("cls");
	std::cout << "Unused skillpoints: " << skillPoint << "\n\n";
	int i{};
	for (int us : skillLevel)
	{
		switch (i)
		{
		case Swordsmanship:
			std::cout << "1. - Swordsmanship: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Bowmanship:
			std::cout << "2. - Bowmanship: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Arcanum:
			std::cout << "3. - Arcanum: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Wood_cutting:
			std::cout << "4. - Wood-cutting: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Mining:
			std::cout << "5. - Mining: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Foraging:
			std::cout << "6. - Foraging: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Hunting:
			std::cout << "7. - Hunting: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Smithing:
			std::cout << "8. - Smithing: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Brewing:
			std::cout << "9. - Brewing: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Toolsmanship:
			std::cout << "10. - Toolsmanship: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Stealth:
			std::cout << "11. - Stealth: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Medicine:
			std::cout << "12. - Medicine: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;
		case Lockpicking:
			std::cout << "13. - Lockpicking: " << skillLevel[i] << " - " << skillXP[i] << "/" << skillXPToNextLevel[i] << '\n';
			break;

		default:
			break;
		}
		i++;
	}
	std::cout << "\n";
	if (skillPoint > 0)
	{
		std::cout << "0 - Back\n1 - 13 - Upgrade Skill\n-1 - -13 - Downgrade Skill\n\n";

		int x{};
		std::cin >> x;
		if (x > 0 && x < 14)
		{
			skillPoint -= 1;
			skillLevel[x - 1] += 1;

			location = SkillScreen;
		}
		else if (x < 0 && x > -14)
		{
			if (skillLevel[x *-1 - 1] > 0 && skillLockLevel[x * -1 - 1] > skillLevel[x * -1 - 1])
			{
				skillPoint += 1;
				skillLevel[x *-1 - 1] -= 1;
			}
			location = SkillScreen;
		}
		else if (x == 0)
		{
			location = Backpack;
			lockSkills();
		}
		else
		{
			location = SkillScreen;
		}
	}
	else
	{
		std::cout << "0 - Back\n-1 - -13 - Downgrade Skill\n\n";

		int x{};
		std::cin >> x;
		if (x < 0 && x > -14)
		{
			if (skillLevel[x *-1 - 1] > 0 && skillLockLevel[x * -1 - 1] > skillLevel[x * -1 - 1])
			{
				skillPoint += 1;
				skillLevel[x *-1 - 1] -= 1;
			}
			location = SkillScreen;
		}
		else if (x == 0)
		{
			location = Backpack;
			lockSkills();
		}
		else
		{
			location = SkillScreen;
		}
	}
}

void resourceScreen()
{
	AgainResources:
	std::system("cls");
	int i{};

	std::cout << "Resources: \n\n";

	for (int value : resources)
	{
		switch (i)
		{
		case Gold:
			std::cout << "Gold: " << resources[i] << '\n';
			break;
		case Wood:
			std::cout << "Wood: " << resources[i] << '\n';
			break;
		case Iron_ore:
			std::cout << "Iron ore: " << resources[i] << '\n';
			break;
		case Iron:
			std::cout << "Iron: " << resources[i] << '\n';
			break;
		case Steel:
			std::cout << "Steel: " << resources[i] << '\n';
			break;
		case Adamantine_ore:
			std::cout << "Adamantine ore: " << resources[i] << '\n';
			break;
		case Adamantine:
			std::cout << "Adamantine: " << resources[i] << '\n';
			break;

		default:
			break;
		}
		i++;
	}
	std::cout << "\n0 - Back\n\n";

	int x{};
	std::cin >> x;
	if (x == 0)
	{
		location = Inventory;
	}
	else
	{
		goto AgainResources;
	}
}

void itemScreen()
{
AgainItems:
	std::system("cls");

	std::cout << "Items: \n\n";

	allItems();
	
	std::cout << "\n0 - Back\n\n";

	int x{};
	std::cin >> x;
	if (x == 0)
	{
		location = Inventory;
	}
	else
	{
		goto AgainItems;
	}
}

void magicScreen()
{
AgainMagic:
	std::system("cls");

	std::cout << "Spells: \n\n";

	allSpells();

	std::cout << "\n0 - Back\n\n";

	int x{};
	std::cin >> x;
	if (x == 0)
	{
		location = Inventory;
	}
	else
	{
		goto AgainMagic;
	}
}

void drinkPotion(int type)
{
	switch (type)
	{
	case Hp:
	{
		stats[Hp] += 10;
		break;
	}
	case Stamina:
	{
		stats[Stamina] += 10;
		break;
	}
	default:
		break;
	}
}

void potionScreen()
{
AgainMagic:
	std::system("cls");

	std::cout << "Potions: \n\n";

	std::cout << "Hp Potion(s) - " + std::to_string(potions[Hp]) << "\n";
	std::cout << "Stamina Potion(s) - " + std::to_string(potions[Stamina]) << "\n";

	std::cout << "\n0 - Back\n";

	int x{};
	std::cin >> x;
	if (x == 0)
	{
		location = Inventory;
	}
	else if (x == 1)
	{
		drinkPotion(Hp);
		goto AgainMagic;
	}
	else if (x == 2)
	{
		drinkPotion(Stamina);
		goto AgainMagic;
	}
	else
	{
		goto AgainMagic;
	}
}


void potionScreenB()
{
AgainMagic:
	std::system("cls");

	std::cout << "Potions: \n\n";

	std::cout << "Hp Potion(s) - " + std::to_string(potions[Hp]) << "\n";
	std::cout << "Stamina Potion(s) - " + std::to_string(potions[Stamina]) << "\n";

	std::cout << "\n0 - Back\n";

	int x{};
	std::cin >> x;
	if (x == 0)
	{
		location = AttackInventory;
	}
	else if (x == 1)
	{
		drinkPotion(Hp);
		goto AgainMagic;
	}
	else if (x == 2)
	{
		drinkPotion(Stamina);
		goto AgainMagic;
	}
	else
	{
		goto AgainMagic;
	}
}