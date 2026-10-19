#include "game_main.h"

using namespace std;

Vector2 player_pos;
float player_angle = 0.0f; // vedila come una circonferenza 0 è a destra, pi/2 in basso, pi a sinistra, 3pi/2 in alto
const float FOV = PI/3.0f; //campo visivo del giocatore
float turn_speed = 2.0f; //velocità di rotazione del giocatore
float move_speed = 3.0f; //velocità di movimento del giocatore
void game_init(void){
    map_init();
}

bool game_update(void){
    float dt = GetFrameTime();
    if(IsKeyDown(KEY_A)){
        player_angle -= turn_speed * dt;
    }
    if(IsKeyDown(KEY_D)){
        player_angle += turn_speed * dt;
    }

    float step = (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)) * move_speed * dt;

    float new_x = player_pos.x + cosf(player_angle) * step;
    float new_y = player_pos.y + sinf(player_angle) * step;
    if(MP[(int)new_y][(int)new_x] != '#'){ //se non c'è un muro
        player_pos.x = new_x;
        player_pos.y = new_y;
    }
    
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