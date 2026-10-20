#ifndef GAMEMN_H

#define GAMEMN_H//per evitare recursion

#include "main.h"

using namespace std;

extern Color floor_color;
extern Color ceil_color;

void game_init(void);
bool game_update(void);
void game_draw(void);
#endif