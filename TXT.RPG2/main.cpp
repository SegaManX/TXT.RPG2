#include "allInclude.h"

// Initialize the stats


bool booLeans[4]{};
int hours{};
int minutes{};
int days{};
int hunger{10};
int thirst{10};

void showHT()
{
	std::cout << "Hunger: [";
	for (int i{}; i < hunger; i++)
	{
		std::cout << "#";
	}
	for (int i{}; i < 10 - hunger; i++)
	{
		std::cout << "-";
	}
	std::cout << "]\n";


	std::cout << "Thirst: [";
	for (int i{}; i < thirst; i++)
	{
		std::cout << "#";
	}
	for (int i{}; i < 10 - thirst; i++)
	{
		std::cout << "-";
	}
	std::cout << "]\n";
}

void outputInfo()
{
	using std::cout;
	cout << '\n';
	cout << "Time: " << "Day " << days << " " << hours << ":" << minutes;
	if (minutes < 10)
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << "\n";
	}
	cout << "Name: " << playerName << '\n';
	cout << "Hp: " << stats[Hp] << '/' << stats[MaxHp] << '\n';
	cout << "Stamina: " << stats[Stamina] << '/' << stats[MaxStamina] << '\n';
	cout << "Gold: " << resources[Gold] << '\n';
	showXP();
	showHT();
	cout << "\n";
}

void passTime()
{
	if (location != Battle)
	{
		minutes += 10;
	}
	if (minutes >= 60)
	{
		minutes -= 60;
		hours += 1;
	}
	if (hours >= 24)
	{
		hours -= 24;
		days += 1;
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
	}
	
}

int main()
{
	std::system("title TXT.RPG2");
	std::system("color b");

	playMusic(Start_Music);


	loadConfig();
	startup();
	int clean{ rand() };

	

	while (booLeans[Won] != 1)
	{
		changeLocation();
		stats[Stamina] -= terrain;
		if (stats[Stamina] <= 0)
		{
			stats[Hp] += stats[Stamina];
			stats[Stamina] = 0;
		}
		levelUp();
		passTime();
		
	}

	return 0;
}