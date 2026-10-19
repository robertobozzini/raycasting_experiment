#ifndef GAMEMN_H

#define GAMEMN_H//per evitare recursion

#include "main.h"

using namespace std;

extern Vector2 player_pos;
extern float player_angle;
extern const float FOV;

void game_init(void);
bool game_update(void);
void game_draw(void);
#endif