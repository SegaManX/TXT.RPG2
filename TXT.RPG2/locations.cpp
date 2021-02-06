#include "allInclude.h"



void changeLocation();
void enterLocation(int options, std::string upperText, bool outputStats, bool outputBackpack, std::string optionText, long long (&optionsEff)[100]);

long long location{};
long long lastLocation{};
long long saveLocation{};
long long deepSaveLocation{};
long long city{};

int cityID{};
int terrain{};
int pcg{};

long long optionEff[100]{};
std::string tOptions{};
int options{};
std::string topText{ };
bool showInfo{};
bool showBackpack{};

// mbe config
int sleepCost{ 25 };
int foodCost{ 10 };
int drinkCost{ 5 };
int hpPotPrice{ 20 };
int staPotPrice{ 20 };

// Change Location

void changeLocation()
{

	switch (location)
	{
	case Win:
	{
		terrain = 0;
		win();
		break;
	}
	case Die:
	{
		terrain = 0;

		std::cout << "shize";
		die();
		break;
	}
	case Save:
	{
		terrain = 0;

		save();

		break;
	}
	case Load:
	{
		terrain = 0;

		load();

		break;
	}
	case Exit:
	{
		booLeans[Won] = true;
		break;
	}
	case Battle:
	{
		terrain = 0;

		battle();

		break;
	}
	case BattleSetup:
	{
		terrain = 0;

		battleSetup();

		break;
	}
	case Attack:
	{
		terrain = 0;

		attack();

		break;
	}
	case PostAttack:
	{
		terrain = 0;

		postAttack();

		break;
	}
	case ChangeTarget:
	{
		terrain = 0;

		changeTarget();

		break;
	}
	case AttackInventory:
	{
		terrain = 0;

		attackInventory();

		break;
	}
	case ChangeWeapon:
	{
		terrain = 0;

		changeWeapon();

		break;
	}
	case FightSpells:
	{
		terrain = 0;

		fightSpells();

		break;
	}
	case FightStats:
	{
		terrain = 0;

		fightStats();

		break;
	}
	case TargetEnemyStats:
	{
		terrain = 0;

		targetEnemyStats();

		break;
	}
	case AttackS:
	{
		terrain = 0;
		if (lastSpell != 0)
		{
			attack(true);
		}
		else
		{
			attack();
		}
		break;
	}
	case Backpack:
	{
		terrain = 0;

		optionEff[0] = deepSaveLocation;
		optionEff[1] = StatScreen;
		optionEff[2] = SkillScreen;
		optionEff[3] = Inventory;
		optionEff[4] = Backpack; // Change when add questScreen
		optionEff[5] = Exit;
		
		enterLocation(
			6,
			"Main Menu: ",
			true,
			false,
			"0 - Continue Game\n1 - Stats\n2 - Skills\n3 - Inventory\n4 - Quests(W.I.P.)\n5 - Exit Game",
			optionEff);
		break;
	}
	case StatScreen:
	{
		terrain = 0;
		statScreen();
		break;
	}
	case SkillScreen:
	{
		terrain = 0;
		skillScreen();
		break;
	}
	case Inventory:
	{
		terrain = 0;


		long long optionEff[100]{ Backpack, ResourceScreen, ItemScreen, MagicScreen, PotionScreen};

		enterLocation(
			5,
			"Inventory: ",
			true,
			false,
			"0 - Back\n1 - Resources\n2 - Items\n3 - Spells\n4 - Potions",
			optionEff);
		break;
	}
	case ResourceScreen:
	{
		terrain = 0;
		resourceScreen();
		break;
	}
	case ItemScreen:
	{
		terrain = 0;
		itemScreen();
		break;
	}
	case MagicScreen:
	{
		terrain = 0;
		magicScreen();
		break;
	}
	case PotionScreen:
	{
		terrain = 0;
		potionScreen();
		break;
	}
	case PotionScreenB:
	{
		terrain = 0;
		potionScreenB();
		break;
	}
	case Home:
	{
		terrain = 0;
		
		optionEff[0] = city;
		optionEff[1] = SleepHome;
		optionEff[2] = Save;
		optionEff[3] = TrainingFight;

		enterLocation(
			4,
			"You are at Home...",
			true,
			true,
			"0 - Exit Your House\n1 - Sleep\n2 - Save\n3 - Training Battle",
			optionEff);
		break;
	}
	case HaltonCity:
	{
		terrain = 0;
		city = HaltonCity;
		cityID = CityHalton;

		optionEff[0] = Home;
		optionEff[1] = HaltonTavern;
		optionEff[2] = HaltonAlley;
		optionEff[3] = Shop;
		optionEff[4] = HaltonLibrary;
		optionEff[5] = HaltonKingsGuard;
		optionEff[6] = Smithery;
		optionEff[7] = Mine;
		optionEff[8] = HaltonForest;
		optionEff[9] = Stables;
		optionEff[10] = Port;
		optionEff[11] = HaltonRoadGuard;

		enterLocation(
			12,
			"You are at Halton City...",
			true,
			true,
			"0 - Go Home\n1 - Go To The Tavern\n2 - Go To Alley\n3 - Go To The Shop\n4 - Go To The Library\n5 - Go To Kings Palace\n6 - Go To Smithery\n7 - Go To Mine\n8 - Go To The Forest\n9 - Go To The Stables\n10 - Go To The Port\n11 - Leave Town",
			optionEff);

		break;
	}
	case HaltonTavern:
	{
		terrain = 0;

		optionEff[0] = HaltonCity;
		optionEff[1] = Drink;
		optionEff[2] = Eat;
		optionEff[3] = SleepTavern;
		optionEff[4] = Quest1;

		enterLocation(
			5,
			"You are at the Halton Tavern...",
			true,
			true,
			"0 - Leave Tavern\n1 - Drink(" + std::to_string(drinkCost) + "G)\n2 - Eat(" + std::to_string(foodCost) + "G)\n3 - Rest(" + std::to_string(sleepCost) + "G)\n4 - ?:Clean Out Alley",
			optionEff);
		break;
	}
	case HaltonAlley:
	{
		terrain = 0;

		tOptions = "0 - Leave";
		options = 1;
		topText = "You see an empty alley...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = HaltonCity;

		if (!questDone[HaltonAlleyBanditQuest])
		{
			optionEff[1] = AlleyBanditFight;
			tOptions += "\n1 - ? : Fight them";
			options = 2;
			topText = "You see some suspicious people...";
		}

		enterLocation(options, topText, showInfo, showBackpack,	tOptions, optionEff);
		break;
	}
	case Shop:
	{
		terrain = 0;

		optionEff[0] = city;
		optionEff[1] = BuyWeapons;
		optionEff[2] = BuyArmour;
		optionEff[3] = EnchantGear;

		enterLocation(
			4,
			"You look around the shop...",
			true,
			true,
			"0 - Leave Shop\n1 - Buy Weapons\n2 - Buy Armour\n3 - Enchant Weapons/Armour",
			optionEff);
		break;
	}
	case HaltonLibrary:
	{
		terrain = 0;

		tOptions = "0 - Leave Library\n1 - 4  - Read books";
		options = 5;
		topText =  "You are at The Library..." ;
		showInfo = true;
		showBackpack = true;

		optionEff[0] = city;
		optionEff[1] = Book1;
		optionEff[2] = Book2;
		optionEff[3] = Book3;
		optionEff[4] = Book4;

		if (stats[Intelligence] < 5)
		{
			tOptions = "0 - Leave";
			options = 1;
			topText = "You can't read...";
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case HaltonKingsGuard:
	{
		terrain = 0;

		tOptions = "0 - Leave";
		options = 1;
		topText = "Guard 1: You are not allowed to enter\nGuard 2: May be if you kill the bandit king you could enter\nGuard 1: I heard he has a hideout somewhere in the forest.";
		showInfo = false;
		showBackpack = false;
		questStarted[BanditHideoutQuest] = true;

		optionEff[0] = HaltonCity;

		if (questDone[BanditHideoutQuest])
		{
			optionEff[1] = HaltonKingsPalace;
			tOptions += "\n1 - ? : Enter";
			options = 2;
			topText = "Guard: You may enter";
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case HaltonKingsPalace:
	{
		terrain = 0;

		tOptions = "0 - Leave";
		options = 1;
		topText =  "King: My daugther has been stolen by Greg the Dark. Talk to the king in the next town he should know where GREG is.";
		showInfo =  false;
		showBackpack = false;

		optionEff[0] = HaltonCity;

		if (questDone[PrincessQuest])
		{
			topText = "King: Thank you for saving my daughter. I will give you one of my finest boat for that.";
			booLeans[HasBoat] = true;
			questFinished[PrincessQuest] = true;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;	
	}
	case Smithery:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Melt ores\n2 - Make Alloys\n3 - Craft Gear\n4 - Repair Gear";
		options = 5;
		topText = "You are at the Smithery...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = city;
		optionEff[1] = MeltOre;
		optionEff[2] = MakeAlloys;
		optionEff[3] = CraftGear;
		optionEff[4] = RepairGear;

		if (!questDone[SmitheryAccessQuest])
		{
			optionEff[0] = city;
			optionEff[1] = SmitheryQuest;

			tOptions = "0 - Leave\n1 - ? : Talk to Owner";
			options = 2;
			topText = "You can't enter the Smithery...";
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Mine:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Mine Iron ore\n2 - Mine Adamantine ore";
		options = 3;
		topText = "You are at the Mine...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = city;
		optionEff[1] = MineIron;
		optionEff[2] = MineAdamantine;

		if (!questDone[MineAccessQuest])
		{
			optionEff[1] = MineQuest;
			tOptions = "0 - Leave\n1 - ? : Talk to Owner";
			options = 2;
			topText = "You can't enter the Mine...";
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case HaltonForest:
	{
		terrain = 0;

		options = 4;
		tOptions = "0 - Leave\n1 - Chop Wood\n2 - Forage\n3 - Hunt(W.I.P.)";
		topText = "You are at the Forest...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = city;
		optionEff[1] = Lumberyard;
		optionEff[2] = Forage;
		optionEff[3] = Hunt;

		if (!questDone[WolfAttackQuest])
		{
			tOptions += "\n" + std::to_string(options) + " - ?:You hear a man screaming for help";
			optionEff[options] = WolfFight;
			options += 1;
		}
		if (questStarted[BanditHideoutQuest] && !questDone[BanditHideoutQuest])
		{
			tOptions += "\n" + std::to_string(options) + " - ?:You spot a suspicious cave";
			optionEff[options] = BanditHideout1;
			options += 1;
		}
		

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);

		break;
	}
	case Stables:
	{
		std::system("cls");
		std::cout << "Go home this is under construction";
		std::system("pause>nul");

		location = Home;
		break;
	}
	case Port:
	{
		std::system("cls");
		std::cout << "Go home this is under construction";
		std::system("pause>nul");

		location = Home;
		break;	
	}
	case Lumberyard:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Chop Wood";
		options = 2;
		topText = "You are at the Lumberyard...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = HaltonForest;
		optionEff[1] = ChopWood;

		if (!questDone[LumberyardAccessQuest])
		{
			optionEff[1] = LumberyardQuest;
			tOptions = "0 - Leave\n1 - ? : Talk to Owner";
			options = 2;
			topText = "You can't enter the Lumberyard...";
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case BanditHideout1:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Attack them";
		options = 2;
		topText = "You are near the Hideout. You see two lookouts at the enterance.";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = city;
		optionEff[1] = BanditHideoutLookoutFight;
		
		if (skillLevel[Stealth] >= 3)
		{
			optionEff[2] = BanditHideout2;
			tOptions += "\n2 - Sneak around them";
			options = 3;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case BanditHideout2:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Attack them";
		options = 2;
		topText = "You are in the Hideout. You see four guards at the enterance to the bandit kings chambers.";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = city;
		optionEff[1] = BanditHideoutGuardFight;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case BanditHideout3:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Attack them";
		options = 2;
		topText = "You are outside the bandit kings chambers. You see four guards at the enterance.";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = city;
		optionEff[1] = BanditHideoutKingFight;

		if (skillLevel[Stealth] >= 3)
		{
			optionEff[2] = BanditHideout2;
			tOptions += "\n2 - Sneak around them";
			options = 3;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case HaltonRoadGuard:
	{
		terrain = 0;

		tOptions = "0 - Stay";
		options = 1;
		topText = "Guard 1: You are not allowed to leave the city\nGuard 2: It is dangerous out there\nGuard 1: Only those that the king approves can leave.";
		showInfo = false;
		showBackpack = false;

		optionEff[0] = HaltonCity;

		if (questStarted[RoadGuardHaltonQuest])
		{
			optionEff[1] = Road1;
			tOptions += "\n1 - ? : Leave";
			options = 2;
			topText = "Guard: You may leave the city";
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Road1:
	{
		

		if (cityID == CityHalton)
		{
			terrain = 0;

			tOptions = "0 - Go back\n1 - Go left\n2 - Go right";
			options = 3;
			topText = "You see the road branch out";
			showInfo = false;
			showBackpack = false;

			optionEff[0] = HaltonCity;
			optionEff[1] = Road2;
			optionEff[2] = RoadBanditFight;
		}
		else
		{
			terrain = 0;

			tOptions = "0 - Go to Halton\n1 - Go back right\n2 - Go back left";
			options = 3;
			topText = "You see the roads join back up";
			showInfo = false;
			showBackpack = false;

			optionEff[0] = HaltonCity;
			optionEff[1] = Road2;
			optionEff[2] = RoadBanditFight;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Road2:
	{


		if (cityID == CityHalton)
		{
			terrain = 0;

			tOptions = "0 - Go back left\n1 - Go back right\n2 - Go to Tarrin";
			options = 3;
			topText = "You see the roads join back up";
			showInfo = false;
			showBackpack = false;

			optionEff[0] = Road1;
			optionEff[1] = RoadBanditFight;
			optionEff[2] = TarrinCity;
		}
		else
		{
			terrain = 0;

			tOptions = "0 - Go back\n1 - Go left\n2 - Go right";
			options = 3;
			topText = "You see the road branch out";
			showInfo = false;
			showBackpack = false;

			optionEff[0] = TarrinCity;
			optionEff[1] = RoadBanditFight;
			optionEff[2] = Road2;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case TarrinCity:
	{
		terrain = 0;
		city = TarrinCity;
		cityID = CityTarrin;

		showInfo = true;
		showBackpack = true;

		tOptions = "0 - Go To Halton\n1 - Wander The City\n2 - Go To The Kings Palace";
		topText = "You are at Tarrin City...";

		options = 3;
		optionEff[0] = Road2;
		optionEff[1] = TarrinFight;
		optionEff[2] = TarrinKingsGuard;
		if (questStarted[LichQuest] && !questDone[LichQuest])
		{

			tOptions += "\n4 - Go to the Cemetary";

			options = 4;
			optionEff[3] = TarCem1;
		}

		if (questFinished[LichQuest])
		{
			optionEff[0] = Road2;
			optionEff[1] = Tavern;
			optionEff[2] = Shop;
			optionEff[3] = TarrinLibrary;
			optionEff[4] = TarrinKingsGuard;
			optionEff[5] = Smithery;
			optionEff[6] = Mine;
			optionEff[7] = Stables;
			optionEff[8] = TarrinRoadGuard;
		
			tOptions = "0 - Go To Halton\n1 - Go To The Tavern\n2 - Go To The Shop\n3 - Go To The Library\n4 - Go To Kings Palace\n5 - Go To Smithery\n6 - Go To Mine\n7 - Go To The Stables\n8 - Go to Madthorne";
			options = 9;
		}
		
		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Tavern:
	{
		terrain = 0;

		optionEff[0] = city;
		optionEff[1] = Drink;
		optionEff[2] = Eat;
		optionEff[3] = SleepTavern;

		enterLocation(
			4,
			"You are at the Tavern...",
			true,
			true,
			"0 - Leave Tavern\n1 - Drink(" + std::to_string(drinkCost) + "G)\n2 - Eat(" + std::to_string(foodCost) + "G)\n3 - Rest(" + std::to_string(sleepCost) + "G)",
			optionEff);
		break;
	}
	case TarrinLibrary:
	{
		terrain = 0;

		tOptions = "0 - Leave Library\n1 - 4  - Read books";
		options = 5;
		topText = "You are at The Library...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = city;
		optionEff[1] = Book5;
		optionEff[2] = Book6;
		optionEff[3] = Book7;
		optionEff[4] = Book8;
			
		if (stats[Intelligence] < 5)
		{
			tOptions = "0 - Leave";
			options = 1;
			topText = "You can't read...";
		}
			
		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	
	}
	case TarrinKingsGuard:
	{
		terrain = 0;

		tOptions = "0 - Stay outside\n1 - ? : Enter";
		topText = "Guard 1: Perish you fowl beast\nGuard 2: Wait you're not one of them.\nGuard 1: Quick come in before they attack you.";
		showInfo = false;
		showBackpack = false;

		optionEff[0] = TarrinCity;
		optionEff[1] = TarrinKingsPalace;
		options = 2;
		
		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case TarrinKingsPalace:
	{
		terrain = 0;

		tOptions = "0 - Leave";
		options = 1;
		topText = "King: The entire town has been filled with the undead. The Lich has summoned them.\nBut thankfully they can't get in here because a bishop blessed this place. If you kill the Lich everything should go back to normal.\nI heard there is a map that should lead you to the Lich\n Kill some of his minions one of them ought to have it.\nWhen you get it bring it to me to decode it.";
		showInfo = false;
		showBackpack = false;
		questStarted[LichMapQuest] = true;

		optionEff[0] = TarrinCity;
		if (questDone[LichMapQuest])
		{
			topText = "King: Great saviour you have returned with the map. It looks like he is based at the old cemetary. Seems obvious in retrospect.";
			questFinished[LichMapQuest] = true;
			questStarted[LichQuest] = true;
		}
		if (questDone[LichQuest])
		{
			options = 1;
			topText = "King: Thank you for killing the Lich. GREG has been spotted near Madthorne.";
			questFinished[LichQuest] = true;
			
		}
		else if (questDone[CleanTarrinQuest] && !questFinished[CleanTarrinQuest])
		{
			questFinished[CleanTarrinQuest] = true;
			options = 1;
			topText = "King: Thank you for cleaning up my town. Here is 1000 gold.";
			resources[Gold] += 1000;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case TarrinRoadGuard:
	{
		terrain = 0;

		tOptions = "0 - Stay";
		options = 1;
		topText = "Guard 1: You are not allowed to leave the city\nGuard 2: It is dangerous out there\nGuard 1: Only those that the king approves can leave.";
		showInfo = false;
		showBackpack = false;

		optionEff[0] = TarrinCity;

		if (questFinished[LichQuest])
		{
			optionEff[1] = Road3;
			tOptions += "\n1 - ? : Leave";
			options = 2;
			topText = "Guard: You may leave the city";
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case TarCem1:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Enter";
		topText = "You see four zombies guarding the enterance to the cemetary.";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = TarrinCity;
		optionEff[1] = TarCem1Fight;
		options = 2;

		if (skillLevel[Stealth] >= 15)
		{
			optionEff[2] = TarCem2;
			tOptions += "\n2 - Sneak around them";
			options = 3;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case TarCem2:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Fight";
		topText = "You see four shadows in the cemetary.";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = TarrinCity;
		optionEff[1] = TarCem2Fight;
		options = 2;

		if (skillLevel[Stealth] >= 25)
		{
			optionEff[2] = TarCem3;
			tOptions += "\n2 - Sneak around them";
			options = 3;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case TarCem3:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Fight";
		topText = "You see four skeletons guarding a mausoleum.";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = TarrinCity;
		optionEff[1] = TarCem3Fight;
		options = 2;

		if (skillLevel[Stealth] >= 20)
		{
			optionEff[2] = TarCem4;
			tOptions += "\n2 - Sneak around them";
			options = 3;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case TarCem4:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Fight";
		topText = "You see the Lich and his bodyguards in the mausoleum.";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = TarrinCity;
		optionEff[1] = TarCem4Fight;
		options = 2;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Road3:
	{
		if (cityID == CityTarrin)
		{
			terrain = 0;

			tOptions = "0 - Go back\n1 - Go right\n2 - Go left\n3 - Go straight";
			options = 4;
			topText = "The Path Goes In Three Directions...";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = TarrinCity;
			optionEff[1] = Road4;
			optionEff[2] = Road9;
			optionEff[3] = Road7;
		}
		else
		{
			terrain = 0;

			tOptions = "0 - Go to Tarrin\n1 - Go back right\n2 - Go back left\n3 - Go back";
			options = 4;
			topText = "You see the roads join back up";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = TarrinCity;
			optionEff[1] = Road4;
			optionEff[2] = Road9;
			optionEff[3] = Road7;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Road4:
	{
		if (cityID == CityTarrin)
		{
			terrain = 0;

			tOptions = "0 - Go back\n1 - Forage\n2 - Keep going";
			options = 3;
			topText = "You See Some Blue Berries Next To The Path...";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = Road3;
			optionEff[1] = Forage;
			optionEff[2] = Road5;
		}
		else
		{
			terrain = 0;

			tOptions = "0 - Go back\n1 - Forage\n2 - Keep going";
			options = 3;
			topText = "You See Some Blue Berries Next To The Path...";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = Road5;
			optionEff[1] = Forage;
			optionEff[2] = Road3;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;

	}
	case Road5:
	{
		if (cityID == CityTarrin)
		{
			terrain = 0;

			tOptions = "0 - Go back\n1 - Forage\n2 - Keep going";
			options = 3;
			topText = "You See A Weird Hut Next To The Path...";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = Road4;
			optionEff[1] = Witch;
			optionEff[2] = Road6;
		}
		else
		{
			terrain = 0;

			tOptions = "0 - Go back\n1 - Forage\n2 - Keep going";
			options = 3;
			topText = "You See A Weird Hut Next To The Path...";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = Road6;
			optionEff[1] = Witch;
			optionEff[2] = Road4;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;

	}
	case Witch:
	{
		terrain = 0;

		tOptions = "0 - Go back\n1 - Brew Hp Potion" + std::to_string(hpPotPrice) + "\n2 - Brew Sta Potion" + std::to_string(staPotPrice);
		options = 3;
		topText = "Witch: You can buy the ingrediants from me but you have to brew your own potions...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Road5;
		optionEff[1] = BrewHp;
		optionEff[2] = BrewSta;
		
		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Road6:
	{
		if (cityID == CityTarrin)
		{
			terrain = 0;

			tOptions = "0 - Go back\n1 - Keep going";
			options = 2;
			topText = "You See A Town On The Horizon";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = Road5;
			optionEff[1] = Madthorne;
		}
		else
		{
			terrain = 0;

			tOptions = "0 - Go back\n1 - Keep going";
			options = 2;
			topText = "You Are Exiting The Town Limits...";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = Madthorne;
			optionEff[1] = Road5;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;

	}
	case Road7:
	{
			terrain = 0;

			tOptions = "0 - Go back\n1 - Keep going";
			options = 2;
			topText = "You Hear Something Weird";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = Road3;
			optionEff[1] = OldPirateFight;
		

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;

	}
	case Road8:
	{
		
			terrain = 0;

			tOptions = "0 - Go back\n1 - Keep going";
			options = 2;
			topText = "You Hear Pirates";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = Road7;
			optionEff[1] = PirateCove;
		

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;

	}
	case PirateCove:
	{
		terrain = 0;

		tOptions = "0 - Go back\n1 - Keep going\n2 - Try";
		options = 3;
		topText = "You Hear Something Weird";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Road8;
		optionEff[1] = Road6;
		optionEff[2] = PirateTrivia;


		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Road9:
	{
		terrain = 0;

		tOptions = "0 - Go back\n1 - Keep going";
		options = 2;
		topText = "You Are Lost";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Road3;
		optionEff[1] = Road10;


		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Road10:
	{
		terrain = 0;

		tOptions = "0 - Go back\n1 - Keep going";
		options = 2;
		topText = "You Are Lost";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Road4;
		optionEff[1] = Road9;


		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Madthorne:
	{
		terrain = 0;
		city = Madthorne;
		cityID = CityMadthorne;

		showInfo = true;
		showBackpack = true;

		tOptions = "0 - Go To Tarrin\n1 - Go To The Tavern\n2 - Go To The Shop\n3 - Go To The Library\n4 - Go To The Castle\n5 - Go To Smithery\n6 - Go To Mine\n7 - Go To The Stables";
		topText = "You are at Madthorne...";

		options = 8;
		optionEff[0] = Road6;
		optionEff[1] = MadthorneTavern;
		optionEff[2] = Shop;
		optionEff[3] = BridgeToLibrary;
		optionEff[4] = MadthorneCastle;
		optionEff[5] = Smithery;
		optionEff[6] = MadthorneGoblinMine;
		optionEff[7] = Stables;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case MadthorneTavern:
	{
		terrain = 0;

		optionEff[0] = city;
		optionEff[1] = Drink;
		optionEff[2] = Eat;
		optionEff[3] = SleepTavern;
		optionEff[4] = Quest2;

		enterLocation(
			5,
			"You are at the Tavern...",
			true,
			true,
			"0 - Leave Tavern\n1 - Drink(" + std::to_string(drinkCost) + "G)\n2 - Eat(" + std::to_string(foodCost) + "G)\n3 - Rest(" + std::to_string(sleepCost) + "G)" + "\n4 - Ask around for GREG",
			optionEff);
		break;
	}
	case BridgeToLibrary:
	{
		terrain = 0;

		showInfo = true;
		showBackpack = true;

		if (!questDone[MadthorneBridgeQuest])
		{
			tOptions = "0 - Go Back\n1 - Answer the Riddles\n2 - Fight him";
			topText = "A troll stops you...\nTroll: Answer my riddles three to pass";

			options = 3;
			optionEff[0] = Madthorne;
			optionEff[1] = BridgeRiddles;
			optionEff[2] = BridgeFight;
		}
		else
		{
			tOptions = "0 - Go Back\n1 - Go to library";
			topText = "You are on a bridge...";

			options = 2;
			optionEff[0] = Madthorne;
			optionEff[1] = MadthorneLibrary;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case MadthorneLibrary:
	{
		
			terrain = 0;

			tOptions = "0 - Leave Library\n1 - 4  - Read books";
			options = 5;
			topText = "You are at The Library...";
			showInfo = true;
			showBackpack = true;

			optionEff[0] = city;
			optionEff[1] = Book9;
			optionEff[2] = Book10;
			optionEff[3] = Book11;
			optionEff[4] = Book12;

			if (stats[Intelligence] < 5)
			{
				tOptions = "0 - Leave";
				options = 1;
				topText = "You can't read...";
			}

			enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
			break;

		
	}
	case MadthorneCastle:
	{
		terrain = 0;

		tOptions = "0 - Go back\n1 - Fight them";
		options = 2;
		topText = "You are at the castle lobby and suddently three goblins are running at you...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Madthorne;
		optionEff[1] = MadthorneCastleFight1;

		if (questDone[MadthorneCastleQuest])
		{
			tOptions = "0 - Go back\n1 - Go to The Portal";
			options = 2;
			topText = "You are at the castle\nIt looks empty but perfectly clean...";
			optionEff[1] = MadthornePrincessRoom;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case MadthorneCastleTowerDoors:
	{
		terrain = 0;

		tOptions = "0 - Go back\n1 - Fight them";
		options = 2;
		topText = "You see some doors with some orcs gurading them...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Madthorne;
		optionEff[1] = MadthorneCastleFight2;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case MadthorneCastleTower:
	{
		terrain = 0;

		tOptions = "0 - Go back\n1 - Fight him";
		options = 2;
		topText = "You see a Dragon...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Madthorne;
		optionEff[1] = MadthorneCastleFight3;

		if (stats[Perception] > 15 && !questDone[MadthorneTreasure])
		{
			tOptions += "\n2 - Go to Treasure Room";
			options = 3;
			optionEff[2] = MadthorneCastleTreasureRoom;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case MadthorneCastleTreasureRoom:
	{
		terrain = 0;

		tOptions = "0 - Go back\n1 - Fight them";
		options = 2;
		topText = "You are at the treasure room but a group of trolls and orc knights are guarding it...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Madthorne;
		optionEff[1] = MadthorneCastleFight4;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case MadthornePrincessRoom:
	{
		terrain = 0;

		tOptions = "1 - Touch The Glow";
		options = 2;
		topText = "You come to the princeses room...\nYou see a note: GREG was here\nMaid: Sorry " + playerName + " The Princess Is In Another Castle\nBut you see a weird glow from the wall";
		showInfo = true;
		showBackpack = true;

		questDone[MadthorneCastleQuest] = true;

		optionEff[0] = Madthorne;
		optionEff[1] = Dunkelland;

		if (stats[Perception] > 10 && !questDone[PunchBrickQuest])
		{
			topText += "\nYou also see a weird red brick above you";
			tOptions += "\n2 - Hit It";
			options = 3;
			optionEff[2] = MarioBrick;
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case MadthorneGoblinMine:
	{
		terrain = 0;

		tOptions = "0 - Go back\n1 - Fight them";
		options = 2;
		topText = "You are at the mine, but a lot of goblins are blocking the enterance...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Madthorne;
		optionEff[1] = MadthorneGoblinMineFight;

		if (questDone[MadthorneGoblinMineQuest])
		{
			tOptions = "0 - Go back";
			options = 1;
			topText = "You are at the mine, but there is nothing to mine...";
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case Dunkelland:
	{
		terrain = 0;
		city = Dunkelland;
		cityID = CityDunkelland;

		showInfo = true;
		showBackpack = true;

		tOptions = "0 - Go To Madthorne\n1 - Go To The Tavern\n2 - Go To The Dark Castle";
		topText = "You are at Dunkelland...";

		options = 3;
		optionEff[0] = MadthornePrincessRoom;
		optionEff[1] = DunkellandTavern;
		optionEff[2] = DarkCastle;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case DunkellandTavern:
	{
		terrain = 0;

		optionEff[0] = city;

		enterLocation(
			1,
			"You are at the Tavern but it is empty...",
			true,
			true,
			"0 - Leave Tavern",
			optionEff);
		break;
	}
	case DarkCastle:
	{
		terrain = 0;

		tOptions = "0 - Go back\n1 - Go to her";
		options = 2;
		topText = "You are at the castle and you hear the princess screaming for help...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Dunkelland;
		optionEff[1] = DarkCastleFight;

		if (questDone[PrincessQuest])
		{
			options = 1;
			topText = "You are at the dark castle...";
		}

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		break;
	}
	case TrainingFight:
	{
		terrain = 0;
		trainingFight();
		break;
	}
	case AlleyBanditFight:
	{
		terrain = 0;
		alleyBanditFight();
		break;
	}
	case WolfFight:
	{
		terrain = 0;
		wolfFight();
		break;
	}
	case RoadBanditFight:
	{
		terrain = 0;

		roadBanditFight();

		break;
	}
	case BanditHideoutLookoutFight:
	{
		terrain = 0;

		banditHideoutLookoutFight();

		break;
	}
	case BanditHideoutGuardFight:
	{
		terrain = 0;

		banditHideoutGuardFight();

		break;
	}
	case BanditHideoutKingFight:
	{
		terrain = 0;

		banditHideoutKingFight();

		break;
	}
	case TarrinFight:
	{
		terrain = 0;
		tarrinFight();
		break;
	}
	case TarCem1Fight:
	{
		terrain = 0;
		tarCem1Fight();
		break;
	}
	case TarCem2Fight:
	{
		terrain = 0;
		tarCem2Fight();
		break;
	}
	case TarCem3Fight:
	{
		terrain = 0;
		tarCem3Fight();
		break;
	}
	case TarCem4Fight:
	{
		terrain = 0;
		tarCem4Fight();
		break;
	}
	case OldPirateFight:
	{
		terrain = 0;
		oldPirateFight();
		break;
	}
	case BridgeFight:
	{
		terrain = 0;
		bridgeFight();
		break;
	}
	case MadthorneGoblinMineFight:
	{
		terrain = 0;
		madthorneGoblinMineFight();
		break;
	}
	case MadthorneCastleFight1:
	{
		terrain = 0;
		madthorneCastleFight1();
		break;
	}
	case MadthorneCastleFight2:
	{
		terrain = 0;
		madthorneCastleFight2();
		break;
	}
	case MadthorneCastleFight3:
	{
		terrain = 0;
		madthorneCastleFight3();
		break;
	}
	case MadthorneCastleFight4:
	{
		terrain = 0;
		madthorneCastleFight4();
		break;
	}
	case DarkCastleFight:
	{
		terrain = 0;
		darkCastleFight();
		break;
	}
	case SleepHome:
	{
		terrain = 0;
		sleepHome();
		break;
	}
	case Eat:
	{
		terrain = 0;

		eat();
		break;
	}
	case Drink:
	{
		terrain = 0;

		drink();
		break;
	}
	case SleepTavern:
	{
		terrain = 0;

		sleepTavern();
		break;
	}
	case BuyWeapons:
	{
		terrain = 0;

		buyWeapons();
		break;
	}
	case MeltOre:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Melt Iron ore\n2 - Melt Adamantine ore";
		options = 3;
		topText = "What do you want to melt...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Smithery;
		optionEff[1] = MeltIron;
		optionEff[2] = MeltAdamantine;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);

		break;
	}
	case MeltIron:
	{
		terrain = 0;
		meltOre(Iron_ore);
		break;
	}
	case MeltAdamantine:
	{
		terrain = 0;
		meltOre(Adamantine_ore);
		break;
	}
	case MakeAlloys:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Make Steel";
		options = 2;
		topText = "What do you want to make...";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Smithery;
		optionEff[1] = MakeSteel;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);


		break;
	}
	case MakeSteel:
	{
		terrain = 0;

		makeAlloys(Steel);

		break;
	}
	case CraftGear:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Wood\n2 - Iron\n3 - Steel\n4 - Adamantine";
		options = 5;
		topText = "What do you want to make it from?";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Smithery;
		optionEff[1] = PickCraftGearWood;
		optionEff[2] = PickCraftGearIron;
		optionEff[3] = PickCraftGearSteel;
		optionEff[4] = PickCraftGearAdamantine;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);


		break;
	}
	case PickCraftGearWood:
	{
		terrain = 0;
		pcg = Wood;
		location = PickCraftGear;
		break;
	}
	case PickCraftGearIron:
	{
		terrain = 0;
		pcg = Iron;
		location = PickCraftGear;
		break;
	}
	case PickCraftGearSteel:
	{
		terrain = 0;
		pcg = Steel;
		location = PickCraftGear;
		break;
	}
	case PickCraftGearAdamantine:
	{
		terrain = 0;
		pcg = Adamantine;
		location = PickCraftGear;
		break;
	}
	case PickCraftGear:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Sword\n2 - Bow\n3 - Staff\n4 - Armour(W.I.P.)";
		options = 5;
		topText = "What do you want to make?";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = CraftGear;
		optionEff[1] = CraftSword;
		optionEff[2] = CraftBow;
		optionEff[3] = CraftStaff;
		optionEff[4] = PickCraftGear;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);


		break;
	}
	case CraftSword:
	{
		terrain = 0;

		craftGear(Sword, pcg);
		
		break;
	}
	case CraftBow:
	{
		terrain = 0;

		craftGear(Bow, pcg);

		break;
	}
	case CraftStaff:
	{
		terrain = 0;

		craftGear(Staff, pcg);

		break;
	}
	case RepairGear:
	{
		terrain = 0;

		tOptions = "0 - Leave\n1 - Equipped Weapon";
		options = 2;
		topText = "What do you want to Repair?";
		showInfo = true;
		showBackpack = true;

		optionEff[0] = Smithery;
		optionEff[1] = RepairWeapon;

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);


		break;
	}
	case RepairWeapon:
	{
		terrain = 0;

		repairGear(item[lastWeapon]);

		break;
	}
	case MineIron:
	{
		terrain = 0;

		mine(Iron_ore);

		break;
	}
	case MineAdamantine:
	{
		terrain = 0;

		mine(Adamantine_ore);

		break;
	}
	case Forage:
	{
		terrain = 0;

		forage();

		break;
	}
	case ChopWood:
	{
		terrain = 0;

		chopWood();

		break;
	}
	case BrewHp:
	{
		terrain = 0;
		brewHp();
		break;
	}
	case BrewSta:
	{
		terrain = 0;
		brewSta();
		break;
	}
	case PirateTrivia:
	{
		terrain = 0;
		pirateTrivia();
		break;
	}
	case BridgeRiddles:
	{
		terrain = 0;
		bridgeRiddles();
		break;
	}
	case MarioBrick:
	{
		terrain = 0;
		marioBrick();
		break;
	}
	case Quest1:
	{
		terrain = 0;

		tOptions = "";
		options = 0;
		topText = "Tavern Keeper: Come back later...";
		showInfo = true;
		showBackpack = false;
		location = HaltonTavern;


		if (!questStarted[HaltonAlleyBanditQuest])
		{
			tOptions = "";
			options = 0;
			topText = "Tavern Keeper: I will tell you where Greg the Dark is, if you clear out the alley next to the Tavern";
			questStarted[HaltonAlleyBanditQuest] = true;
		}
		else if (questStarted[HaltonAlleyBanditQuest] && questDone[HaltonAlleyBanditQuest] && !questFinished[HaltonAlleyBanditQuest])
		{
			tOptions = "";
			options = 0;
			topText = "Tavern Keeper: Thanks for doing that, I didn't think you would acctually do that. I don't know where he is but i heard the king has been talking about him recently. ";
			questFinished[HaltonAlleyBanditQuest] = true;
		}
		else if (questStarted[HaltonAlleyBanditQuest] && !questDone[HaltonAlleyBanditQuest])
		{
			tOptions = "";
			options = 0;
			topText = "Tavern Keeper: I'm waiting for you to clear out the alley next to the Tavern";
		}


		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
		
		std::system("pause>nul");

		break;
	}
	case SmitheryQuest:
	{
		terrain = 0;
		smitheryFight();
		break;
	}
	case MineQuest:
	{
		terrain = 0;
		mineFight();
		break;
	}
	case LumberyardQuest:
	{
		terrain = 0;
		lumberyardFight();
		break;
	}
	case Quest2:
	{
		terrain = 0;

		tOptions = "";
		options = 0;
		showInfo = true;
		showBackpack = false;
		location = MadthorneTavern;
		topText = "Tavern Keeper: I don't know where Greg the Dark is, but if heard someone was holding a princess from Halton in the castle";

		enterLocation(options, topText, showInfo, showBackpack, tOptions, optionEff);
	}
	case Book1:
	{
		terrain = 0;
		book1();
		break;
	}
	case Book2:
	{
		terrain = 0;
		book2();
		break;
	}
	case Book3:
	{
		terrain = 0;
		book3();
		break;
	}
	case Book4:
	{
		terrain = 0;
		book4();
		break;
	}
	case Book5:
	{
		terrain = 0;
		book5();
		break;
	}
	case Book6:
	{
		terrain = 0;
		book6();
		break;
	}
	case Book7:
	{
		terrain = 0;
		book7();
		break;
	}
	case Book8:
	{
		terrain = 0;
		book8();
		break;
	}
	case Book9:
	{
		terrain = 0;
		book9();
		break;
	}
	case Book10:
	{
		terrain = 0;
		book10();
		break;
	}
	case Book11:
	{
		terrain = 0;
		book11();
		break;
	}
	case Book12:
	{
		terrain = 0;
		book12();
		break;
	}
	default:
		break;
	}
	
}

void enterLocation(int options,
	std::string upperText,
	bool outputStats,
	bool outputBackpack,
	std::string optionText,
	long long (&optionsEff)[100])
{
	bool backpackOuted{ 0 };
Back:
	using std::cout;
	int x{-1};
	saveLocation = lastLocation;
	lastLocation = location;

	std::system("cls");
	cout << upperText << "\n\n";

	if (outputStats)
	{
		outputInfo();
	}

	if (outputBackpack && !backpackOuted)
	{
		optionsEff[options] = Backpack;
		optionText += '\n';
		optionText += std::to_string(options);
		optionText += " - Backpack";
		options += 1;

		backpackOuted = true;
		deepSaveLocation = lastLocation;
	}

	if (options == 0)
	{
	}
	else
	{

		cout << optionText << "\n\n";

		
		while (x < 0 || x > options)
		{

			std::cin >> x;

			if (options >= x)
			{
				location = optionsEff[x];
			}
			else
			{
				goto Back;
			}
		}
		
	}
}
