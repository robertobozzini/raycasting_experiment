#ifndef RAYCAST_H

#define RAYCAST_H//per evitare recursion

#include "main.h"
#include "map.h"
#include "game_main.h"

extern Color wall_color;

float cast_ray(float angle);
void draw_ray(float wallsize);
#endif