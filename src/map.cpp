#include "map.h"

using namespace std;
vector<vector<char>>MP;

filesystem::path map_path = "../maps/map0.txt";

int map_height;
int map_width;


void map_init(void){
    ifstream map_file;
    map_file.open(map_path.string());

    if(!map_file.is_open()){
        cout<<"Map file not found"<<endl;
        return;
    }
    vector<string> map_lines;
    //devo invertire x e y, perche' la mappa è scritta in righe e colonne, ma il player_pos è in coordinate cartesiane
    string s;
    map_height = 0;
    map_width = 0;

    while(getline(map_file,s)){
        map_height++;
        if(map_height == 1){
            map_width = s.size();
        }
        map_lines.push_back(s);
        //string s;
        //getline(map_file,s);
        //MP.push_back(vector<char>());
        //MP[map_height - 1].resize(map_width);
    }
    MP.assign(map_width, vector<char>(map_height));
    for(int i=0;i<map_height;i++){
        for(int j=0;j<map_width;j++){
            MP[j][i] = map_lines[i][j];
            if(map_lines[i][j] == 'P'){
                player_pos = {j + 0.5f, i + 0.5f};//x, y, +0.5 to center the player in the cell
                MP[j][i] = '.';//replace P with empty space
            }
        }
    }

}

float minimap_fract = 5.0f; //quale dello schermo è la minimappa

float minimap_cellsize = 0; //dimensione di una cella della mappa in pixel
float minimap_width = 0; //dimensione della mappa in pixel
float minimap_height = 0; //dimensione della mappa in pixel

Rectangle minimap_rect; //rettangolo della minimappa
Color minimap_color = floor_color; //colore della minimappa //colore dei muri della minimappa
Color player_color = {0, 255, 0, 255}; //colore del giocatore sulla minimappa
Color border_color = {0, 0, 0, 255}; //colore del bordo della minimappa
//wall_color è il colore dei muri
float padding = 10.0f; //padding tra la minimappa e il bordo dello schermo

float border = 10.0f; //spessore del bordo della minimappa

void minimap_init(void){

    float minimap_mxsize = (float)ScreenHeight / minimap_fract;


    if(map_width > map_height){
        minimap_cellsize = (float)minimap_mxsize / map_width;
    }
    else{
        minimap_cellsize = (float)minimap_mxsize / map_height;
    }
    minimap_width = map_width * minimap_cellsize;
    minimap_height = map_height * minimap_cellsize;

    minimap_rect = {(float)ScreenWidth - minimap_width - border - padding, border + padding, minimap_width, minimap_height};

}

float fill_gaps = 0.1f;

void minimap_draw(void){
    DrawRectangle(minimap_rect.x - border, minimap_rect.y - border,
         minimap_rect.width + 2*border, minimap_rect.height + 2*border, border_color);
    DrawRectangleRec(minimap_rect, minimap_color);

    for(int y=0;y<map_height;y++){
        for(int x=0;x<map_width;x++){
            if(MP[x][y] == '#'){
                DrawRectangle(minimap_rect.x + x * minimap_cellsize, minimap_rect.y + y * minimap_cellsize,
                 minimap_cellsize + fill_gaps, minimap_cellsize + fill_gaps, wall_color);
            }
        }
    }
    //draw player
    DrawCircle(minimap_rect.x + player_pos.x * minimap_cellsize, 
        minimap_rect.y + player_pos.y * minimap_cellsize, 
        minimap_cellsize/3.0f, player_color);
}
