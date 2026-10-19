#include "game_main.h"

using namespace std;

Vector2 player_pos;
float player_angle = 0.0f; // vedila come una circonferenza 0 è a destra, pi/2 in alto, pi a sinistra, 3pi/2 in basso
const float FOV = PI/3.0f; //campo visivo del giocatore

void game_init(void){
    map_init();
}

bool game_update(void){



    return false;//devo switchare al menu?
}

void game_draw(void){
    ClearBackground(BLACK);
    for(int x = 0; x < ScreenWidth; x++){
        float ray_angle = player_angle - FOV/2.0f + FOV * ((float)x / (float)ScreenWidth);
        float distance = cast_ray(ray_angle) * cosf(ray_angle - player_angle); //correzione della distorsione prospettica

        //disegno il muro
        float wall_height = ((float)ScreenHeight / distance);
        DrawLine(x, (ScreenHeight - wall_height) / 2.0f, x, (ScreenHeight + wall_height) / 2.0f, WHITE);
    }
}