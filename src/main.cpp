#include "main.h"

using namespace std;

const int ScreenWidth = 1500;
const int ScreenHeight = 1000;

bool (*event_handler)(void);//coso figo
void (*screen_drawer)(void);

int main(){
    InitWindow(ScreenWidth, ScreenHeight, "raycasting experiment");
    SetTargetFPS(60);
    SetExitKey(KEY_ESCAPE);
    
    event_handler = game_update;//ora lasciamo cosi, in caso dopo voglio fare la lobby cambio
    screen_drawer = game_draw;

    game_init();
    while(!WindowShouldClose()){

        if(event_handler != nullptr){
            event_handler();
        }

        BeginDrawing();
        //ClearBackground(RAYWHITE);
        if(screen_drawer != nullptr){
            screen_drawer();
        }
        EndDrawing();
    }


}