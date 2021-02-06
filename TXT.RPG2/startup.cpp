#include "allInclude.h"

std::string playerName{};
int diff{};
int clasDmgStat{};

int newOrLoad()
{
	using std::cout;
	std::system("cls");
	cout << "Create New Game Or Load\n\n";

	int x{};

	cout << "1 - New Game\n";
	cout << "2 - Load\n\n";

retry:

	x = 0;

	std::cin >> x;

	if (x == 1)
	{
		return 0;
	}
	else if (x == 2)
	{
		load();
		return 1;
	}
	else
	{
		goto retry;
	}
}

void naming()
{
	std::system("cls");

	std::cout << "Please enter your name: ";
	std::cin.ignore(32767, '\n');
	std::getline(std::cin, playerName);
}

void setDiff(std::string name)
{
	std::system("cls");

No:
		diff = 0;
		std::system("cls");
		std::cout << "Set you difficulty(1-5): ";
		std::cin >> diff;
		if (diff < 1 || diff > 5)
			goto No;
	
	stats[Hp] = stats[MaxHp];
	stats[Stamina] = stats[MaxStamina];

}

void difficlutyEffects()
{
	stats[MaxHp] = 15;
	stats[MaxStamina] = 15;
	stats[Hp] = stats[MaxHp];
	stats[Stamina] = stats[MaxStamina];

	stats[Strength] = 3;
	stats[Defence] = 3;
	stats[Agility] = 3;
	stats[Perception] = 3;
	stats[Intelligence] = 3;
	stats[Charisma] = 3;

	item[0] = Torch;
	itemAmount[0] = 6 - diff;
	itemMaxDurability[0] = 10;
	itemDurability[0] = itemMaxDurability[0];
	itemsInInventory += 1;

	expirience = 0;
	totalEXP = 0;
	level = 1;

	

	if (diff == 1)
	{
		skillPoint = 4;
		statPoint = 10;
	}
	else if (diff == 2)
	{
		skillPoint = 3;
		statPoint = 7;
	}
	else if (diff == 3)
	{
		skillPoint = 2;
		statPoint = 5;
	}
	else if (diff == 4)
	{
		skillPoint = 1;
		statPoint = 2;
	}
	else if (diff == 5)
	{
		skillPoint = 0;
		statPoint = 0;
		
	}

	resources[Gold] = 5 * skillPoint;

	int i{};
	for (int value : skillXP)
	{
		skillXPToNextLevel[i] = 200 * diff;
		i++;
	}
}
void classSetup()
{
	int x{};

AgainClass:
	std::system("cls");
	std::cout << "Choose a Class: " << "\n\n";
	
	std::cout << "\n";
	if (!booLeans[ClassSelected])
	{
		std::cout << "1 - Warrior(+3 Swordsmanship, +1 Defence, +1 Strength)\n";
		std::cout << "2 - Theif(+2 Stealth, +2 Lockpicking, +1 Agility)\n";
		std::cout << "3 - Ranger(+2 Bowmanship, +1 Agility, +2 Perception)\n";
		std::cout << "4 - Mage(+2 Arcanum, +1 Brewing, +2 Intelligence)\n";
		std::cout << "5 - Cleric(+1 Arcanum, +1 Medicine, +1 Brewing, +1 Intelligence, +1 Charisma)\n\n";

		x = 0;
		std::cin >> x;
		if (x > 0 && x < 6)
		{
			switch (x - 1)
			{
			case Warrior:
				skillLevel[Swordsmanship] += 3;

				stats[Defence] += 1;
				stats[Strength] += 1;
				clasDmgStat = Strength;

				booLeans[ClassSelected] = 1;
				selectedClass = 1;

				playerName += " the Warrior";

				item[itemsInInventory] = Sword;
				itemMaxDurability[itemsInInventory] = 25;
				itemDurability[itemsInInventory] = itemMaxDurability[itemsInInventory];
				itemRequirement[itemsInInventory] = 1;
				itemAmount[itemsInInventory] = 1;
				itemsInInventory += 1;

				break;
			case Theif:
				skillLevel[Stealth] += 2;
				skillLevel[Lockpicking] += 2;
				clasDmgStat = Strength;

				stats[Agility] += 1;

				booLeans[ClassSelected] = 1;
				selectedClass = 2;

				playerName += " the Theif";

				item[itemsInInventory] = Sword;
				itemMaxDurability[itemsInInventory] = 15;
				itemDurability[itemsInInventory] = itemMaxDurability[itemsInInventory];
				itemRequirement[itemsInInventory] = 0; // Temporary until dagger skill
				itemAmount[itemsInInventory] = 1;
				itemsInInventory += 1;

				break;
			case Ranger:
				skillLevel[Bowmanship] += 2;

				stats[Agility] += 1;
				stats[Perception] += 2;
				clasDmgStat = Perception;

				booLeans[ClassSelected] = 1;
				selectedClass = 3;

				playerName += " the Ranger";

				item[itemsInInventory] = Bow;
				itemMaxDurability[itemsInInventory] = 20;
				itemDurability[itemsInInventory] = itemMaxDurability[itemsInInventory];
				itemRequirement[itemsInInventory] = 1;
				itemAmount[itemsInInventory] = 1;
				itemsInInventory += 1;

				break;
			case Mage:
				skillLevel[Arcanum] += 2;
				skillLevel[Brewing] += 1;
				clasDmgStat = Intelligence;

				stats[Intelligence] += 2;

				booLeans[ClassSelected] = 1;
				selectedClass = 4;

				playerName += " the Mage";

				item[itemsInInventory] = Staff;
				itemMaxDurability[itemsInInventory] = 25;
				itemDurability[itemsInInventory] = itemMaxDurability[itemsInInventory];
				itemRequirement[itemsInInventory] = 1;
				itemAmount[itemsInInventory] = 1;
				itemsInInventory += 1;

				spellsUnlocked[Fireball] = true;
				spellLevel[Fireball] = 1;
				lastSpell = Fireball;

				break;
			case Cleric:
				skillLevel[Brewing] += 1;
				skillLevel[Medicine] += 1;
				skillLevel[Arcanum] += 1;
				clasDmgStat = Intelligence;

				stats[Intelligence] += 1;
				stats[Charisma] += 1;

				booLeans[ClassSelected] = 1;
				selectedClass = 5;

				playerName += " the Cleric";

				item[itemsInInventory] = Staff;
				itemMaxDurability[itemsInInventory] = 15;
				itemDurability[itemsInInventory] = itemMaxDurability[itemsInInventory];
				itemRequirement[itemsInInventory] = 1;
				itemAmount[itemsInInventory] = 1;
				itemsInInventory += 1;

				spellsUnlocked[HealWounds] = true;
				spellLevel[HealWounds] = 1;
				lastSpell = HealWounds;

				break;
			default:
				break;
			}

			lockSkills();
			lockStats();

			goto AgainClass;
		}
		else
		{
			goto AgainClass;
		}
	}
}

void statSetup()
{
AgainStats:
	std::system("cls");
	std::cout << "Unused statpoints: " << statPoint << "\n\n";
	int i{};
	for (int value : stats)
	{
		switch (i)
		{
		case Hp:
			std::cout << "1 - Hp: " << stats[MaxHp] / 5 << '\n';
			break;
		case Stamina:
			std::cout << "2 - Stamina: " << stats[MaxStamina] / 5 << '\n';
			break;
		case Strength:
			std::cout << "3 - Strength: " << stats[Strength] << '\n';
			break;
		case Defence:
			std::cout << "4 - Defence: " << stats[Defence] << '\n';
			break;
		case Agility:
			std::cout << "5 - Agility: " << stats[Agility] << '\n';
			break;
		case Perception:
			std::cout << "6 - Perception: " << stats[Perception] << '\n';
			break;
		case Intelligence:
			std::cout << "7 - Intelligence: " << stats[Intelligence] << '\n';
			break;
		case Charisma:
			std::cout << "8 - Charisma: " << stats[Charisma] << '\n';
			break;

		default:
			break;
		}
		i += 1;
	}
	std::cout << "\n";
	if (statPoint > 0)
	{
		std::cout << "1 - 8 - Upgrade Stat\n-1 - -8 Downgrade Stat\n";

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
			
			goto AgainStats;
		}
		else if (x < 0 && x > -9)
		{
			switch (x)
			{
			case -1:
				if (stats[MaxHp] > 5 && statLockLevel[MaxHp] < stats[MaxHp])
				{
					stats[MaxHp] -= 5;
					stats[Hp] -= 5;
					statPoint += 1;
				}
				break;
			case -2:
				if (stats[MaxStamina] > 5 && statLockLevel[MaxStamina] < stats[MaxStamina])
				{
					stats[MaxStamina] -= 5;
					stats[Stamina] -= 5;
					statPoint += 1;
				}
				break;
			case -3:
				if (stats[Strength] > 1 && statLockLevel[Strength] < stats[Strength])
				{
					stats[Strength] -= 1;
					statPoint += 1;
				}
				break;
			case -4:
				if (stats[Defence] > 1 && statLockLevel[Defence] < stats[Defence])
				{
					stats[Defence] -= 1;
					statPoint += 1;
				}
				break;
			case -5:
				if (stats[Agility] > 1 && statLockLevel[Agility] < stats[Agility])
				{
					stats[Agility] -= 1;
					statPoint += 1;
				}
				break;
			case -6:
				if (stats[Perception] > 1 && statLockLevel[Perception] < stats[Perception])
				{
					stats[Perception] -= 1;
					statPoint += 1;
				}
				break;
			case -7:
				if (stats[Intelligence] > 1 && statLockLevel[Intelligence] < stats[Intelligence])
				{
					stats[Intelligence] -= 1;
					statPoint += 1;
				}
				break;
			case -8:
				if (stats[Charisma] > 1 && statLockLevel[Charisma] < stats[Charisma])
				{
					stats[Charisma] -= 1;
					statPoint += 1;
				}
				break;
			default:
				break;
			}

			goto AgainStats;
		}
		else
		{
			goto AgainStats;
		}
	}

	lockStats();
}

void skillSetup()
{
AgainSkills:
	std::system("cls");
	std::cout << "Unused skillpoints: " << skillPoint << "\n\n\n";
	int i{};
	for (int us : skillLevel)
	{
		switch (i)
		{
		case Swordsmanship:
			std::cout << "Combat Skills:\n" << "1 - Swordsmanship: " << skillLevel[i] << '\n';
			break;
		case Bowmanship:
			std::cout << "2 - Bowmanship: " << skillLevel[i] << '\n';
			break;
		case Arcanum:
			std::cout << "3 - Arcanum: " << skillLevel[i] << "\n";
			break;
		case Wood_cutting:
			std::cout << "\nResource Gathering Skills:\n" << "4 - Wood-cutting: " << skillLevel[i] << '\n';
			break;
		case Mining:
			std::cout << "5 - Mining: " << skillLevel[i] << '\n';
			break;
		case Foraging:
			std::cout << "6 - Foraging: " << skillLevel[i] << "\n";
			break;
		case Hunting:
			std::cout << "7 - Hunting: " << skillLevel[i] << "\n";
			break;
		case Smithing:
			std::cout << "\nCrafting Skills:\n" << "8 - Smithing: " << skillLevel[i] << '\n';
			break;
		case Brewing:
			std::cout << "9 - Brewing: " << skillLevel[i] << '\n';
			break;
		case Toolsmanship:
			std::cout << "10 - Toolsmanship: " << skillLevel[i] << "\n";
			break;
		case Stealth:
			std::cout << "\nUtility Skills:\n" << "11 - Stealth: " << skillLevel[i] << '\n';
			break;
		case Medicine:
			std::cout << "12 - Medicine: " << skillLevel[i] << '\n';
			break;
		case Lockpicking:
			std::cout << "13 - Lockpicking: " << skillLevel[i] << '\n';
			break;

		default:
			break;
		}
		i += 1;
	}
	std::cout << "\n";
	if (skillPoint > 0)
	{
		std::cout << "1 - 13 - Upgrade Skill\n-1 - -13 - Downgrade Skill\n";

		int x{};
		std::cin >> x;
		if (x > 0 && x < 14)
		{
			skillPoint -= 1;
			skillLevel[x - 1] += 1;

			goto AgainSkills;
		}
		else if (x < 0 && x > -14)
		{
			if (skillLevel[x *- 1 -1] > 0 && skillLockLevel[x * -1 - 1] < skillLevel[x * -1 - 1])
			{
				skillPoint += 1;
				skillLevel[x *-1 - 1] -= 1;
			}
			goto AgainSkills;
		}
		else
		{
			goto AgainSkills;
		}
	}
	lockSkills();
}

//gg

void characterCreator()
{
	
	std::system("cls");
	classSetup();
	statSetup();
	skillSetup();

}

void itemLevelInit()
{
	int c{};
	for (int i : itemLevel)
	{
		itemLevel[c] = 1;
		c++;
	}
	c = 0;
	for (int i : sItemLevel)
	{
		sItemLevel[c] = 1;
		c++;
	}
}

void startup()
{
	using std::cout;
	std::system("cls");
	std::system("color b");

	booLeans[Won] = 0;
	location = Home;
	saveLocation = Home;
	lastLocation = Home;
	deepSaveLocation = Home;
	city = HaltonCity;
	cityID = CityHalton;

	hours = 8;
	minutes = 0;
	days = 1;

	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	cout << "Welcome to TXT.RPG\n";
	std::system("pause > nul");

	int loaded = newOrLoad();
	if (loaded == 0)
	{
		itemLevelInit();
		naming();
		setDiff(playerName);
		difficlutyEffects();
		characterCreator();
	}
}