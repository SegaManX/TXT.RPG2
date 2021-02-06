#include "allInclude.h"


void save()
{
	location = Home;

	std::ofstream save;
	save.open("save.txt");

	save << playerName << '\n';

	save << diff << '\n'
		 << location << '\n'
		 << lastLocation << '\n'
		 << saveLocation << '\n'
		 << deepSaveLocation << '\n'
		 << city << '\n'
		 << terrain << '\n'
		 << expirience << '\n'
		 << totalEXP << '\n'
		 << level << '\n'
		 << skillPoint << '\n'
		 << statPoint << '\n'
		 << selectedClass << '\n'
		 << itemCount << '\n'
		 << itemsInInventory << '\n'
		 << spells << '\n'
		 << clasDmgStat << '\n'
		 << hours << '\n'
		 << minutes << '\n'
		 << days << '\n';

		for (int i : stats)
		{
			save << i << '\n';
		};
		for (int i : skillXP)
		{
			save << i << '\n';
		};
		for (int i : skillXPToNextLevel)
		{
			save << i << '\n';
		};
		for (int i : skillTotalXP)
		{
			save << i << '\n';
		};
		for (int i : skillLevel)
		{
			save << i << '\n';
		};
		for (int i : resources)
		{
			save << i << '\n';
		};
		for (int i : booLeans)
		{
			save << i << '\n';
		};
		for (int i : item)
		{
			save << i << '\n';
		};
		for (int i : itemDurability)
		{
			save << i << '\n';
		};
		for (int i : itemMaxDurability)
		{
			save << i << '\n';
		};
		for (int i : itemAmount)
		{
			save << i << '\n';
		};
		for (int i : itemEnchant)
		{
			save << i << '\n';
		};
		for (int i : itemLevel)
		{
			save << i << '\n';
		};
		for (int i : itemRequirement)
		{
			save << i << '\n';
		};
		for (int i : spellsUnlocked)
		{
			save << i << '\n';
		};
		for (int i : spellLevel)
		{
			save << i << '\n';
		};
		for (int i : questDone)
		{
			save << i << '\n';
		}
		for (int i : questFinished)
		{
			save << i << '\n';
		}
		for (int i : questStarted)
		{
			save << i << '\n';
		}

	save.close();

	std::system("cls");
	std::cout << "Game Saved";
	std::system("pause>nul");

	location = Home;
}

void load()
{
	std::ifstream load;
	load.open("save.txt");

	//Check for error
	if (load.fail())
	{
		std::cout << "Error Loading" << '\n';
	}

	std::getline(load, playerName);

	load >> diff >>
			location >>
			lastLocation >>
			saveLocation >>
			deepSaveLocation >>
			city >>
			terrain >>
			expirience >>
			totalEXP >>
			level >>
			skillPoint >>
			statPoint >>
			selectedClass >>
			itemCount >>
			itemsInInventory >>
			spells >>
			clasDmgStat >>
			hours >>
			minutes >>
			days;
	
	int i{};
	for (int dumb : stats)
	{
		load >> stats[i];
		i++;
	};
	i = 0;
	for (int dumb : skillXP)
	{
		load >> skillXP[i];
		i++;
	};
	i = 0;
	for (int dumb : skillXPToNextLevel)
	{
		load >> skillXPToNextLevel[i];
		i++;
	};
	i = 0;
	for (int dumb : skillTotalXP)
	{
		load >> skillTotalXP[i];
		i++;
	};
	i = 0;
	for (int dumb : skillLevel)
	{
		load >> skillLevel[i];
		i++;
	};
	i = 0;
	for (int dumb : resources)
	{
		load >> resources[i];
		i++;
	};
	i = 0;
	for (int dumb : booLeans)
	{
		load >> booLeans[i];
		i++;
	};
	i = 0;
	for (int dumb : item)
	{
		load >> item[i];
		i++;
	};
	i = 0;
	for (int dumb : itemDurability)
	{
		load >> itemDurability[i];
		i++;
	};
	i = 0;
	for (int dumb : itemMaxDurability)
	{
		load >> itemMaxDurability[i];
		i++;
	};
	i = 0;
	for (int dumb : itemAmount)
	{
		load >> itemAmount[i];
		i++;
	};
	i = 0;
	for (int dumb : itemEnchant)
	{
		load >> itemEnchant[i];
		i++;
	};
	i = 0;
	for (int dumb : itemLevel)
	{
		load >> itemLevel[i];
		i++;
	};
	i = 0;
	for (int dumb : itemRequirement)
	{
		load >> itemRequirement[i];
		i++;
	};
	i = 0;
	for (int dumb : spellsUnlocked)
	{
		load >> spellsUnlocked[i];
		i++;
	};
	i = 0;
	for (int dumb : spellLevel)
	{
		load >> spellLevel[i];
		i++;
	};
	i = 0;
	for (int dumb : questDone)
	{
		load >> questDone[i];
		i++;
	}
	i = 0;
	for (int dumb : questFinished)
	{
		load >> questFinished[i];
		i++;
	}
	i = 0;
	for (int dumb : questStarted)
	{
		load >> questStarted[i];
		i++;
	}
	i = 0;

	load.close();

	location = lastLocation;
}
