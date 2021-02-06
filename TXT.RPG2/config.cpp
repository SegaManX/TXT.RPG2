#include "allInclude.h"

double attackMultiplier{ 0.1 };
double rangedWeaponDemultiplier{0.5};

void loadConfig()
{
	std::ifstream loadConfig;
	loadConfig.open("config.txt");

	//Check for error and create if fail
	if (loadConfig.fail())
	{
		
		std::ofstream save;
		save.open("config.txt");

		save << attackMultiplier << '\n'
			 << rangedWeaponDemultiplier << '\n';

		save.close();
		

		loadConfig.open("config.txt");
	}

	loadConfig >>	attackMultiplier >>
					rangedWeaponDemultiplier;

	loadConfig.close();

	location = saveLocation;
}
