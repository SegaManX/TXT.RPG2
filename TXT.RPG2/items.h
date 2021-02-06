#ifndef ITEMS_H
#define ITEMS_H

enum Items
{

	NoItem,
	Sword,
	Bow,
	Staff,
	Torch,
	
	
	LastItem
};
enum suffixEnchants
{
	NoSuffix,
	Fire,
	Poison,
	Ice,
	blood, // lifesteal
	Lightning,

	LastSuffixEnchant
};

extern int itemCount;
extern int item[100];
extern int itemMaxDurability[100];
extern int itemDurability[100];
extern int itemAmount[100];
extern int itemEnchant[100];
extern int itemLevel[100];
extern int itemRequirement[100];
extern int itemsInInventory;
extern int shownItems;

extern bool itemShown[100];

extern std::string itemName[100];
extern bool rangedWeapon[100];
extern bool magicWeapon[100];
extern int itemBuildReq[100];

extern int potions[10];


void allItems();
void combatItems();
void utilityItems();
int damageOutput();
void suffix(int itemEnchant);

#endif // !ITEMS_H

