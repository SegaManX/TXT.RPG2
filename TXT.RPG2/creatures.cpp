#include "allInclude.h"

std::string eName{};
std::string eTextBefore{};
std::string eTextAfter{};
int enemies[10]{};
int enemyCount{10};
int targetEnemy{1};
int eLevel{};
int eDamage{};
int eStats[10]{};
int eSkillLevel[13]{};

int eRewardXP{};
int eRewardGold{};

void dummy()
{
	eName = "Dummy";
	eTextBefore = "Dummy: ... ";
	eTextAfter = "Dummy: ... ";
	eRewardXP = 100;
	eRewardGold = 0;

	eLevel = 0;
	eDamage = 1;

	eStats[Hp] = 10;
	eStats[MaxHp] = 10;
	eStats[Stamina] = 0;
	eStats[MaxStamina] = 0;
	eStats[Strength] = 0;
	eStats[Defence] = 5;
	eStats[Agility] = 1;
	eStats[Perception] = 0;
	eStats[Intelligence] = 0;
	eStats[Charisma] = 0;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;
	
}

void bandit()
{
	eName = "Bandit";
	eTextBefore = "Bandit: Argh... ";
	eTextAfter = "A Bandit drops some gold... ";
	eRewardXP = 500;
	eRewardGold = 10;

	eLevel = 1;
	eDamage = 1;

	eStats[Hp] = 10;
	eStats[MaxHp] = 10;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 2;
	eStats[Defence] = 2;
	eStats[Agility] = 2;
	eStats[Perception] = 2;
	eStats[Intelligence] = 2;
	eStats[Charisma] = 2;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;

}

void roadBandit()
{
	eName = "Road Bandit";
	eTextBefore = "";
	eTextAfter = "A Road Bandit drops some gold... ";
	eRewardXP = 750;
	eRewardGold = 20;

	eLevel = 1;
	eDamage = 2;

	eStats[Hp] = 10;
	eStats[MaxHp] = 10;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 3;
	eStats[Defence] = 2;
	eStats[Agility] = 3;
	eStats[Perception] = 2;
	eStats[Intelligence] = 2;
	eStats[Charisma] = 2;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;

}

void drunkBandit() 
{
	eName = "Drunk Bandit";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 300;
	eRewardGold = 10;

	eLevel = 1;
	eDamage = 1;

	eStats[Hp] = 5;
	eStats[MaxHp] = 5;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 2;
	eStats[Defence] = 2;
	eStats[Agility] = 1;
	eStats[Perception] = 2;
	eStats[Intelligence] = 2;
	eStats[Charisma] = 2;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;

}

void forestBandit()
{
	eName = "Forest Bandit";
	eTextBefore = "";
	eTextAfter = "A Forest Bandit drops some gold... ";
	eRewardXP = 500;
	eRewardGold = 10;

	eLevel = 1;
	eDamage = 1;

	eStats[Hp] = 10;
	eStats[MaxHp] = 10;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 2;
	eStats[Defence] = 1;
	eStats[Agility] = 3;
	eStats[Perception] = 2;
	eStats[Intelligence] = 2;
	eStats[Charisma] = 2;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;

}

void banditKing()
{
	eName = "Bandit King";
	eTextBefore = "Bandit King: What are you doing here kid!";
	eTextAfter = "The Bandit King had a chest of gold...";
	eRewardXP = 3000;
	eRewardGold = 150;

	eLevel = 4;
	eDamage = 5;

	eStats[Hp] = 40;
	eStats[MaxHp] = 40;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 10;
	eStats[Defence] = 7;
	eStats[Agility] = 4;
	eStats[Perception] = 3;
	eStats[Intelligence] = 3;
	eStats[Charisma] = 3;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;

}

void wolf()
{
	eName = "Wolf";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 1000;
	eRewardGold = 0;

	eLevel = 2;
	eDamage = 2;

	eStats[Hp] = 15;
	eStats[MaxHp] = 15;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 4;
	eStats[Defence] = 2;
	eStats[Agility] = 6;
	eStats[Perception] = 3;
	eStats[Intelligence] = 3;
	eStats[Charisma] = 3;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;
}

void madDwarf()
{
	eName = "Mad Dwarf";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 100;
	eRewardGold = 0;

	eLevel = 1;
	eDamage = 1;

	eStats[Hp] = 15;
	eStats[MaxHp] = 15;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 2;
	eStats[Defence] = 3;
	eStats[Agility] = 1;
	eStats[Perception] = 2;
	eStats[Intelligence] = 2;
	eStats[Charisma] = 2;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;
}

void skeleton()
{
	eName = "Skeleton";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 1000;
	eRewardGold = 0;

	eLevel = 5;
	eDamage = 6;

	eStats[Hp] = 60;
	eStats[MaxHp] = 60;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 12;
	eStats[Defence] = 10;
	eStats[Agility] = 8;
	eStats[Perception] = 6;
	eStats[Intelligence] = 6;
	eStats[Charisma] = 2;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;
}

void shadow()
{
	eName = "Shadow";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 1000;
	eRewardGold = 0;

	eLevel = 5;
	eDamage = 8;

	eStats[Hp] = 50;
	eStats[MaxHp] = 50;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 16;
	eStats[Defence] = 8;
	eStats[Agility] = 10;
	eStats[Perception] = 6;
	eStats[Intelligence] = 3;
	eStats[Charisma] = 2;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;
}

void zombie()
{
	eName = "Zombie";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 1000;
	eRewardGold = 0;

	eLevel = 5;
	eDamage = 4;

	eStats[Hp] = 70;
	eStats[MaxHp] = 70;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 8;
	eStats[Defence] = 12;
	eStats[Agility] = 6;
	eStats[Perception] = 6;
	eStats[Intelligence] = 3;
	eStats[Charisma] = 2;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;
}

void lich()
{
	eName = "Lich";
	eTextBefore = "Lich: Have you come to join my immortal army?";
	eTextAfter = "You search around but don't find any gold. It seams that the undead have no need for such things.";
	eRewardXP = 50000;
	eRewardGold = 0;

	eLevel = 10;
	eDamage = 20;

	eStats[Hp] = 150;
	eStats[MaxHp] = 150;
	eStats[Stamina] = 20;
	eStats[MaxStamina] = 20;
	eStats[Strength] = 25;
	eStats[Defence] = 20;
	eStats[Agility] = 15;
	eStats[Perception] = 10;
	eStats[Intelligence] = 10;
	eStats[Charisma] = 2;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;
}

void oldPirate()
{
	eName = "Old Pirate";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 1500;
	eRewardGold = 0;

	eLevel = 7;
	eDamage = 8;

	eStats[Hp] = 70;
	eStats[MaxHp] = 70;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 16;
	eStats[Defence] = 12;
	eStats[Agility] = 10;
	eStats[Perception] = 6;
	eStats[Intelligence] = 3;
	eStats[Charisma] = 3;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;
}

void goblin()
{
	eName = "Goblin";
	eTextBefore = "Goblin: GOLD!!! ";
	eTextAfter = "";
	eRewardXP = 2000;
	eRewardGold = 10;

	eLevel = 10;
	eDamage = 16;

	eStats[Hp] = 100;
	eStats[MaxHp] = 100;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 20;
	eStats[Defence] = 10;
	eStats[Agility] = 12;
	eStats[Perception] = 9;
	eStats[Intelligence] = 3;
	eStats[Charisma] = 3;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;

}

void orc()
{
	eName = "Orc";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 1600;
	eRewardGold = 0;

	eLevel = 13;
	eDamage = 20;
	
	eStats[Hp] = 200;
	eStats[MaxHp] = 200;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 20;
	eStats[Defence] = 20;
	eStats[Agility] = 8;
	eStats[Perception] = 9;
	eStats[Intelligence] = 3;
	eStats[Charisma] = 3;
	
	{
		eSkillLevel[Swordsmanship] = 0;
		eSkillLevel[Bowmanship] = 0;
		eSkillLevel[Arcanum] = 0;
		eSkillLevel[Wood_cutting] = 0;
		eSkillLevel[Mining] = 0;
		eSkillLevel[Foraging] = 0;
		eSkillLevel[Hunting] = 0;
		eSkillLevel[Smithing] = 0;
		eSkillLevel[Brewing] = 0;
		eSkillLevel[Toolsmanship] = 0;
		eSkillLevel[Stealth] = 0;
		eSkillLevel[Medicine] = 0;
		eSkillLevel[Lockpicking] = 0;
	}
}

void troll()
{
	eName = "Troll";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 3000;
	eRewardGold = 0;

	eLevel = 15;
	eDamage = 40;

	eStats[Hp] = 400;
	eStats[MaxHp] = 400;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 40;
	eStats[Defence] = 20;
	eStats[Agility] = 1;
	eStats[Perception] = 9;
	eStats[Intelligence] = 3;
	eStats[Charisma] = 3;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;

}

void orcKnight()
{
	eName = "Orc Knight";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 3000;
	eRewardGold = 0;

	eLevel = 15;
	eDamage = 25;

	eStats[Hp] = 200;
	eStats[MaxHp] = 200;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 25;
	eStats[Defence] = 40;
	eStats[Agility] = 4;
	eStats[Perception] = 9;
	eStats[Intelligence] = 3;
	eStats[Charisma] = 5;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;

}

void dragon()
{
	eName = "Dragon";
	eTextBefore = "";
	eTextAfter = "";
	eRewardXP = 5000;
	eRewardGold = 0;

	eLevel = 17;
	eDamage = 35;

	eStats[Hp] = 600;
	eStats[MaxHp] = 600;
	eStats[Stamina] = 5;
	eStats[MaxStamina] = 5;
	eStats[Strength] = 35;
	eStats[Defence] = 50;
	eStats[Agility] = 20;
	eStats[Perception] = 15;
	eStats[Intelligence] = 3;
	eStats[Charisma] = 6;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;

}

void greg()
{
	eName = "GREG the Dark";
	eTextBefore = "GREG the Dark: Puny mortal what are you doing here?";
	eTextAfter = "";
	eRewardXP = 10000;
	eRewardGold = 0;

	eLevel = 20;
	eDamage = 100;

	eStats[Hp] = 1000;
	eStats[MaxHp] = 1000;
	eStats[Stamina] = 100;
	eStats[MaxStamina] = 100;
	eStats[Strength] = 100;
	eStats[Defence] = 100;
	eStats[Agility] = 100;
	eStats[Perception] = 30;
	eStats[Intelligence] = 20;
	eStats[Charisma] = 10;

	eSkillLevel[Swordsmanship] = 0;
	eSkillLevel[Bowmanship] = 0;
	eSkillLevel[Arcanum] = 0;
	eSkillLevel[Wood_cutting] = 0;
	eSkillLevel[Mining] = 0;
	eSkillLevel[Foraging] = 0;
	eSkillLevel[Hunting] = 0;
	eSkillLevel[Smithing] = 0;
	eSkillLevel[Brewing] = 0;
	eSkillLevel[Toolsmanship] = 0;
	eSkillLevel[Stealth] = 0;
	eSkillLevel[Medicine] = 0;
	eSkillLevel[Lockpicking] = 0;

}


void selectCreature(int x)
{
	switch (x)
	{
	case Dummy:
	{
		dummy();
		break;
	}
	case Bandit:
	{
		bandit();
		break;
	}
	case RoadBandit:
	{
		roadBandit();
		break;
	}
	case  DrunkBandit:
	{
		drunkBandit();
		break;
	}
	case ForestBandit:
	{
		forestBandit();
		break;
	}
	case BanditKing:
	{
		banditKing();
		break;
	}
	case Wolf:
	{
		wolf();
		break;
	}
	case MadDwarf:
	{
		madDwarf();
		break;
	}
	case Skeleton:
	{
		skeleton();
		break;
	}
	case Shadow:
	{
		shadow();
		break;
	}
	case Zombie:
	{
		zombie();
		break;
	}
	case Lich:
	{
		lich();
		break;
	}
	case OldPirate:
	{
		oldPirate();
		break;
	}
	case Goblin:
	{
		goblin();
		break;
	}
	case Orc:
	{
		orc();
		break;
	}
	case Troll:
	{
		troll();
		break;
	}
	case OrcKnight:
	{
		orcKnight();
		break;
	}
	case Dragon:
	{
		dragon();
		break;
	}
	case GREG:
	{
		greg();
		break;
	}
	default:
		break;
	}
}