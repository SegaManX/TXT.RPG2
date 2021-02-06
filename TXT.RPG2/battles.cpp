#include "allInclude.h"

int rewardXP{};
int rewardGold{};
int retreatLocation{};
int winLocation{};

std::string aeTextAfter{};
std::string aeTextBefore{};

int enemiesInBattle{};
int lastWeapon{1};
int lastSpell{};
int statCoefficient{};
double damageO{};
double damageI{};
int dodgechance{};

bool dead[10]{1,1,1,1,1,1,1,1,1,1};
bool allDead{1};

bool dealDamage{};
bool dodged{};
bool spelling{};

int aeLevel[10]{};
int aeStats[10][10]{ {},{} };
int aeSkillLevel[10][10]{ {},{} };
int aeDamage[10]{};
std::string aeName[10]{};
int battleSpots[10]{};
int quest{};

int enemiesKilled[100]{};

void trainingFight()
{
	enemies[0] =  Dummy;

	retreatLocation = Home;
	winLocation = Home;
	quest = NoQuest;


	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void alleyBanditFight()
{
	enemies[0] = Bandit;
	enemies[1] = Bandit;
	enemies[2] = Bandit;

	retreatLocation = HaltonCity;
	winLocation = HaltonAlley;
	quest = HaltonAlleyBanditQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void roadBanditFight()
{
	enemies[0] = RoadBandit;
	enemies[1] = RoadBandit;
	enemies[2] = RoadBandit;
	enemies[3] = RoadBandit;

	if (cityID == CityHalton)
	{
		retreatLocation = Road1;
		winLocation = Road2;
	}
	else
	{
		retreatLocation = Road2;
		winLocation = Road1;
	}
	quest = NoQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "You have been ambushed by road bandits";
	aeTextAfter = "After defeating them you continue to walk";


	location = BattleSetup;
}

void banditHideoutLookoutFight()
{
	enemies[0] = DrunkBandit;
	enemies[1] = DrunkBandit;

	retreatLocation = HaltonForest;
	winLocation = BanditHideout2;
	quest = NoQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void banditHideoutGuardFight()
{
	enemies[0] = Bandit;
	enemies[1] = Bandit;
	enemies[2] = Bandit;
	enemies[3] = Bandit;

	retreatLocation = HaltonForest;
	winLocation = BanditHideout3;
	quest = NoQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void banditHideoutKingFight()
{
	enemies[0] = BanditKing;
	enemies[1] = ForestBandit;
	enemies[2] = ForestBandit;

	retreatLocation = HaltonForest;
	winLocation = HaltonForest;
	quest = BanditHideoutQuest;

	rewardGold = 10;
	rewardXP = 200;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void wolfFight()
{
	enemies[0] = Wolf;
	enemies[1] = Wolf;
	enemies[2] = Wolf;
	enemies[3] = Wolf;

	retreatLocation = HaltonForest;
	winLocation = HaltonForest;
	quest = WolfAttackQuest;

	rewardGold = 10;
	rewardXP = 200;

	aeTextBefore = "Man: Help they are attacking me!";
	aeTextAfter = "The man gives you 20 gold for saving him";


	location = BattleSetup;
}

void smitheryFight()
{
	enemies[0] = DrunkBandit;

	retreatLocation = city;
	winLocation = Smithery;
	quest = SmitheryAccessQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "Someone is attacking the owner";
	aeTextAfter = "For saving him the owner allows you to use the smithery";


	location = BattleSetup;
}

void mineFight()
{
	enemies[0] = MadDwarf;

	retreatLocation = city;
	winLocation = Mine;
	quest = MineAccessQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "Someone is attacking the owner";
	aeTextAfter = "For saving him the owner allows you to use the mine";


	location = BattleSetup;
}

void lumberyardFight()
{
	enemies[0] = ForestBandit;

	retreatLocation = city;
	winLocation = Lumberyard;
	quest = LumberyardAccessQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "Someone is attacking the owner";
	aeTextAfter = "For saving him the owner allows you to use the lumberyard";


	location = BattleSetup;
}

void tarrinFight()
{
	enemies[0] = Zombie;
	enemies[1] = Skeleton;
	enemies[2] = Shadow;

	retreatLocation = TarrinCity;
	winLocation = TarrinCity;
	quest = LichMapQuest;

	rewardGold = 50;
	rewardXP = 100;

	aeTextBefore = "Some undead attack you";
	aeTextAfter = "";


	location = BattleSetup;
}

void tarCem1Fight()
{
	enemies[0] = Zombie;
	enemies[1] = Zombie;
	enemies[2] = Zombie;
	enemies[3] = Zombie;


	retreatLocation = city;
	winLocation = TarCem2;
	quest = NoQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void tarCem2Fight()
{
	enemies[0] = Shadow;
	enemies[1] = Shadow;
	enemies[2] = Shadow;
	enemies[3] = Shadow;


	retreatLocation = city;
	winLocation = TarCem3;
	quest = NoQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void tarCem3Fight()
{
	enemies[0] = Skeleton;
	enemies[1] = Skeleton;
	enemies[2] = Skeleton;
	enemies[3] = Skeleton;


	retreatLocation = city;
	winLocation = TarCem4;
	quest = NoQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void tarCem4Fight()
{
	enemies[0] = Zombie;
	enemies[1] = Zombie;
	enemies[2] = Shadow;
	enemies[3] = Shadow;
	enemies[4] = Skeleton;
	enemies[5] = Skeleton;
	enemies[6] = Lich;


	retreatLocation = city;
	winLocation = TarrinCity;
	quest = LichQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void oldPirateFight()
{
	enemies[0] = OldPirate;

	retreatLocation = Road7;
	winLocation = Road8;
	quest = NoQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void bridgeFight()
{
	enemies[0] = Troll;

	retreatLocation = Madthorne;
	winLocation = MadthorneLibrary;
	quest = MadthorneBridgeQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "The COOL HAT vanishes after the troll dies";


	location = BattleSetup;
}

void madthorneGoblinMineFight()
{
	enemies[0] = Goblin;
	enemies[1] = Goblin;
	enemies[2] = Goblin;
	enemies[3] = Goblin;
	enemies[4] = Goblin;
	enemies[5] = Goblin;
	enemies[6] = Goblin;
	enemies[7] = Goblin;
	enemies[8] = Goblin;
	enemies[9] = Goblin;

	retreatLocation = Madthorne;
	winLocation = MadthorneGoblinMine;
	quest = MadthorneGoblinMineQuest;

	rewardGold = 1;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void madthorneCastleFight1()
{
	enemies[0] = Goblin;
	enemies[1] = Goblin;
	enemies[2] = Goblin;

	retreatLocation = MadthorneCastle;
	winLocation = MadthorneCastleTowerDoors;
	quest = NoQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void madthorneCastleFight2()
{
	enemies[0] = OldPirate;

	retreatLocation = MadthorneCastle;
	winLocation = MadthorneCastleTower;
	quest = NoQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void madthorneCastleFight3()
{
	enemies[0] = OldPirate;

	retreatLocation = MadthorneCastle;
	winLocation = MadthornePrincessRoom;
	quest = NoQuest;

	rewardGold = 0;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "";


	location = BattleSetup;
}

void madthorneCastleFight4()
{
	enemies[0] = OldPirate;

	retreatLocation = MadthorneCastleTower;
	winLocation = MadthorneCastleTower;
	quest = NoQuest;

	rewardGold = 10000;
	rewardXP = 0;

	aeTextBefore = "";
	aeTextAfter = "You find 10000 Gold In the room";


	location = BattleSetup;
}

void darkCastleFight()
{
	enemies[0] = GREG;

	retreatLocation = DarkCastle;
	winLocation = DarkCastle;
	quest = PrincessQuest;

	rewardGold = 0;
	rewardXP = 10000;

	aeTextBefore = "";
	aeTextAfter = "You have defeated GREG the dark";


	location = BattleSetup;
}

int d20()
{
	int x{ d20Gen(mersenne) };
	if (x >= 20 - stats[Intelligence])
	{
		x = x * 2;
	}
	return x;
}
int ed20()
{
	int x{ d20Gen(mersenne) };
	if (x >= 20 - aeStats[targetEnemy - 1][Intelligence])
	{
		x = x * 2;
	}
	return x;
}
void d100()
{
	int x{ d100Gen(mersenne) };
	if (x <= dodgechance)
	{
		dodged = true;
	}
	else
	{
		dodged = false;
	}
}


void postAttack()
{
	if (stats[Hp] <= 0)
	{
		location = Die;
	}
	else
	{
		for (int i{}; i < enemiesInBattle; i++)
		{
			if (aeStats[i][Hp] <= 0)
			{
				dead[i] = true;
				battleSpots[i] = 0;
				if (aeStats[i][Hp] < 0)
				{
					aeStats[i][Hp] = 0;
				}
				
			}
		}
		for (int ii{}; ii < enemiesInBattle; ii++)
		{
			if (battleSpots[ii] != 0)
			{
				targetEnemy = ii + 1;
				break;
			}
		}
		if (dead[0] && dead[1] && dead[2] && dead[3] && dead[4] && dead[5] && dead[6] && dead[7] && dead[8] && dead[9])
		{
			allDead = true;
			int count{};
			for (int i : enemies)
			{
				enemies[count] = 0;
				count += 1;
				
			}
		}

		location = Battle;
	}

}

void attack(bool spelling)
{

	std::system("cls");
	// Main enemy fight


	statCoefficient = aeStats[targetEnemy - 1][Defence] - stats[clasDmgStat];
	damageO = round((d20() - statCoefficient) * (attackMultiplier *(damageOutput())));
	if (damageO <= 0)
	{
		damageO = 0;
	}
	statCoefficient = stats[Defence] - aeStats[targetEnemy - 1][Strength];
	damageI = round((ed20() - statCoefficient) * (attackMultiplier * aeDamage[targetEnemy - 1]));
	if (damageI <= 0)
	{
		damageI = 0;
	}

	dodgechance = 5 * (stats[Agility] + (stats[Intelligence] / 2) - aeStats[targetEnemy - 1][Agility]);
	if (dodgechance < 5)
	{
		dodgechance = 5;
	}
	if (rangedWeapon[item[lastWeapon]] == true)
	{
		dodgechance += 15;
	}
	d100();
	if (dodged)
	{
		damageI = 0;
	}
	else if (rangedWeapon[item[lastWeapon]] == true)
	{
		damageO = round(damageO * rangedWeaponDemultiplier);
	}

	if (stats[Agility] + (stats[Intelligence] / 2) > aeStats[targetEnemy - 1][Agility])
	{
		if (spelling && spellRequirement[lastSpell] <= stats[Stamina])
		{
			damageO = castSpell(Damage);
			std::cout << " You did " << damageO << " damage to " << aeName[targetEnemy - 1] << " with " << spellNames[lastSpell] << "\n";
			castSpell(Debuff);
			stats[Hp] += castSpell(Heal);
			if (stats[Hp] > stats[MaxHp])
			{
				stats[Hp] = stats[MaxHp];
			}
			if (castSpell(Heal) > 0)
			{
				std::cout << " You healed " << castSpell(Heal) << " damage to yourself with " << spellNames[lastSpell] << "\n";
			}
			stats[Stamina] -= spellRequirement[lastSpell];
		}
		else
		{
			if (damageO > 0)
			{
				aeStats[targetEnemy - 1][Hp] -= damageO;
				std::cout << " You did " << damageO << " damage to " << aeName[targetEnemy - 1] << "\n";
			}
		}

		if (aeStats[targetEnemy - 1][Hp] > 0)
		{
			if (damageI > 0)
			{
				stats[Hp] -= damageI;
				std::cout << aeName[targetEnemy - 1] << " did " << damageI << " damage to you\n";
			}
		}
		

		
	}
	else
	{
		if (aeStats[targetEnemy - 1][Hp] > 0)
		{
			if (damageI > 0)
			{
				stats[Hp] -= damageI;
				std::cout << aeName[targetEnemy - 1] << " did " << damageI << " damage to you\n";
			}
		}

		if (stats[Hp] > 0)
		{
			if (spelling && spellRequirement[lastSpell] <= stats[Stamina])
			{
				damageO = castSpell(Damage);
				std::cout << " You did " << damageO << " damage to " << aeName[targetEnemy - 1] << " with " << spellNames[lastSpell] << "\n";
				castSpell(Debuff);
				stats[Hp] += castSpell(Heal);
				if (castSpell(Heal) > 0)
				{
					std::cout << " You healed " << castSpell(Heal) << " damage to yourself with " << spellNames[lastSpell] << "\n";
				}
				stats[Stamina] -= spellRequirement[lastSpell];
			}
			else
			{
				if (damageO > 0)
				{
					aeStats[targetEnemy - 1][Hp] -= damageO;
					std::cout << " You did " << damageO << " damage to " << aeName[targetEnemy - 1] << "\n";
				}
			}
		}
	}

	itemDurability[lastWeapon] -= 1;
	
	// Other enemy attacks

	for (int i{}; i < 10; i++)
	{
		if (targetEnemy != i + 1 && !dead[i] )
		{
			statCoefficient = stats[Defence] - aeStats[i][Strength];
			damageI = round((d20() - statCoefficient) * (attackMultiplier * aeDamage[i]));
			if (damageI <= 0)
			{
				damageI = 0;
			}
			dodgechance = 5 * (stats[Agility] + (stats[Intelligence] / 2) - aeStats[i][Agility]);
			if (dodgechance < 5)
			{
				dodgechance = 5;
			}
			if (rangedWeapon[item[lastWeapon]] == true)
			{
				dodgechance += 10;
			}
			d100();
			if (dodged)
			{
				damageI = 0;
			}
			if (damageI > 0)
			{
				stats[Hp] -= damageI;
				std::cout << aeName[i] << " did " << damageI << " damage to you\n";
			}
		}
	}
	std::system("pause>nul");


	location = PostAttack;
}

void changeWeapon()
{
	int x{};
	int iWannaSleep{}; // Its 1:20 AM

AgainItems:
	x = 0;
	std::system("cls");

	std::cout << "Items: \n\n";

	combatItems();

	if (shownItems <= 0) {
		std::cout << "\n0 - Back\nn";
		std::cin >> x;
		if (x == 0)
		{
			
		}
		else
		{
			goto AgainItems;
		}
	}
	else if (shownItems == 1)
	{
		std::cout << "\n0 - Back\n";
		std::cout << "1 - ";
		int y{};
		for (int i : itemShown)
		{
			if (i)
			{
				std::cout << itemName[item[y]] << "\n";
			}
			y++;
		}
		std::cout << "\n";
		x = 0;
		std::cin >> x;
		if (x == 1)
		{
			int yy{};
			for (int i : itemShown)
			{
				if (i)
				{
					lastWeapon = yy;
				}
				yy++;
			}
		}
		else if (x == 0)
		{

		}
		else
		{
			goto AgainItems;
		}
	}
	else
	{
		std::cout << "\n";
		
			int y{};
			int z{1};
			std::cout << "0 - Back\n";
			for (int i : itemShown)
			{
				if (i)
				{
					std::cout << z << " - ";
					std::cout << itemName[item[y]] << "\n";
					z++;
				}
				y++;
			}
			std::cout << "\n";
		
		x = 0;
		std::cin >> x;
		if (x == 1)
		{
			int yy{};
			for (int i : itemShown)
			{
				if (i)
				{
					lastWeapon = yy;
				}
				yy++;
			}
		}
		else if (x <= shownItems)
		{
			for (int i{}; i < shownItems; i++)
			{
				int yy{};
				for (int i : itemShown)
				{
					if (i && iWannaSleep < x)
					{
						lastWeapon = yy;
						iWannaSleep += 1;
					}
					yy++;
				}
			}
		}
		else if (x == 0)
		{

		}
		else
		{
			goto AgainItems;
		}
	}

	location = AttackInventory;
}

void fightStats()
{
	std::system("cls");
	int i{};
	std::cout << playerName << ": \n\n";
	for (int value : stats)
	{
		switch (i)
		{
		case MaxHp:
			std::cout << "Hp: " << stats[MaxHp] / 5 << '\n';
			break;
		case MaxStamina:
			std::cout << "Stamina: " << stats[MaxStamina] / 5 << '\n';
			break;
		case Strength:
			std::cout << "Strength: " << stats[Strength] << '\n';
			break;
		case Defence:
			std::cout << "Defence: " << stats[Defence] << '\n';
			break;
		case Agility:
			std::cout << "Agility: " << stats[Agility] << '\n';
			break;
		case Perception:
			std::cout << "Perception: " << stats[Perception] << '\n';
			break;
		case Intelligence:
			std::cout << "Intelligence: " << stats[Intelligence] << '\n';
			break;
		case Charisma:
			std::cout << "Charisma: " << stats[Charisma] << '\n';
			break;

		default:
			break;
		}
		i++;
	}
	std::system("pause>nul");
	location = AttackInventory;
}

void targetEnemyStats()
{
	std::system("cls");
	std::cout << aeName[targetEnemy - 1] << ": \n\n";
	std::cout << "Level: " << aeLevel[targetEnemy - 1] << "\n";
	std::cout << "Hp: " << aeStats[targetEnemy - 1][Hp] << "/" << aeStats[targetEnemy - 1][MaxHp] << "\n";
	std::cout << "Stamina: " << aeStats[targetEnemy - 1][Stamina] << "/" << aeStats[targetEnemy - 1][MaxStamina] << "\n";
	std::cout << "Strength: " << aeStats[targetEnemy - 1][Strength] << "\n";
	std::cout << "Defence: " << aeStats[targetEnemy - 1][Defence] << "\n";
	std::cout << "Agility: " << aeStats[targetEnemy - 1][Agility] << "\n";
	std::cout << "Perception: " << aeStats[targetEnemy - 1][Perception] << "\n";
	std::cout << "Intelligence: " << aeStats[targetEnemy - 1][Intelligence] << "\n";
	std::cout << "Charisma: " << aeStats[targetEnemy - 1][Charisma] << "\n";

	std::system("pause>nul");

	location = AttackInventory;
}

void fightSpells()
{

	int x{};
	int iWannaSleep{};

AgainSpells:
	x = 0;
	std::system("cls");

	std::cout << "Spells: \n\n";

	combatSpells();

	if (shownSpells <= 0) {
		std::cout << "\n0 - Back\n\n";
		std::cin >> x;
		if (x == 0)
		{
			location = AttackInventory;
		}
		else
		{
			goto AgainSpells;
		}
	}
	else if (shownSpells == 1)
	{

		std::cout << "0 - Back";
		std::cout << "\n1 - ";
		int y{};
		for (int i : spellsShown)
		{
			if (i)
			{
				std::cout << spellNames[y] << "\n";
			}
			y++;
		}
		std::cout << "\n";
		x = 0;
		std::cin >> x;
		if (x == 0)
		{
			location = AttackInventory;
		}
		else if (x == 1)
		{
			int yy{};
			for (int i : spellsShown)
			{
				if (i)
				{
					lastSpell = yy;
					location = AttackInventory;
				}
				yy++;
			}
		}
		else
		{
			goto AgainSpells;
		}
	}
	else
	{
		std::cout << "\n";

		int y{};
		int z{ 1 };
		std::cout << 0 << " - Back\n";
		for (int i : spellsShown)
		{
			if (i)
			{
				std::cout << z << " - " << spellNames[y] << "\n";
				z++;
			}
			y++;
		}
		std::cout << "\n";

		x = 0;
		std::cin >> x;
		if (x == 1)
		{
			int yy{};
			for (int i : spellsShown)
			{
				if (i)
				{
					lastSpell = yy;
				}
				yy++;
			}

			location = AttackInventory;
		}
		else if (x <= shownSpells)
		{
			for (int i{}; i < shownSpells; i++)
			{
				int yy{};
				for (int i : spellsShown)
				{
					if (i && iWannaSleep < x)
					{
						lastSpell = yy;
						iWannaSleep += 1;
					}
					yy++;
				}
			}

			location = AttackInventory;
		}
		else if (x == 0)
		{

			location = AttackInventory;
		}
		else
		{
			goto AgainSpells;
		}
	}
}



void attackInventory()
{
	int x{};
	Redo:
	std::system("cls");
	std::cout << "Inventory: \n\n";
	std::cout << playerName << ": ";
	std::cout << "Level: " << level << "\n";
	std::cout << "Hp: " << stats[MaxHp] << "/" << stats[Hp] << "\n";
	std::cout << "Stamina: " << stats[MaxStamina] << "/" << stats[Stamina] << "\n\n";
	std::cout << "0 - Back\n1 - Change Weapon\n2 - Spells\n3 - Stats\n4 - Target Enemy Stats\n5 - Potions\n\n";
	x = 0;
	std::cin >> x;
	
	if (x == 0)
	{
		location = Battle;
	}
	else if (x == 1)
	{
		location = ChangeWeapon;
	}
	else if (x == 2)
	{
		location = FightSpells;
	}
	else if (x == 3)
	{
		location = FightStats;

	}
	else if (x == 4)
	{
		location = TargetEnemyStats;

	}
	else if (x == 5)
	{
		location = PotionScreenB;
	}
	else
	{
		goto Redo;
	}

}

void changeTarget()
{
	std::system("cls");
	int x{};

	for (int i{1}; i <= enemiesInBattle; i++)
	{
		if (battleSpots[i - 1] == i)
		{
			std::cout << "Target " << i << ". : ";

			std::cout << aeName[i - 1] << "\n";
		}
	}
	std::cout << "\n\n";
	x = 0;
	std::cin >> x;
	
	targetEnemy = x;

	location = Battle;

}

void battleSetup()
{
	enemiesInBattle = 0;
	int count{};
	for (int i : battleSpots)
	{
		battleSpots[count] = 0;
		count += 1;
	}

	for (int i{}; i < 10; i++)
	{
		if (enemies[i] != 0)
		{

			enemiesInBattle += 1;
			selectCreature(enemies[i]);
			dead[i] = false;
			battleSpots[i] = i + 1;
			allDead = false;

			int times{};

			aeName[i] = eName;
			aeTextBefore += "\n" + eTextBefore;
			aeTextAfter += "\n" + eTextAfter;
			rewardXP += eRewardXP;
			rewardGold += eRewardGold;

			aeLevel[i] = eLevel;
			aeDamage[i] = eDamage;

			times = 0;
			for (int ii : eStats)
			{
				aeStats[i][times] = ii;
				times++;

			}
			times = 0;
			for (int ii : eSkillLevel)
			{
				aeSkillLevel[i][times] = ii;
				times++;
			}
		}
	}

	std::system("cls");
	std::cout << aeTextBefore;
	std::system("pause>nul");


	targetEnemy = 1;
	location = Battle;
}

void battle()
{
	int x{};
	int speed{ stats[Agility] + (stats[Intelligence] / 2) };
	bool canRun{};
	int faster{};


NextAttack:
	if (!allDead)
	{

		std::system("cls");

		std::cout << playerName << ": \n\n";
		std::cout << "Level: " << level << "\n";
		std::cout << "Hp: " << stats[Hp] << "/" << stats[MaxHp] << "\n";
		std::cout << "Stamina: " << stats[Stamina] << "/" << stats[MaxStamina] << "\n\n";

		for (int i{}; i < enemiesInBattle; i++) // Show all enemies
		{
			
				std::cout << i + 1<< ". " << aeName[i] << ": \n\n";
				std::cout << "Level: " << aeLevel[i] << "\n";
				std::cout << "Hp: " << aeStats[i][Hp] << "/" << aeStats[i][MaxHp] << "\n";
				std::cout << "Stamina: " << aeStats[i][Stamina] << "/" << aeStats[i][MaxStamina] << "\n\n";
		} 
		std::cout << "Target: " << aeName[targetEnemy - 1] << " - Enemy " << targetEnemy << ".\n\n";

		std::cout << "1 - Attack With Last Weapon\n";
		std::cout << "2 - Cast selected spell\n";
		std::cout << "3 - Inventory\n";
		std::cout << "4 - Change Target\n";

		speed = stats[Agility] + (stats[Intelligence] / 2);
		canRun = false;
		x = 0;

		faster = 0;
		for (int i{}; i < 10; i++)
		{
			if (speed > aeStats[i][Agility])
			{
				faster += 1;
			}
		}

		if (faster == 10)
		{
			canRun = true;
		}

		if (canRun == true)
		{
			std::cout << "5 - Run away\n";
		}

		std::cout << "\n";

		std::cin >> x;

		if (x == 1)
		{
			location = Attack;
		}
		else if (x == 2)
		{
			location = AttackS;
		}
		else if (x == 3)
		{
			location = AttackInventory;
		}
		else if (x == 4)
		{
			location = ChangeTarget;
		}
		else if (x == 5 && canRun == true)
		{
			location = retreatLocation;
		}
		else
		{
			goto NextAttack;
		}

	}
	if (allDead)
	{
		if (aeTextAfter != "")
		{
			std::system("cls");
			std::cout << aeTextAfter;
			std::system("pause>nul");
		}

		expirience += rewardXP;
		totalEXP += rewardXP;
		switch (item[lastWeapon])
		{
		case Sword:
			skillTotalXP[Swordsmanship] += rewardXP;
			skillXP[Swordsmanship] += rewardXP;
			break;
		case Bow:
			skillTotalXP[Bowmanship] += rewardXP;
			skillXP[Bowmanship] += rewardXP;
			break;
		case Staff:
			skillTotalXP[Arcanum] += rewardXP;
			skillXP[Arcanum] += rewardXP;
			break;
		default:
			break;
		}
		questUpdater();
		resources[Gold] += rewardGold;
		location = winLocation;
		int c{};
		for (int i : enemies)
		{
			enemiesKilled[enemies[c]] += 1;
			enemies[c] = 0;
				c++;
		}
	}
}