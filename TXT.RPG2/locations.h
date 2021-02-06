#ifndef LOCATIONS_H
#define LOCATIONS_H

void changeLocation();

extern long long location;
extern long long lastLocation;
extern long long saveLocation;
extern long long deepSaveLocation;
extern long long city;
extern int cityID;
extern int terrain;

enum Location
{
	// Base Functions
	Win,
	Die,
	Save,
	Load,
	Exit,
	Battle,
	BattleSetup,
	Attack,
	PostAttack,
	AttackInventory,
	ChangeTarget,
	ChangeWeapon,
	FightSpells,
	FightStats,
	TargetEnemyStats,
	AttackS,

	// Main Menu/Backpack
	Backpack,
	StatScreen,
	SkillScreen,
	Inventory,
	ResourceScreen,
	ItemScreen,
	MagicScreen,
	PotionScreen,
	PotionScreenB,

	// Locations
	Home,
	HaltonCity,
	HaltonTavern,
	HaltonAlley,
	Shop,
	HaltonLibrary,
	HaltonKingsGuard,
	HaltonKingsPalace,
	Smithery,
	Mine,
	HaltonForest,
	Stables,// later
	Port,// later
	Lumberyard,
	BanditHideout1,
	BanditHideout2,
	BanditHideout3,
	HaltonRoadGuard,
	Road1,
	Road2,
	TarrinCity,
	Tavern,
	TarrinLibrary,
	TarrinKingsGuard,
	TarrinKingsPalace,
	TarrinRoadGuard,
	TarCem1,
	TarCem2,
	TarCem3,
	TarCem4,
	Road3,
	Road4,
	Road5,
	Witch,
	Road6,
	Road7,
	Road8,
	Road9,
	Road10,
	PirateCove,
	Madthorne, 
	MadthorneTavern,
	BridgeToLibrary,
	MadthorneLibrary,
	MadthorneCastle,
	MadthorneCastleTowerDoors,
	MadthorneCastleTower,
	MadthorneCastleTreasureRoom,
	MadthornePrincessRoom,
	MadthorneGoblinMine,
	Dunkelland, 
	DunkellandTavern,
	DarkCastle,

	//Fights
	TrainingFight,
	AlleyBanditFight,
	WolfFight,
	RoadBanditFight,
	BanditHideoutLookoutFight,
	BanditHideoutGuardFight,
	BanditHideoutKingFight,
	TarrinFight,
	TarCem1Fight,
	TarCem2Fight,
	TarCem3Fight,
	TarCem4Fight,
	OldPirateFight,
	BridgeFight,
	MadthorneGoblinMineFight,
	MadthorneCastleFight1,
	MadthorneCastleFight2, 
	MadthorneCastleFight3,
	MadthorneCastleFight4,
	DarkCastleFight, 

	// Actions

	SleepHome,
	Eat,
	Drink,
	SleepTavern,
	BuyWeapons,
	BuyArmour,// later
	EnchantGear,// later
	MeltOre,
	MeltIron,
	MeltAdamantine,
	MakeAlloys,
	MakeSteel,
	CraftGear, 
	PickCraftGear, 
	PickCraftGearWood, 
	PickCraftGearIron, 
	PickCraftGearSteel, 
	PickCraftGearAdamantine,
	CraftSword, 
	CraftBow, 
	CraftStaff,
	RepairGear,
	RepairWeapon,
	MineIron,
	MineAdamantine,
	Forage,
	Hunt, // Later
	ChopWood,
	BrewHp,
	BrewSta,
	PirateTrivia,
	BridgeRiddles, // Add give COOL HAT when armour is done
	MarioBrick,

	// Quests
	Quest1,
	SmitheryQuest,
	MineQuest,
	LumberyardQuest,
	Quest2,

	// Books
	Book1,
	Book2,
	Book3,
	Book4,
	Book5,
	Book6,
	Book7,
	Book8,
	Book9,
	Book10,
	Book11,
	Book12,
};

enum Cities
{
	NotCity,
	CityHalton,
	CityTarrin,
	CityMadthorne,
	CityDunkelland,
};

void changeLocation();
void enterLocation(int options,	std::string upperText, bool outputStats, bool outputBackpack, std::string optionText, long long(&optionsEff)[100]);

extern int sleepCost;
extern int foodCost;
extern int drinkCost;
extern int hpPotPrice;
extern int staPotPrice;


#endif