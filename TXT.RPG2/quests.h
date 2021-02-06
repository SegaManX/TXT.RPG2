#pragma once

enum Quests
{
	NoQuest,
	HaltonAlleyBanditQuest,
	SmitheryAccessQuest,
	LumberyardAccessQuest,
	MineAccessQuest,
	RoadGuardHaltonQuest,
	PrincessQuest,
	WolfAttackQuest,
	BanditHideoutQuest,
	LichQuest,
	CleanTarrinQuest,
	LichMapQuest,
	MadthorneBridgeQuest,
	MadthorneGoblinMineQuest,
	MadthorneCastleQuest,
	MadthorneTreasure,
	PunchBrickQuest,
};

extern bool questFinished[80];
extern bool questDone[80];
extern bool questStarted[80];

void questUpdater();