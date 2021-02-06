#ifndef BATTLES_H
#define BATTLES_H

extern int lastWeapon;
extern int lastSpell;


void battleSetup();
void battle();

void trainingFight();
void alleyBanditFight();
void roadBanditFight();
void banditHideoutLookoutFight();
void banditHideoutGuardFight();
void banditHideoutKingFight();
void wolfFight();
void smitheryFight();
void mineFight();
void lumberyardFight();
void tarrinFight();
void tarCem1Fight();
void tarCem2Fight();
void tarCem3Fight();
void tarCem4Fight();
void oldPirateFight();
void pirateTrivia();
void bridgeFight();
void madthorneGoblinMineFight();
void madthorneCastleFight1();
void madthorneCastleFight2();
void madthorneCastleFight3();
void madthorneCastleFight4();
void darkCastleFight();

void attack(bool spelling = false);


extern int quest;
extern int enemiesKilled[100];




#endif // !BATTLES_H
