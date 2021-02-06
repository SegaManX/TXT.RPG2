#include "allInclude.h"


bool questDone[80]{};
bool questStarted[80]{};
bool questFinished[80]{};

void questUpdater()
{
	switch (quest)
	{
	case HaltonAlleyBanditQuest:
	{
		questDone[HaltonAlleyBanditQuest] = true;
		break;
	}
	case BanditHideoutQuest:
	{
		questDone[BanditHideoutQuest] = true;
		break;
	}
	case WolfAttackQuest:
	{
		questDone[WolfAttackQuest] = true;
		break;
	}
	case SmitheryAccessQuest:
	{
		questDone[SmitheryAccessQuest] = true;
		break;
	}
	case LumberyardAccessQuest:
	{
		questDone[LumberyardAccessQuest] = true;
		break;
	}
	case MineAccessQuest:
	{
		questDone[MineAccessQuest] = true;
		break;
	}
	case CleanTarrinQuest:
	{
		if (enemiesKilled[Skeleton] >= 5)
		{
			questDone[CleanTarrinQuest] = true;
		}
		break;
	}
	case LichMapQuest:
	{
		int chance{ 10 };
		if (d100Gen(mersenne) > chance)
		{
			questDone[LichMapQuest] = true;
			std::system("cls");
			std::cout << "You have found the map";
			std::system("pause>nul");

		}
		else
		{
			std::system("cls");
			std::cout << "You have not found the map";
			std::system("pause>nul");
		}
		break;
	}
	case LichQuest:
	{
		questDone[LichQuest] = true;
		break;
	}
	case MadthorneBridgeQuest:
	{
		questDone[MadthorneBridgeQuest] = true;
		break;
	}
	case MadthorneGoblinMineQuest:
	{
		questDone[MadthorneGoblinMineQuest] = true;
		break;
	}
	default:
		break;
	}
}