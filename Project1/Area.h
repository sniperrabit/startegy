#ifndef _AREA_H_
#define _AREA_H_

#include "Area.h"
#include "Map.h"
#include "Entity.h"

class Map;
class Area {
public:
	static Area            AreaControl;

public:
	std::vector<Map> MapList;
	std::vector<Map> BuildingMapList;
	

	Map*    GetMap(std::vector<Map>& objectMapList, int X, int Y);
	Entity*    GetTile(std::vector<Map>& objectMapList, int X, int Y);

private:
	int                     AreaSize;

	SDL_Surface*        Surf_Tileset;
	SDL_Texture*  textureTile;
public:
	Area();	

	bool    OnLoad(char* File, std::vector<Map>& objectMapList, SDL_Renderer* renderer);

	void    OnRender(SDL_Renderer *renderer, std::vector<Map> & objectMapList, int CameraX, int CameraY);

	void    OnCleanup();

};

#endif