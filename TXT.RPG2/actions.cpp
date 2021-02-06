#include "allInclude.h"


void win()
{
	using std::cout;
	std::system("cls");
	std::system("color e");
	cout << "Congratulations " << playerName << " you have won!\n\n";

	std::system("pause>nul");

	int x{};

	cout << "1 - Restart\n";
	cout << "2 - Exit\n\n";


	std::cin >> x;

	if (x == 1)
	{
		startup();
	}
	else if (x == 2)
	{
		booLeans[0] = 1;
	}
	else
	{
		win();
	}
}
// Die
void die()
{
	if (stats[Hp] <= 0)
	{
		using std::cout;
		std::system("cls");
		std::system("color 4");
		cout << "Game Over " << playerName << " You Have Failed!\n\n";

		std::system("pause>nul");

		int x{};

		cout << "1 - Restart\n";
		cout << "2 - Exit\n\n";


		std::cin >> x;

		if (x == 1)
		{
			startup();
		}
		else if (x == 2)
		{
			booLeans[0] = 1;
		}
		else
		{
			die();
		}
	}
}

void sleepHome()
{
	std::system("cls");
	for (int i{ 0 }; i < 5; ++i)
	{
		std::cout << "zZz" << ' ';
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	stats[Hp] = stats[MaxHp];
	stats[Stamina] = stats[MaxStamina];
	days += 1;
	hours = 7;
	minutes = 50;

	if (hunger > 0)
	{
		hunger -= 1;
	}
	else
	{
		stats[Hp] -= 5;
		if (stats[Hp] <= 0)
		{
			die();
		}
	}

	if (thirst > 0)
	{
		thirst -= 1;
	}
	else
	{
		stats[Stamina] -= 5;
		if (stats[Stamina] <= 0)
		{
			stats[Hp] -= 5;
			if (stats[Hp] <= 0)
			{
				die();
			}
		}
	}

	location = Home;
}

void eat()
{
	if (resources[Gold] >= foodCost)
	{
		hunger = 10;
		
		resources[Gold] -= foodCost;
	}
	location = lastLocation;
}


void drink()
{
	if (resources[Gold] >= drinkCost)
	{
		thirst = 10;
		resources[Gold] -= drinkCost;
	}
	location = lastLocation;
}

void sleepTavern()
{
	if (resources[Gold] >= sleepCost)
	{
		for (int i{ 0 }; i < 5; ++i)
		{
			std::cout << "zZz" << ' ';
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		stats[Hp] = stats[MaxHp];
		stats[Stamina] = stats[MaxStamina];
		days += 1;
		hours = 7;
		minutes = 50;

		if (hunger > 0)
		{
			hunger -= 1;
		}
		else
		{
			stats[Hp] -= 5;
			if (stats[Hp] <= 0)
			{
				die();
			}
		}

		if (thirst > 0)
		{
			thirst -= 1;
		}
		else
		{
			stats[Stamina] -= 5;
			if (stats[Stamina] <= 0)
			{
				stats[Hp] -= 5;
				if (stats[Hp] <= 0)
				{
					die();
				}
			}
		}

		resources[Gold] -= sleepCost;
	}
	location = lastLocation;
}

void buyWeapons()
{

	itemsInStore = 0;
	int storeItems[100]{};

	for (int i{ 0 }; i < cityID * 5; i++)
	{
		int waste{rand()};
		int rng{rand() % LastItem + 1};
		generateItem(rng);
	}

AgainBW:
	std::system("cls");
	itemsInStore = 0;

	std::cout << "Weapons: \n\n";
	
	for (int i{1}; i <= cityID * 5; i++)
	{
		if (sItem[i] == 1 && skillLevel[Swordsmanship] >= sItemRequirement[i])
		{
			std::cout << itemsInStore + 1 << " - ";
			std::cout << sItemAmount[i] << "x ";
			std::cout << "Level " << sItemLevel[i] << " ";
			std::cout << "Sword";
			suffix(sItemEnchant[i]);
			std::cout << "- Durability: " << sItemMaxDurability[i] << "/" << sItemDurability[i] ;
			sItemValue[i] = itemValueOutput(i, true);
			std::cout << " (" << sItemValue[i] << "G)" << "\n";

			sItem[itemsInStore] = sItem[i];
			sItemMaxDurability[itemsInStore] = sItemMaxDurability[i];
			sItemDurability[itemsInStore] = sItemDurability[i];
			sItemAmount[itemsInStore] = sItemAmount[i];
			sItemEnchant[itemsInStore] = sItemEnchant[i];
			sItemLevel[itemsInStore] = sItemLevel[i];
			sItemRequirement[itemsInStore] = sItemRequirement[i];
			sItemValue[itemsInStore] = sItemValue[i];

			storeItems[itemsInStore] = i;

			itemsInStore += 1;
		}

			
		if (sItem[i] == 2 && skillLevel[Bowmanship] >= sItemRequirement[i])
		{
			std::cout << itemsInStore + 1 << " - ";
			std::cout << sItemAmount[i] << "x ";
			std::cout << "Level " << sItemLevel[i] << " ";
			std::cout << "Bow";
			suffix(sItemEnchant[i]);
			std::cout << "- Durability: " << sItemMaxDurability[i] << "/" << sItemDurability[i];
			sItemValue[i] = itemValueOutput(i, true);
			std::cout << " (" << sItemValue[i] << "G)" << "\n";

			sItem[itemsInStore] = sItem[i];
			sItemMaxDurability[itemsInStore] = sItemMaxDurability[i];
			sItemDurability[itemsInStore] = sItemDurability[i];
			sItemAmount[itemsInStore] = sItemAmount[i];
			sItemEnchant[itemsInStore] = sItemEnchant[i];
			sItemLevel[itemsInStore] = sItemLevel[i];
			sItemRequirement[itemsInStore] = sItemRequirement[i];
			sItemValue[itemsInStore] = sItemValue[i];

			storeItems[itemsInStore] = i;

			itemsInStore += 1;
		}
			
		
		if (sItem[i] == 3 && skillLevel[Arcanum] >= sItemRequirement[i])
		{
			std::cout << itemsInStore + 1 << " - ";
			std::cout << sItemAmount[i] << "x ";
			std::cout << "Level " << sItemLevel[i] << " ";
			std::cout << "Staff";
			suffix(sItemEnchant[i]);
			std::cout << "- Durability: " << sItemMaxDurability[i] << "/" << sItemDurability[i];
			sItemValue[i] = itemValueOutput(i, true);
			std::cout << " (" << sItemValue[i] << "G)" << "\n";

			sItem[itemsInStore] = sItem[i];
			sItemMaxDurability[itemsInStore] = sItemMaxDurability[i];
			sItemDurability[itemsInStore] = sItemDurability[i];
			sItemAmount[itemsInStore] = sItemAmount[i];
			sItemEnchant[itemsInStore] = sItemEnchant[i];
			sItemLevel[itemsInStore] = sItemLevel[i];
			sItemRequirement[itemsInStore] = sItemRequirement[i];
			sItemValue[itemsInStore] = sItemValue[i];

			storeItems[itemsInStore] = i;

			itemsInStore += 1;
		}
			
		if (sItem[i] == 4)
		{
			std::cout << itemsInStore + 1 << " - ";
			std::cout << sItemAmount[i] << "x ";
			std::cout << "Torch";
			std::cout << " - Durability: " << sItemMaxDurability[i] << "/" << sItemDurability[i];
			sItemValue[i] = itemValueOutput(i, true);
			std::cout << " (" << sItemValue[i] << "G)" << "\n";

			sItem[itemsInStore] = sItem[i];
			sItemMaxDurability[itemsInStore] = sItemMaxDurability[i];
			sItemDurability[itemsInStore] = sItemDurability[i];
			sItemAmount[itemsInStore] = sItemAmount[i];
			sItemEnchant[itemsInStore] = sItemEnchant[i];
			sItemLevel[itemsInStore] = sItemLevel[i];
			sItemRequirement[itemsInStore] = sItemRequirement[i];
			sItemValue[itemsInStore] = sItemValue[i];

			storeItems[itemsInStore] = i;

			itemsInStore += 1;
		}
	}

	std::cout << "\n";
	std::cout << itemsInStore + 1 << " - Back\n\n";

	int x{};
	std::cin >> x;
	for (int i{1}; i <= itemsInStore; i++)
	{
		if (x == i)
		{
			if (resources[Gold] >= sItemValue[i - 1])
			{
				resources[Gold] -= sItemValue[i - 1];

				std::system("cls");

				item[itemsInInventory] = sItem[i - 1];
				itemMaxDurability[itemsInInventory] = sItemMaxDurability[i - 1];
				itemDurability[itemsInInventory] = sItemDurability[i - 1];
				itemAmount[itemsInInventory] = sItemAmount[i - 1];
				itemEnchant[itemsInInventory] = sItemEnchant[i - 1];
				itemLevel[itemsInInventory] = sItemLevel[i - 1];
				itemRequirement[itemsInInventory] = sItemRequirement[i - 1];

				std::cout << "You got ";
				std::cout << itemAmount[itemsInInventory] << "x ";
				std::cout << "Level " << itemLevel[itemsInInventory] << " ";

				switch (item[itemsInInventory])
				{
				case Sword:
					
					std::cout << "Sword";
					break;
				case Bow:
					std::cout << "Bow";
					break;
				case Staff:
					std::cout << "Staff";
					break;
				case Torch:
					std::cout << "Torch";
					break;
				default:
					break;
				}
				
				suffix(itemEnchant[itemsInInventory]);
				std::cout << "- Durability: " << itemMaxDurability[itemsInInventory] << "/" << itemDurability[itemsInInventory] << "\n";
				shownItems += 1;
				itemShown[itemsInInventory] = true;
				
				itemsInInventory += 1;

				std::system("pause>nul");

				location = Shop;
			}
		}
		else if (x == itemsInStore + 1)
		{
			location = Shop;
		}
		else if (x > itemsInStore + 1 || x < 1)
		{
			goto AgainBW;
		}
	}
}

void chopWood()
{
	int rng{};
	int resOut{};

	for (int i{}; i < skillLevel[Wood_cutting]; i++)
	{
		rng = (d20Gen(mersenne));

		if (rng >= 20 - skillLevel[Wood_cutting])
		{
			rng = rng * 2;
		}
		resOut += round(rng / 15.0);
	}
	resources[Wood] += resOut;

	skillTotalXP[Wood_cutting] += resOut * 10;
	skillXP[Wood_cutting] += resOut * 10;
	expirience += resOut * 10;

	std::system("cls");
	std::cout << "You got " << resOut << " wood...";
	std::system("pause>nul");

	location = Lumberyard;

}

void mine(int res)
{
	int rng{};
	int resOut{};

	for (int i{}; i < skillLevel[Mining]; i++)
	{
		rng = (d20Gen(mersenne));

		if (rng >= 20 - skillLevel[Mining])
		{
			rng = rng * 2;
		}
		if (round(rng / (10.0 * res)) <= 0)
		{
			resOut = 0;
		}
		else
		{
			resOut += round(rng / (10.0 * res));
		}
	}
	resources[res] += resOut;

	skillTotalXP[Mining] += resOut * 10;
	skillXP[Mining] += resOut * 10;
	expirience += resOut * 10;

	std::system("cls");
	std::cout << "You got "<< resOut <<" ore...";
	std::system("pause>nul");

	location = Mine;
}

void forage()
{
	int rng{};
	int resOut{};

	for (int i{}; i < skillLevel[Foraging]; i++)
	{
		rng = (d20Gen(mersenne));

		if (rng >= 20 - skillLevel[Foraging])
		{
			rng = rng * 2;
		}
		if (round(rng / (10.0)) <= 0)
		{
			resOut = 0;
		}
		else
		{
			resOut += round(rng / (10.0));
		}
	}
	stats[Hp] += resOut;
	if (stats[Hp] > stats[MaxHp])
	{
		stats[Hp] = stats[MaxHp];
	}

	skillTotalXP[Foraging] += resOut * 10;
	skillXP[Foraging] += resOut * 10;
	expirience += resOut * 10;

	std::system("cls");
	std::cout << "You got " << resOut << " Hp...";
	std::system("pause>nul");

	location = saveLocation;
}

void brewHp()
{
	if (resources[Gold] >= hpPotPrice)
	{
		resources[Gold] -= hpPotPrice;
		potions[Hp] += 1;
	}
	location = saveLocation;
}

void brewSta()
{
	if (resources[Gold] >= staPotPrice)
	{
		resources[Gold] -= staPotPrice;
		potions[Stamina] += 1;
	}
	location = saveLocation;
}

void pirateTrivia()
{
	using std::cout;
	int x{};
	std::system("cls");

	std::cout << "1. How Many Islands Are On Evark?(Write 0 To Exit)" << "\n\n";
incorrect:
	std::cin >> x;

	if (x == 0)
	{
		location = PirateCove;

	}
	else if (x == 276 || x == 274)
	{

		int y{};
		std::system("cls");

		std::cout << "2. About How Old Is Halton (in C.E.)?(Write 0 To Exit)" << "\n\n";

	wrong:
		std::cin >> y;

		if (y == 200)
		{
			int z{};
			std::system("cls");

			std::cout << "3. How Many Billion Years Ago Was Evark Formed?(Write 0 To Exit)" << "\n\n";

		dumb:
			std::cin >> z;
			if (z == 6)
			{

				std::system("cls");

				std::cout << "Congratulations You Win 5.000 Gold Coins" << "\n\n";
				resources[Gold] += 5;
				outputInfo();
				std::system("pause >nul");
				location = Road6;
			}
			else if (z == 0)
			{
				location = PirateCove;
			}
			else
			{
				goto dumb;
			}
		}
		else if (y == 0)
		{
			location = PirateCove;
		}
		else
		{
			goto wrong;
		}
	}
	else
	{
		goto incorrect;
	}
}

void bridgeRiddles()
{
	using std::cout;
	int x{};
	std::system("cls");

	std::cout << "The troll says the first riddle..\n"; 
	std::cout <<"\n0 - Give up";
	if (stats[Intelligence] > 5)
	{
		std::cout << "\n1 - Answer";
	}
	std::cout << "\n\n";

	incorrect:
	std::cin >> x;

	if (x == 0)
	{
		location = BridgeToLibrary;

	}
	else if (stats[Intelligence] > 5 && x == 1)
	{

		int y{};
		std::system("cls");


		std::cout << "Correct.\nThen the troll says the second riddle..\n";
		std::cout << "\n0 - Give up";
		if (stats[Intelligence] > 10)
		{
			std::cout << "\n1 - Answer";
		}
		std::cout << "\n\n";

	wrong:
		std::cin >> y;

		if (stats[Intelligence] > 10 && y == 1)
		{
			int z{};
			std::system("cls");

			std::cout << "Correct.\nThen the troll says the third riddle..\n";
			std::cout << "\n0 - Give up";
			if (stats[Intelligence] > 15)
			{
				std::cout << "\n1 - Answer";
			}
			std::cout << "\n\n";

		dumb:
			std::cin >> z;
			if (stats[Intelligence] > 15 && z == 1)
			{

				std::system("cls");

				std::cout << "Congratulations You Win get to pass and also this COOL HAT" << "\n\n";
				questDone[MadthorneBridgeQuest] = true;
				std::system("pause >nul");
				location = MadthorneLibrary;
			}
			else if (z == 0)
			{
				location = BridgeToLibrary;
			}
			else
			{
				goto dumb;
			}
		}
		else if (y == 0)
		{
			location = BridgeToLibrary;
		}
		else
		{
			goto wrong;
		}
	}
	else
	{
		goto incorrect;
	}
}

void marioBrick()
{
	std::system("cls");

	int what{ rand() % 100 };
	
	if (what >= 50)
	{
		std::cout << "A mushroom falls out of it and you eat it...\n";
		std::system("pause>nul");
		std::cout << "You feal stronger(+5 Strength)...";
		std::system("pause>nul");
		stats[Strength] += 5;
	}
	else
	{
		std::cout << "A coin falls out...";
		std::system("pause>nul");
		std::cout << "(+ 10 gold)";
		std::system("pause>nul");
	}

	questDone[PunchBrickQuest] = true;
	location = MadthornePrincessRoom;
}