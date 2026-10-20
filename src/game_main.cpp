#include "game_main.h"

using namespace std;


float wallsize = 1.5f; //dimensione del muro in unità di gioco

Rectangle floor_rect; //rettangolo della minimappa
Color floor_color = {50, 50, 50, 255}; //colore del pavimento della minimappa
Color ceil_color = {150, 150, 150, 255}; //colore del soffitto della minimappa

void game_init(void){
    DisableCursor();
    
    player_init();
    map_init();
    minimap_init();

    floor_rect = {0, (float)ScreenHeight/2.0f, (float)ScreenWidth, (float)ScreenHeight/2.0f};
}

bool game_update(void){
    player_update();
    
    return false;//devo switchare al menu?
}

void game_draw(void){
    ClearBackground(ceil_color);
    DrawRectangleRec(floor_rect, floor_color);

    draw_ray(wallsize);
    player_draw();
    minimap_draw();
    
}