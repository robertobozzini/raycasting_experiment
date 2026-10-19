#ifndef GAMEMN_H

#define GAMEMN_H//per evitare recursion

#include "main.h"

extern Vector2 player_pos;

void game_init(void);
bool game_update(void);
void game_draw(void);
#endif