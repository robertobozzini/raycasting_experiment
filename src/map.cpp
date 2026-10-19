#include "map.h"
#include "game_main.h"

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

    string s;
    map_height = 0;
    map_width = 0;

    for(getline(map_file, s); !map_file.eof(); getline(map_file, s)){
        map_height++;
        if(map_height == 1){
            map_width = s.size();
        }
        //string s;
        //getline(map_file,s);
        MP.push_back(vector<char>());
        MP[map_height - 1].resize(map_width);
        for(int j=0;j<map_width;j++){
            MP[map_height - 1][j] = s[j];
            if(s[j] == 'P'){
                player_pos = {j, map_height - 1};//x, y
            }
        }
    }

}
