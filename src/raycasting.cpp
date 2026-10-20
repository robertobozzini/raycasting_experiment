#include "raycasting.h"

using namespace std;

Color wall_color = {225, 225, 225, 255}; 

float cast_ray(float angle){

    float dx = cosf(angle);//direzione del raggio
    float dy = sinf(angle);

    float maxd = 100.0f; //distanza massima del raggio

    for(float d = 0; d < maxd; d += 0.01f){//passi piccoli -> max 100 unità
        float cx = player_pos.x + dx * d; //cella nella mappa in cui si trova il raggio
        float cy = player_pos.y + dy * d;

        if(MP[(int)cx][(int)cy] == '#'){ //se il raggio colpisce un muro
            return d;
        }
    }
    return maxd;//return 50.0f; massimo che puoi vedere (?)
}

void draw_ray(float wallsize){
    for(int x = 0; x < ScreenWidth; x++){
        float ray_angle = player_angle + FOV/2.0f - FOV * ((float)x / (float)ScreenWidth);
        float distance = cast_ray(ray_angle)* cosf(ray_angle - player_angle); //correzione della distorsione prospettica
        //per evitare l'effetto fish-eye, moltiplico la distanza per il coseno dell'angolo tra il raggio e la direzione del giocatore
        //quindi una specie di proiezione prospettica, perche' se il raggio è molto inclinato rispetto alla direzione del giocatore, la distanza apparente sarà maggiore di quella reale

        //disegno il muro
        float wall_height = ((float)ScreenHeight / distance) * wallsize;
        DrawLine(x, (ScreenHeight - wall_height) / 2.0f, x, (ScreenHeight + wall_height) / 2.0f, wall_color);
    }
}