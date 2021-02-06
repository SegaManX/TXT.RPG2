#ifndef STARTUP_H
#define STARTUP_H

void startup();

extern int diff;
extern std::string playerName;
inline std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
extern int clasDmgStat;

#endif 
