#ifndef MAIN_H

#define MAIN_H//per evitare recursion

#include<raylib.h>
#include<vector>
#include<raymath.h>
#include<algorithm>
#include<map>
#include<thread>
#include<cmath>
#include<string>

#include "game_main.h"
#include "raycasting.h"
#include "map.h"
#include "player.h"

extern const int ScreenWidth;
extern const int ScreenHeight;
extern bool (*event_handler)(void);
extern void (*screen_drawer)(void);


#endif