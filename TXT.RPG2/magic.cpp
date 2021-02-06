#include "allInclude.h"

int spells{16};
bool spellsUnlocked[16]{};
int spellLevel[16]{};
int spellRequirement[16]{0, 3, 5, 10, 2, 5, 4, 2, 6, 10, 7};
int spellDamage[16]{ 0, 1, 2, 5,};
int spellHeal[16]{ 0, 0, 0, 0, 0, 0, 0, 5, 20, 50, 0 };
std::string spellNames[16]{"","Fireball", "Frost ray", "Ligthning bolt", "Shield", "Bless", "Slow", "Heal Wounds", "Cure", "Ressurect", "Unlock"};
int shownSpells{};
bool spellsShown[16]{};
int spellEffect[16][16]{};

void spellPrefix(int requirement)
{
	if (skillLevel[Arcanum] >= requirement * 5)
	{
		std::cout << "Grand Master ";
	}
	else if (skillLevel[Arcanum] >= requirement * 4)
	{
		std::cout << "Master ";
	}
	else if (skillLevel[Arcanum] >= requirement * 3)
	{
		std::cout << "Major ";
	}
	else if (skillLevel[Arcanum] >= requirement * 2)
	{
		std::cout << "";
	}
	else if (skillLevel[Arcanum] >= requirement)
	{
		std::cout << "Minor ";
	}
}

void damageSpells()
{
	for (int i{}; i < Shield; i++)
	{

		if (spellsUnlocked[i] == true)
		{
			std::cout << "Level " << itemLevel[i] << " ";
			spellPrefix(spellRequirement[i]);
			std::cout << spellNames[i];
			std::cout << " " << "- Cost: " << spellRequirement[i] << " Stamina\n";
			shownSpells += 1;
			spellsShown[i] = true;
		}

	}
}

void buffSpells()
{
	for (int i{Shield}; i < Slow; i++)
	{

		if (spellsUnlocked[i] == true)
		{
			std::cout << "Level " << itemLevel[i] << " ";
			spellPrefix(spellRequirement[i]);
			std::cout << spellNames[i];
			std::cout << " " << "- Cost: " << spellRequirement[i] << " Stamina\n";
			shownSpells += 1;
			spellsShown[i] = true;
		}

	}
}

void debuffSpells()
{
	for (int i{Slow}; i < HealWounds; i++)
	{

		if (spellsUnlocked[i] == true)
		{
			std::cout << "Level " << itemLevel[i] << " ";
			spellPrefix(spellRequirement[i]);
			std::cout << spellNames[i];
			std::cout << " " << "- Cost: " << spellRequirement[i] << " Stamina\n";
			shownSpells += 1;
			spellsShown[i] = true;
		}

	}
}

void healSpells()
{
	for (int i{HealWounds}; i < Unlock; i++)
	{

		if (spellsUnlocked[i] == true)
		{
			std::cout << "Level " << itemLevel[i] << " ";
			spellPrefix(spellRequirement[i]);
			std::cout << spellNames[i];
			std::cout << " " << "- Cost: " << spellRequirement[i] << " Stamina\n";
			shownSpells += 1;
			spellsShown[i] = true;
		}

	}
}

void utilitySpells()
{
	for (int i{Unlock}; i < spells; i++)
	{

		if (spellsUnlocked[i] == true)
		{
			std::cout << "Level " << itemLevel[i] << " ";
			spellPrefix(spellRequirement[i]);
			std::cout << spellNames[i];
			std::cout << " " << "- Cost: " << spellRequirement[i] << " Stamina\n";
			shownSpells += 1;
			spellsShown[i] = true;
		}

	}
}

void combatSpells()
{
	damageSpells();
	buffSpells();
	debuffSpells();
	healSpells();
}

void allSpells()
{
	combatSpells();
	utilitySpells();
}

int castSpell(int outputType)
{
	int damageOut{};
	int healOut{};
	int staminaCost{};
	int effectOut{};

	damageOut = spellDamage[lastSpell];
	healOut = spellHeal[lastSpell];
	staminaCost = spellRequirement[lastSpell];

	if (skillLevel[Arcanum] >= spellRequirement[lastSpell] * 5)
	{
		damageOut *= 5;
		healOut *= 5;
		staminaCost = spellRequirement[lastSpell] * 5;
	}
	else if (skillLevel[Arcanum] >= spellRequirement[lastSpell] * 4)
	{
		damageOut *= 4;
		healOut *= 4;
		staminaCost = spellRequirement[lastSpell] * 4;
	}
	else if (skillLevel[Arcanum] >= spellRequirement[lastSpell] * 3)
	{
		damageOut *= 3;
		healOut *= 3;
		staminaCost = spellRequirement[lastSpell] * 3;
	}
	else if (skillLevel[Arcanum] >= spellRequirement[lastSpell] * 2)
	{
		damageOut *= 2;
		healOut *= 2;
		staminaCost = spellRequirement[lastSpell] * 2;
	}
	else if (skillLevel[Arcanum] >= spellRequirement[lastSpell])
	{
	}

	switch (outputType)
	{
	case NoSpellType:
	{
		return 0;
	}
	case Damage:
	{
		return damageOut;
	}
	case Buff:
	{
		return effectOut;
	}
	case Debuff:
	{
		return effectOut;
	}
	case Heal:
	{
		return healOut;
	}
	case Utility:
	{
		return effectOut;
	}
	default:
		return 0;
		break;
	}

}