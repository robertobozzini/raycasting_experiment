#include "raycasting.h"

using namespace std;

float cast_ray(float angle){

    float dx = cosf(angle);//direzione del raggio
    float dy = sinf(angle);

    for(float d = 0; d < 100.0f; d += 0.01f){//passi piccoli
        float cx = player_pos.x + dx * d; //cella nella mappa in cui si trova il raggio
        float cy = player_pos.y + dy * d;

        if(MP[(int)cy][(int)cx] == '#'){ //se il raggio colpisce un muro
            return d;
        }
    }
    return 50.0f;
}