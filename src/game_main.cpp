#include "game_main.h"

using namespace std;


float wallsize = 1.5f; //dimensione del muro in unità di gioco



void game_init(void){
    player_init();
    map_init();
    DisableCursor();
}

bool game_update(void){
    player_update();
    
    return false;//devo switchare al menu?
}

void game_draw(void){
    ClearBackground(BLACK);

    draw_ray(wallsize);
    player_draw();

}