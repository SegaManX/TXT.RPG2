#ifndef MAGIC_H
#define MAGIC_H

enum Spells
{
	NoSpell,
	// Damage
	Fireball, // 3 req
	Frostray, // 5 req
	LightningBolt, //10 req

	// Buff
	Shield, // 2 req
	Bless, // 5 req
	
	// Debuff
	Slow, // 4 req

	// Heal
	HealWounds, // 2 req
	Cure, // 6 req
	Ressurect, // 10 req

	// Utility
	Unlock,// 7 req
	Invisibility, 
};

enum Effects
{
	NoEffect,
	Burning,
	Freezing,
	Shock,
	Slowness,
	Invisible,
};

enum SpellType
{
	NoSpellType,
	Damage,
	Buff,
	Debuff,
	Heal,
	Utility,
};
extern int spells;
extern bool spellsUnlocked[16];
extern int spellLevel[16];
extern int spellRequirement[16];
extern std::string spellNames[16];
extern int spellDamage[16];
extern int spellHeal[16];
extern int shownSpells;
extern bool spellsShown[16];
extern int spellEffect[16][16];


void allSpells();
void combatSpells();
int castSpell(int);

#endif