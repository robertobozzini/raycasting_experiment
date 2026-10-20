#include "player.h"

using namespace std;

Vector2 player_pos;
float player_angle; // vedila come una circonferenza 0 è a destra, pi/2 in basso, pi a sinistra, 3pi/2 in alto
const float FOV = PI/3.0f; //campo visivo del giocatore
const float turn_speed = 3.5e-3; //velocità di rotazione del giocatore
const float move_speed = 3.5f; //velocità di movimento del giocatore
const float player_radius = 0.2f; //raggio del giocatore, per la collisione con i muri

void player_init(void){
    player_angle = 0.0f;
}

static bool collides(float x, float y){
    bool collision = false;
    if(MP[(int)(x - player_radius)][(int)(y - player_radius)] == '#' ||
       MP[(int)(x + player_radius)][(int)(y - player_radius)] == '#' ||
       MP[(int)(x - player_radius)][(int)(y + player_radius)] == '#' ||
       MP[(int)(x + player_radius)][(int)(y + player_radius)] == '#'){
        collision = true;
    }
    return collision;
}

bool firstframe = true;
void player_update(void){
    float dt = GetFrameTime();

    if(IsKeyPressed(KEY_SPACE)){
        IsCursorHidden() ? EnableCursor() : DisableCursor();
    }

    Vector2 deltamousepos = IsCursorHidden() && !firstframe ? GetMouseDelta() : (Vector2){0, 0};
    firstframe = false;

    player_angle -= deltamousepos.x * turn_speed;
    float stepy = (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)) * move_speed * dt;//dritto
    float stepx = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * move_speed * dt;//diagonale

    float dx = cosf(player_angle) * stepy + sinf(player_angle) * stepx; //cos(a + pi/2) = sin(a)
    float dy = sinf(player_angle) * stepy - cosf(player_angle) * stepx; //sin(a + pi/2) = -cos(a)
    //cout<<"deltamousepos.x: "<<deltamousepos.x<<" deltamousepos.y: "<<deltamousepos.y<<endl;
    //cout<<"player_pos.x: "<<player_pos.x<<" player_pos.y: "<<player_pos.y<<endl;
    //cout<<"player_angle: "<<player_angle<<endl;
    
    float new_x = player_pos.x + dx;
    float new_y = player_pos.y + dy;

    if(!collides(new_x, new_y)){ //se non c'è un muro
        player_pos.x = new_x;
        player_pos.y = new_y;
    }
    else if(!collides(new_x, player_pos.y)){ //se non c'è un muro
        player_pos.x = new_x;
    }
    else if(!collides(player_pos.x, new_y)){ //se non c'è un muro
        player_pos.y = new_y;
    }
}

void player_draw(void){
    //draw player

    //draw crosshair
    DrawLine(ScreenWidth/2 - 10, ScreenHeight/2, ScreenWidth/2 + 10, ScreenHeight/2, BLACK);
    DrawLine(ScreenWidth/2, ScreenHeight/2 - 10, ScreenWidth/2, ScreenHeight/2 + 10, BLACK);
}