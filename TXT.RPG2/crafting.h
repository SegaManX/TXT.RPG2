#ifndef CRAFTING_H
#define CRAFTING_H

int itemValueOutput(int valuableItem, bool shop);
void craftGear(int craftItem, int material);
void meltOre(int ore);
void makeAlloys(int alloy);
void repairGear(int repairItem);

#endif // !CRAFTING_H
