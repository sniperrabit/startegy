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
	std::vector<Map>       MapList;

	Map*    GetMap(int X, int Y);
	Entity*    GetTile(int X, int Y);

private:
	int                     AreaSize;

	SDL_Surface*        Surf_Tileset;
	SDL_Texture*  textureTile;
public:
	Area();

	bool    OnLoad(char* File, SDL_Renderer* renderer);

	void    OnRender(SDL_Renderer *renderer, int CameraX, int CameraY);

	void    OnCleanup();

};

#endif