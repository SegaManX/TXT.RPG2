#ifndef MAIN_H
#define MAIN_H

void outputInfo();


enum BooLeans
{
	Won,
	ClassSelected,
	HasBoat,
};

extern bool booLeans[4];
inline std::uniform_int_distribution d20Gen{ 1, 20 };
inline std::uniform_int_distribution d100Gen{ 1, 100 };

extern int hours;
extern int minutes;
extern int days;

extern int hunger;
extern int thirst;

#endif