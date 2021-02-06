#ifndef LEVELING_H
#define LEVELING_H

enum StatList
{
	Hp, //0
	MaxHp, //1
	Stamina, //2
	MaxStamina, //3
	Strength, //4
	Defence, //5
	Agility, //6
	Perception, //7
	Intelligence, //8
	Charisma //9
};

enum SkillList
{
	Swordsmanship, //0
	Bowmanship, //1
	Arcanum, //2
	Wood_cutting, //3
	Mining, //4
	Foraging, //5
	Hunting, // 6
	Smithing, //7
	Brewing, // 8
	Toolsmanship, //9
	Stealth, //10
	Medicine, //11
	Lockpicking //12
};

enum cClasses
{
	Warrior, // Sword
	Theif, // Sword for now Dagger later
	Ranger, // Bow
	Mage, // Staff, Fireball
	Cleric, // Staff for now Wand later , potions later, Cure Wounds
	Trickster,
	Bard,
	Joker,
	Assassin,
	Ninja,
	Hitman,
	Knight,
	Paladin,
	Guardian,
	Barbarian,
	Chieftain,
	Berserker,
	Arcane,
	Elemental,
	Archmage,
	Summoner,
	Necromancer,
	Elemental_Summoner,
	Druid,
	Beastmaster,
	Shaman,
	Priest,
	Bishop,
	Divine_Mage,
	Hunter,
	Beast_Hunter,
	Jager,
	Bowmaster,
	Sniper,
	Phantom
};

enum uClasses
{
	Worker,
	Smith,
	Arcanist,
	Enchanter,
	Cook,
	Alchemist,
	Peasant,
};

void showXP();
void levelUp();
void lockStats();
void lockSkills();


extern int expirience;
extern int totalEXP;
extern int level;
extern int skillPoint;
extern int statPoint;
extern int stats[10];
extern int statLockLevel[10];

extern int skillXP[13];
extern int skillXPToNextLevel[13];
extern int skillTotalXP[13];
extern int skillLevel[13];
extern int skillLockLevel[13];

extern int selectedClass;

#endif