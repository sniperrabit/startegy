#ifndef _AREA_H_
#define _AREA_H_

#include "Area.h"
#include "Map.h"
#include "Entity.h"
#include <list>

class Map;
class Area {

private:
	int           AreaSize;
	SDL_Surface*  Surf_Tileset;
	SDL_Texture*  textureTile;

public:
	
	static			 Area AreaControl;
	std::vector<Map> MapList;
	std::vector<Map> BuildingMapList;
	std::list<Entity> EntityList;
	
	Area();
	Map*    GetMap(std::vector<Map>& objectMapList, int X, int Y);
	Entity* GetTile(std::vector<Map>& objectMapList, int X, int Y);

	
	bool    OnLoad(char* File, std::vector<Map>& objectMapList, SDL_Renderer* renderer);
	void    OnRender(SDL_Renderer *renderer, std::vector<Map> & objectMapList, int CameraX, int CameraY, Entity &entity = Entity(), int idPosEntity = NULL);
	void    OnCleanup();

};

#endif