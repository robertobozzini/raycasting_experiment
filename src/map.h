#ifndef MAP_H

#define MAP_H//per evitare recursion

#include "main.h"
#include<fstream>
#include<iostream>
#include<filesystem>

extern vector<vector<char>>MP;
extern filesystem::path map_path;
extern int map_height;
extern int map_width;

void map_init(void);

#endif