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
