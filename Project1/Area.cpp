#include "Area.h"
#include <SDL_image.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


Area Area::AreaControl;

Area::Area() {
	AreaSize = 0;
}

string ExePath2() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

bool Area::OnLoad(char* File, SDL_Renderer* renderer) {
	MapList.clear();
	
	char result[200];   // array to hold the result.

	strcpy_s(result, ExePath2().c_str());
	strcat_s(result, "\\");// copy string one into the result.
	strcat_s(result, File); // append string two to the result.


	FILE* FileHandle;
	
	fopen_s(&FileHandle, result, "r");

	if (FileHandle == NULL) {
		return false;
	}

	char tilePath[255];


	//.png
	//fscanf_s(FileHandle, "%s\n", &tilePath);
	char buf[150];
	char buf2[150];
	fgets(buf, sizeof buf, FileHandle);

	int a = 0;
	while (buf[a] != '\n') {
		buf2[a] = buf[a];
		a++;
	}
	buf2[a] = '\0';
	//O matko, jeba..y c++

	Surf_Tileset = IMG_Load(buf2);
	textureTile = SDL_CreateTextureFromSurface(renderer, Surf_Tileset);
	SDL_FreeSurface(Surf_Tileset);

	fscanf_s(FileHandle, "%d\n", &AreaSize);	
	//3x3
	
	for (int X = 0; X < AreaSize; X++) {
		for (int Y = 0; Y < AreaSize; Y++) {
			char MapFile[20];
			
			fscanf_s(FileHandle, "%s", MapFile, 20);

			char fullPath[25];  
			strcpy_s(fullPath, MapFile);
			strcat_s(fullPath, ".txt");

			//set tileset vector with id (Entity)
			Map tempMap;
			if (tempMap.OnLoad(fullPath,renderer) == false) {
				fclose(FileHandle);
				return false;
			}

			//set in map object surface with tilesets
			tempMap.Surf_Tileset = Surf_Tileset;

			//add to map list this map
			MapList.push_back(tempMap);
		}
		fscanf_s(FileHandle, "\n");
	}	
	fclose(FileHandle);

	return true;
}

void Area::OnRender(SDL_Renderer *renderer, int CameraX, int CameraY) {
	int MapWidth = LEVEL_WIDTH ;//6*64//384
	int MapHeight = LEVEL_HEIGHT;

	int FirstID = -CameraX / MapWidth;//Id of title field
	FirstID = FirstID + ((-CameraY / MapHeight) * AreaSize);

	//Every time render only 4 maps
	for (int i = 0; i < 9; i++) {
		//Disablerendering only 4 map
/*		int ID = FirstID + ((i / 2) * AreaSize) + (i % 2);

		if (ID < 0 || ID >= MapList.size()) continue;
		int X = ((ID % AreaSize) * MapWidth) + CameraX;
		int Y = ((ID / AreaSize) * MapHeight) + CameraY;

		//render map on x,y
		MapList[ID].OnRender(renderer,X+LEVEL_WIDTH, Y - LEVEL_HEIGHT);
*/		
		//Render all maps
		int X = ((i % AreaSize) * MapWidth) + CameraX;
		int Y = ((i / AreaSize) * MapHeight) + CameraY;
		MapList[i].OnRender(renderer, X + LEVEL_WIDTH, Y - LEVEL_HEIGHT);
	}
}

void Area::OnCleanup() {
	if (Surf_Tileset) {
		SDL_FreeSurface(Surf_Tileset);
	}

	MapList.clear();
}

Map* Area::GetMap(int X, int Y) {
	int MapWidth = MAP_WIDTH * TILE_SIZE;
	int MapHeight = MAP_HEIGHT * TILE_SIZE;

	int ID = X / MapWidth;
	ID = ID + ((Y / MapHeight) * AreaSize);

	if (ID < 0 || ID >= MapList.size()) {
		return NULL;
	}

	return &MapList[ID];
}

Entity* Area::GetTile(int X, int Y) {
	int MapWidth = MAP_WIDTH * TILE_SIZE;
	int MapHeight = MAP_HEIGHT * TILE_SIZE;

	Map* Map = GetMap(X, Y);

	if (Map == NULL) return NULL;

	X = X % MapWidth;
	Y = Y % MapHeight;

	return Map->GetTile(X, Y);
}