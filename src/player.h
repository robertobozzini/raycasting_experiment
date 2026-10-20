#ifndef PLAYER_H
#define PLAYER_H

#include "main.h"

using namespace std;

extern Vector2 player_pos;
extern float player_angle;
extern const float FOV;
extern const float turn_speed;
extern const float move_speed;
extern const float player_radius;

void player_init(void);
void player_update(void);
void player_draw(void);
#endif