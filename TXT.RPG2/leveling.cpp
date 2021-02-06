#include "allInclude.h"


int stats[10]{};
int statPoint{};
int statLockLevel[10]{};

int skillXP[13];
int skillXPToNextLevel[13];
int skillTotalXP[13];
int skillLevel[13];
int skillPoint{};
int skillLockLevel[13]{};

int expirience{};
int totalEXP{};
int level{};

int selectedClass{};

void lockStats()
{
	int c{};
	for (int i : stats)
	{
		statLockLevel[c] = i;
		c++;
	}
}

void lockSkills()
{
	int c{};
	for (int i : skillLevel)
	{
		skillLockLevel[c] = i;
		c++;
	}
}

void showXP()
{
	std::cout << "Level: " << level << '\n';
	if (expirience < 100 * (1.5 * level - 1))
	{
		std::cout << "XP: [----------]\n";
	}
	else if (expirience < 200 * (1.5 * level - 1))
	{
		std::cout << "XP: [*---------]\n";
	}
	else if (expirience < 300 * (1.5 * level - 1))
	{
		std::cout << "XP: [**--------]\n";
	}
	else if (expirience < 400 * (1.5 * level - 1))
	{
		std::cout << "XP: [***-------]\n";
	}
	else if (expirience < 500 * (1.5 * level - 1))
	{
		std::cout << "XP: [****------]\n";
	}
	else if (expirience < 600 * (1.5 * level - 1))
	{
		std::cout << "XP: [*****-----]\n";
	}
	else if (expirience < 700 * (1.5 * level - 1))
	{
		std::cout << "XP: [******----]\n";
	}
	else if (expirience < 800 * (1.5 * level - 1))
	{
		std::cout << "XP: [*******---]\n";
	}
	else if (expirience < 900 * (1.5 * level - 1))
	{
		std::cout << "XP: [********--]\n";
	}

	else if (expirience < 1000 * (1.5 * level - 1))
	{
		std::cout << "XP: [*********-]\n";
	}
}

void levelUp()
{
	std::system("cls");

	if (expirience >= 1000 * (1.5 * level - 1))
	{
		std::cout << "You have leveled up\n";
		expirience -= floor(1000 * (1.5 * level));
		skillPoint += 2;
		statPoint += 5;
		level += 1;
		switch (selectedClass - 1)
		{
		case Warrior:
			std::cout << "You gained +3 Swordsmanship, +1 Defence, +1 Strength";
			skillLevel[Swordsmanship] += 3;
			stats[Defence] += 1;
			stats[Strength] += 1;
			break;
		case Knight:
		{
			std::cout << "You gained +4 Swordsmanship, +3 Defence, +1 Strength, +2 Hp";
			skillLevel[Swordsmanship] += 4;
			stats[Defence] += 3;
			stats[MaxHp] += 2 * 5;
			stats[Hp] += 2 * 5;
			stats[Strength] += 1;
			break;
		}
		case Paladin:
		{
			std::cout << "You gained +4 Swordsmanship, +4 Defence, +1 Strength, +3 Hp, +2 Intelligence, +1 Stamina";
			skillLevel[Swordsmanship] += 4;
			stats[Defence] += 4;
			stats[MaxHp] += 3 * 5;
			stats[Hp] += 3 * 5;
			stats[Intelligence] += 2;
			stats[Stamina] += 1 * 5;
			stats[MaxStamina] += 1 * 5;
			stats[Strength] += 1;
			break;
		}
		case Guardian:
		{
			std::cout << "You gained +4 Swordsmanship, +6 Defence, +1 Strength, +4 Hp";
			skillLevel[Swordsmanship] += 4;
			stats[Defence] += 6;
			stats[MaxHp] += 4 * 5;
			stats[Hp] += 4 * 5;
			stats[Strength] += 1;
			break;
		}
		case Barbarian:
		{
			std::cout << "You gained +5 Swordsmanship, +1 Defence, +3 Strength, +1 Agility";
			skillLevel[Swordsmanship] += 5;
			stats[Defence] += 1;
			stats[Strength] += 3;
			stats[Agility] += 1;
			break;
		}
		case Chieftain:
		{
			std::cout << "You gained +5 Swordsmanship, +1 Defence, +5 Strength, +1 Agility, +2 Intelligence, +1 Stamina";
			skillLevel[Swordsmanship] += 5;
			stats[Defence] += 1;
			stats[Strength] += 5;
			stats[Agility] += 1;
			stats[Intelligence] += 2;
			stats[Stamina] += 1 * 5;
			stats[MaxStamina] += 1 * 5;
			break;
		}
		case Berserker:
		{
			std::cout << "You gained +6 Swordsmanship, +1 Defence, +5 Strength, +3 Agility";
			skillLevel[Swordsmanship] += 6;
			stats[Defence] += 1;
			stats[Strength] += 5;
			stats[Agility] += 3;
			break;
		}
		case Theif:
			std::cout << "You gained +2 Stealth, +2 Lockpicking, +1 Agility";
			skillLevel[Stealth] += 2;
			skillLevel[Lockpicking] += 2;
			stats[Agility] += 1;
			break;
		case Trickster:
		{
			std::cout << "You gained +2 Stealth, +2 Lockpicking, +2 Agility, +2 Intelligence, +2 Charisma";
			skillLevel[Stealth] += 2;
			skillLevel[Lockpicking] += 2;
			stats[Agility] += 2;
			stats[Intelligence] += 2;
			stats[Charisma] += 2;
			break;
		}
		case Bard:
		{
			std::cout << "You gained +2 Stealth, +2 Lockpicking, +2 Agility, +3 Intelligence, +5 Charisma, +1 Stamina";
			skillLevel[Stealth] += 2;
			skillLevel[Lockpicking] += 2;
			stats[Agility] += 2;
			stats[Intelligence] += 3;
			stats[Charisma] += 5;
			stats[Stamina] += 1 * 5;
			stats[MaxStamina] += 1 * 5;
			break;
		}
		case Joker:
		{
			std::cout << "You gained +2 Stealth, +2 Lockpicking, +2 Agility, +4 Intelligence, +4 Charisma, +1 Stamina";
			skillLevel[Stealth] += 2;
			skillLevel[Lockpicking] += 2;
			stats[Agility] += 2;
			stats[Intelligence] += 4;
			stats[Charisma] += 4;
			stats[Stamina] += 1 * 5;
			stats[MaxStamina] += 1 * 5;
			break;
		}
		case Assassin:
		{
			std::cout << "You gained +3 Stealth, +2 Lockpicking, +3 Agility, +2 Strength";
			skillLevel[Stealth] += 3;
			skillLevel[Lockpicking] += 2;
			stats[Agility] += 3;
			stats[Strength] += 2;
			break;
		}
		case Ninja:
		{
			std::cout << "You gained +5 Stealth, +3 Lockpicking, +5 Agility, +2 Strength";
			skillLevel[Stealth] += 5;
			skillLevel[Lockpicking] += 3;
			stats[Agility] += 5;
			stats[Strength] += 2;
			break;
		}
		case Hitman:
		{
			std::cout << "You gained +4 Stealth, +3 Lockpicking, +4 Agility, +4 Strength";
			skillLevel[Stealth] += 4;
			skillLevel[Lockpicking] += 3;
			stats[Agility] += 4;
			stats[Strength] += 4;
			break;
		}
		case Ranger:
			std::cout << "You gained +2 Bowmanship, +1 Agility, +2 Perception";
			skillLevel[Bowmanship] += 2;
			stats[Agility] += 1;
			stats[Perception] += 2;
			break;
		case Hunter:
		{
			std::cout << "You gained +3 Bowmanship, +3 Agility, +3 Perception, +1 Hunting";
			skillLevel[Bowmanship] += 3;
			stats[Agility] += 3;
			stats[Perception] += 3;
			skillLevel[Hunting] += 1;
			break;
		}
		case Beast_Hunter:
		{
			std::cout << "You gained +5 Bowmanship, +4 Agility, +5 Perception, +1 Hunting";
			skillLevel[Bowmanship] += 5;
			stats[Agility] += 4;
			stats[Perception] += 5;
			skillLevel[Hunting] += 1;
			break;
		}
		case Jager:
		{
			std::cout << "You gained +4 Bowmanship, +6 Agility, +4 Perception, +1 Hunting";
			skillLevel[Bowmanship] += 4;
			stats[Agility] += 6;
			stats[Perception] += 4;
			skillLevel[Hunting] += 1;
			break;
		}
		case Bowmaster:
		{
			std::cout << "You gained +4 Bowmanship, +2 Agility, +4 Perception";
			skillLevel[Bowmanship] += 4;
			stats[Agility] += 2;
			stats[Perception] += 4;
			break;
		}
		case Sniper:
		{
			std::cout << "You gained +4 Bowmanship, +2 Agility, +9 Perception";
			skillLevel[Bowmanship] += 4;
			stats[Agility] += 2;
			stats[Perception] += 9;
			break;
		}
		case Phantom:
		{
			std::cout << "You gained +4 Bowmanship, +6 Agility, +4 Perception, +1 Stealth";
			skillLevel[Bowmanship] += 4;
			stats[Agility] += 6;
			stats[Perception] += 4;
			skillLevel[Stealth] += 1;
			break;
		}
		case Mage:
			std::cout << "You gained +2 Arcanum, +1 Brewing, +2 Intelligence";
			skillLevel[Arcanum] += 2;
			skillLevel[Brewing] += 1;
			stats[Intelligence] += 2;
			break;
		case Arcane:
		{
			std::cout << "You gained +4 Arcanum, +1 Brewing, +3 Intelligence, +2 Stamina";
			skillLevel[Arcanum] += 4;
			skillLevel[Brewing] += 1;
			stats[Intelligence] += 3;
			stats[Stamina] += 2 * 5;
			stats[MaxStamina] += 2 * 5;
			break;
		}
		case Elemental:
		{
			std::cout << "You gained +5 Arcanum, +1 Brewing, +4 Intelligence, +5 Stamina";
			skillLevel[Arcanum] += 5;
			skillLevel[Brewing] += 1;
			stats[Intelligence] += 4;
			stats[Stamina] += 5 * 5;
			stats[MaxStamina] += 5 * 5;
			break;
		}
		case Archmage:
		{
			std::cout << "You gained +7 Arcanum, +1 Brewing, +4 Intelligence, +3 Stamina";
			skillLevel[Arcanum] += 7;
			skillLevel[Brewing] += 1;
			stats[Intelligence] += 4;
			stats[Stamina] += 3 * 5;
			stats[MaxStamina] += 3 * 5;
			break;
		}
		case Summoner:
		{
			std::cout << "You gained +3 Arcanum, +1 Brewing, +4 Intelligence, +2 Stamina";
			skillLevel[Arcanum] += 3;
			skillLevel[Brewing] += 1;
			stats[Intelligence] += 4;
			stats[Stamina] += 2 * 5;
			stats[MaxStamina] += 2 * 5;
			break;
		}
		case Necromancer:
		{
			std::cout << "You gained +5 Arcanum, +1 Brewing, +6 Intelligence, +3 Stamina";
			skillLevel[Arcanum] += 5;
			skillLevel[Brewing] += 1;
			stats[Intelligence] += 6;
			stats[Stamina] += 3 * 5;
			stats[MaxStamina] += 3 * 5;
			break;
		}
		case Elemental_Summoner:
		{
			std::cout << "You gained +5 Arcanum, +1 Brewing, +5 Intelligence, +4 Stamina";
			skillLevel[Arcanum] += 5;
			skillLevel[Brewing] += 1;
			stats[Intelligence] += 5;
			stats[Stamina] += 4 * 5;
			stats[MaxStamina] += 4 * 5;
			break;
		}
		case Cleric:
			std::cout << "You gained +1 Arcanum, +1 Medicine, +1 Brewing, +1 Intelligence, +1 Stamina";
			skillLevel[Brewing] += 1;
			skillLevel[Medicine] += 1;
			skillLevel[Arcanum] += 1;
			stats[Intelligence] += 1;
			stats[Stamina] += 1 * 5;
			stats[MaxStamina] += 1 * 5;
			break;
		case Druid:
		{
			std::cout << "You gained +2 Arcanum, +1 Medicine, +2 Brewing, +2 Intelligence, +1 Foraging, +1 Stamina";
			skillLevel[Brewing] += 2;
			skillLevel[Medicine] += 1;
			skillLevel[Arcanum] += 2;
			stats[Intelligence] += 2;
			skillLevel[Foraging] += 1;
			stats[Stamina] += 2 * 5;
			stats[MaxStamina] += 2 * 5;
			break;
		}
		case Beastmaster:
		{
			std::cout << "You gained +2 Arcanum, +1 Medicine, +2 Brewing, +2 Intelligence, +1 Foraging, +1 Stamina, +3 Strength, +1 Hp, +1 Defence";
			skillLevel[Brewing] += 2;
			skillLevel[Medicine] += 1;
			skillLevel[Arcanum] += 2;
			stats[Intelligence] += 2;
			skillLevel[Foraging] += 1;
			stats[Stamina] += 2 * 5;
			stats[MaxStamina] += 2 * 5;
			stats[Strength] += 3;
			stats[Hp] += 1 * 5;
			stats[MaxHp] += 1 * 5;
			stats[Defence] += 1;
			break;
		}
		case Shaman:
		{
			std::cout << "You gained +3 Arcanum, +1 Medicine, +3 Brewing, +3 Intelligence, +1 Foraging, +3 Stamina";
			skillLevel[Brewing] += 3;
			skillLevel[Medicine] += 1;
			skillLevel[Arcanum] += 3;
			stats[Intelligence] += 3;
			skillLevel[Foraging] += 1;
			stats[Stamina] += 3 * 5;
			stats[MaxStamina] += 3 * 5;
			break;
		}
		case Priest:
		{
			std::cout << "You gained +1 Arcanum, +2 Medicine, +1 Brewing, +3 Intelligence, +3 Stamina";
			skillLevel[Brewing] += 1;
			skillLevel[Medicine] += 2;
			skillLevel[Arcanum] += 1;
			stats[Intelligence] += 3;
			stats[Stamina] += 3 * 5;
			stats[MaxStamina] += 3 * 5;
			break;
		}
		case Bishop:
		{
			std::cout << "You gained +1 Arcanum, +5 Medicine, +1 Brewing, +4 Intelligence, +4 Stamina";
			skillLevel[Brewing] += 1;
			skillLevel[Medicine] += 5;
			skillLevel[Arcanum] += 1;
			stats[Intelligence] += 4;
			stats[Stamina] += 4 * 5;
			stats[MaxStamina] += 4 * 5;
			break;
		}
		case Divine_Mage:
		{
			std::cout << "You gained +4 Arcanum, +2 Medicine, +1 Brewing, +4 Intelligence, +4 Stamina";
			skillLevel[Brewing] += 1;
			skillLevel[Medicine] += 2;
			skillLevel[Arcanum] += 4;
			stats[Intelligence] += 4;
			stats[Stamina] += 4 * 5;
			stats[MaxStamina] += 4 * 5;
			break;
		}
		default:
			break;
		}
		std::cout << " and +2 Skillpoints, +5 Statpoints\n";
		std::system("pause>nul");
	}
	int i{};
	for (int count : skillXP)
	{
		if (count >= skillXPToNextLevel[i])
		{
				switch (i)
				{
				case Swordsmanship:
					std::cout << "Swordsmanship Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Bowmanship:
					std::cout << "Bowmanship Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Arcanum:
					std::cout << "Arcanum Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Wood_cutting:
					std::cout << "Wood-cutting Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Mining:
					std::cout << "Mining Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Foraging:
					std::cout << "Foraging Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Hunting:
					std::cout << "Hunting Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Smithing:
					std::cout << "Smithing Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Brewing:
					std::cout << "Brewing Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Toolsmanship:
					std::cout << "Toolsmanship Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Stealth:
					std::cout << "Stealth Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Medicine:
					std::cout << "Medicine Leveled Up: Level " << skillLevel[i] << '\n';
					break;
				case Lockpicking:
					std::cout << "Lockpicking Leveled Up: Level " << skillLevel[i] << '\n';
					break;

				default:
					break;
				}
			
			skillXP[i] = 0;
			skillLevel[i] += 1;
			skillXPToNextLevel[i] += 200 * diff;
			std::system("pause>nul");
		}
		i++;
	}
}