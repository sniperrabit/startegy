#include "Map.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


Map::Map() {
	Surf_Tileset = NULL;
}

const string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

bool Map::OnLoad(char* File, SDL_Renderer* renderer) {

	char result[200];   // array to hold the result.

	strcpy_s(result, ExePath().c_str());
	strcat_s(result, "\\");// copy string one into the result.
	strcat_s(result, File); // append string two to the result.

	
	FILE* FileHandle;
	fopen_s(&FileHandle, result, "r");

	if (FileHandle == NULL) {
		return false;
	}
	int i = 0;
	for (int y = 0; y < LEVEL_HEIGHT; y++) {
		for (int x = 0; x < LEVEL_WIDTH; x++) {
			Entity tempTile;

			fscanf_s(FileHandle, "%d ", &tempTile.id);
			if (tempTile.id==1){
				tempTile = Entity(i, "gfx/grass2.png", x, y, renderer, 1, 1, 8);			
				tempTile.TypeID = 1;
			}
			else if (tempTile.id == 2) {
				tempTile = Entity(i, "gfx/house.png", x, y, renderer, 1, 2, 8);
				tempTile.TypeID = 1;
			}
			else if (tempTile.id == 3) {
				tempTile = Entity(i, "gfx/house2.png", x, y, renderer, 2, 3, 8);
				tempTile.TypeID = 1;
			
			}

			i++;

			TileList.push_back(tempTile);
		}
		fscanf_s(FileHandle, "\n");
	}

	fclose(FileHandle);
/*
	int i = 0;
	for (int y = 0; y < LEVEL_HEIGHT; y++) {
		for (int x = 0; x < LEVEL_WIDTH; x++) {
			Entity tempTile;

			tempTile = Entity(i, "gfx/grass2.png", x, y, renderer, 1, 1, 8);
			tempTile.id = i;
			tempTile.TypeID = 1;
			TileList.push_back(tempTile);
			i++;
		}
		
	}
	*/
	return true;
}
//MapX and MapY arguments. These tell use where to render this map on the screen. 
void Map::OnRender(SDL_Renderer *renderer,int MapX, int MapY) {
	//if (Surf_Tileset == NULL) return;

//	int TilesetWidth = 64 / SHAPE_SIZE;
//	int TilesetHeight = 64 / SHAPE_SIZE;

	int ID = 0;

	for (int Y = 0; Y < LEVEL_HEIGHT; Y++) {
		for (int X = 0; X < LEVEL_WIDTH; X++) {
			if (TileList[ID].TypeID == TILE_TYPE_NONE) {
				ID++;
				continue;
			}
			Point* p = new Point(0,0);
			
			
//			int tX = MapX + (X * SHAPE_SIZE);
//			int tY = MapY + (Y * SHAPE_SIZE);
			 p->x = MapX + (X);
			 p->y = MapY + (Y);


			int TilesetX = (TileList[ID].id % TileList[ID].width) * SHAPE_SIZE;
			int TilesetY = (TileList[ID].id / TileList[ID].height) * SHAPE_SIZE;
		
			//render one tile
			Main::renderMap(renderer,TileList[ID].textureEntity, p, SHAPE_SIZE, TileList[ID].width, TileList[ID].height);
		//	CSurface::OnDraw( Surf_Tileset, tX, tY, TilesetX, TilesetY, SHAPE_SIZE, SHAPE_SIZE);

			ID++;
		}
	}
}

