#include "raycasting.h"

using namespace std;

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