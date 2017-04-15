#include "Map.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
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
			if (tempTile.id == 0) {
				tempTile = Entity(i, TILE_TYPE_NONE, "gfx/grass2.png", x, y, renderer, 1, 1, 8);
				//tempTile.TypeID = 0;
			}
			else if (tempTile.id==1){
				tempTile = Entity(i, TILE_TYPE_NORMAL, "gfx/grass2.png", x, y, renderer, 1, 1, 8);
				//tempTile.TypeID = 1;
			}
			else if (tempTile.id == 2) {
				tempTile = Entity(i, TILE_TYPE_BLOCK, "gfx/house.png", x, y, renderer, 1, 2, 8);
				//tempTile.TypeID = 1;
			}
			else if (tempTile.id == 3) {
				tempTile = Entity(i, TILE_TYPE_BLOCK, "gfx/house2.png", x, y, renderer, 2, 3, 8);
				
				//tempTile.TypeID = 1;
			
			}
			else if (tempTile.id == 8) {
				tempTile = Entity(i, TILE_TYPE_BLOCK, "xx", x, y, renderer, 1, 1, 8);
				//tempTile.TypeID = 1;
			}

			if (tempTile.id == 9) { //HERO		
				tempTile =Entity();
			//	tempTile =new Entity(i, ENTITY_TYPE_PLAYER, "gfx/yoshi2.png", x, y, renderer, 1, 1, 8);			
				tempTile.OnLoad(i, ENTITY_TYPE_PLAYER, "gfx/yoshi2.png", x, y, renderer, 1, 1, 8);
				
				Area::AreaControl.EntityList.push_back(tempTile);
				//tempTile.TypeID = 9;
			//	Entity* enPtr;
			//	enPtr=&Area::AreaControl.EntityList.back();
				tempTile.heroPtr = &tempTile;
				tempTile = Entity(i, TILE_TYPE_NONE, "gfx/grass2.png", x, y, renderer, 1, 1, 8);
			}
			

			i++;

			TileList.push_back(tempTile);
		}
		fscanf_s(FileHandle, "\n");
	}
fclose(FileHandle);
return true;
}
//MapX and MapY arguments. These tell use where to render this map on the screen. 
void Map::OnRender(SDL_Renderer *renderer,int MapX, int MapY, Entity &hero) {
//	printf("RENDER\n");
	int ID = 0;
	for (int Y = 0; Y < LEVEL_HEIGHT; Y++) {
		for (int X = 0; X < LEVEL_WIDTH; X++) {

		
		
			Point* p = new Point(0,0);
						
//			int tX = MapX + (X * SHAPE_SIZE);
//			int tY = MapY + (Y * SHAPE_SIZE);
			 p->x = MapX + (X);
			 p->y = MapY + (Y);


			int TilesetX = (TileList[ID].id % TileList[ID].width) * SHAPE_SIZE;
			int TilesetY = (TileList[ID].id / TileList[ID].height) * SHAPE_SIZE;
			

			int hx = (int)floor(hero.point.x + 0.5) % LEVEL_WIDTH;
			int hy = (int)floor(hero.point.y + 0.9) % LEVEL_HEIGHT;
			
			//Render Hero
			if (hero.TypeID ==ENTITY_TYPE_PLAYER && (hy == Y && hx == X)){
				
				hero.point.x -= Camera::CameraControl.GetX();
				hero.point.y -= Camera::CameraControl.GetY();
				Point* p = new Point(hero.point.x + LEVEL_WIDTH, hero.point.y - LEVEL_HEIGHT);//OFFSET
																								
				Main::renderEntity(renderer, hero, p, hero.CurrentFrameCol * SHAPE_SIZE_IMG, (hero.CurrentFrameRow + hero.Anim_Control.GetCurrentFrame()) * SHAPE_SIZE_IMG, hero.width, hero.height);
//				printf("[%d,%d] renderEntity \n", X, Y);
				delete p;
				ID++;
				
			}else if (TileList[ID].TypeID == TILE_TYPE_NONE) {//Empty tile, not render ,next ID
				ID++;
				continue;
			} else { //Entity building render

				//render one tile
				Main::renderMap(renderer, TileList[ID].textureEntity, p, SHAPE_SIZE, TileList[ID].width, TileList[ID].height);
		//		printf("[%d,%d] renderMap \n", X, Y);
				delete p;
				ID++;			
			}			
		}
	}
}

Entity* Map::GetTile(float X, float Y) {
	int ID = 0;

	ID = abs(X) / TILE_SIZE;
	int a = (abs(Y) / TILE_SIZE);
	ID = ID + (LEVEL_WIDTH * a);
	printf("GET TILE: %f, %f \n",X,Y);

	if (ID < 0 || ID >= TileList.size()) {
		printf("ID tile not found in map\n");
		return NULL;
	}
	
	printf("ID tile in map: %d\n",ID);
	return &TileList[ID];
}