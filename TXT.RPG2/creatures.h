#ifndef CREATURES_H
#define CREATURES_H

enum Creatures
{
	Noone,
	Dummy,
	Bandit,
	RoadBandit,
	DrunkBandit,
	ForestBandit,
	BanditKing,
	Wolf,
	MadDwarf,
	Skeleton,
	Shadow,
	Zombie,
	Lich,
	OldPirate,
	Goblin,
	Orc,
	Troll,
	OrcKnight,
	Dragon,
	GREG,
};

extern int eLevel;
extern int eDamage;
extern int eStats[10];
extern int eSkillLevel[13];

extern std::string eName;
extern std::string eTextBefore;
extern std::string eTextAfter;

extern int enemies[10];
extern int targetEnemy;
extern int enemyCount;

extern int eRewardXP;
extern int eRewardGold;

extern void selectCreature(int);


#endif // !CREATURES_H

