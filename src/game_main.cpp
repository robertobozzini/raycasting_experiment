#include "game_main.h"

using namespace std;

Vector2 player_pos;
float player_angle = 0.0f; // vedila come una circonferenza 0 è a destra, pi/2 in basso, pi a sinistra, 3pi/2 in alto
const float FOV = PI/3.0f; //campo visivo del giocatore
float turn_speed = 3.5e-3; //velocità di rotazione del giocatore
float move_speed = 3.5f; //velocità di movimento del giocatore
float wallsize = 1.5f; //dimensione del muro in unità di gioco



void game_init(void){
    map_init();
    DisableCursor();
}

bool game_update(void){
    float dt = GetFrameTime();

    if(IsKeyPressed(KEY_SPACE)){
        IsCursorHidden() ? EnableCursor() : DisableCursor();
    }

    Vector2 deltamousepos = IsCursorHidden() ? GetMouseDelta() : (Vector2){0, 0};

    player_angle -= deltamousepos.x * turn_speed;
    float stepy = (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)) * move_speed * dt;//dritto
    float stepx = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * move_speed * dt;//diagonale

    float new_x = player_pos.x + cosf(player_angle) * stepy + sinf(player_angle) * stepx; //cos(a + pi/2) = sin(a)
    float new_y = player_pos.y + sinf(player_angle) * stepy - cosf(player_angle) * stepx; //sin(a + pi/2) = -cos(a)
    /*
    cout<<"player_pos.x: "<<player_pos.x<<" player_pos.y: "<<player_pos.y<<endl;
    cout<<"new_x: "<<new_x<<" new_y: "<<new_y<<endl;
    cout<<"player_angle: "<<player_angle<<endl;
    */
    if(MP[(int)new_x][(int)new_y] != '#'){ //se non c'è un muro
        player_pos.x = new_x;
        player_pos.y = new_y;
    }
    
    return false;//devo switchare al menu?
}

void game_draw(void){
    ClearBackground(BLACK);
    for(int x = 0; x < ScreenWidth; x++){
        float ray_angle = player_angle + FOV/2.0f - FOV * ((float)x / (float)ScreenWidth);
        float distance = cast_ray(ray_angle)* cosf(ray_angle - player_angle); //correzione della distorsione prospettica
        //per evitare l'effetto fish-eye, moltiplico la distanza per il coseno dell'angolo tra il raggio e la direzione del giocatore
        //quindi una specie di proiezione prospettica, perche' se il raggio è molto inclinato rispetto alla direzione del giocatore, la distanza apparente sarà maggiore di quella reale

        //disegno il muro
        float wall_height = ((float)ScreenHeight / distance) * wallsize;
        DrawLine(x, (ScreenHeight - wall_height) / 2.0f, x, (ScreenHeight + wall_height) / 2.0f, WHITE);
    }

    //draw crosshair
    DrawLine(ScreenWidth/2 - 10, ScreenHeight/2, ScreenWidth/2 + 10, ScreenHeight/2, BLACK);
    DrawLine(ScreenWidth/2, ScreenHeight/2 - 10, ScreenWidth/2, ScreenHeight/2 + 10, BLACK);
}