#ifndef _MAP_H_
#define _MAP_H_
#include "Entity.h"
#include <SDL.h>
#include <vector>


#include "CSurface.h"
class Entity;
class Map {
public:
	SDL_Surface* Surf_Tileset;
	Entity* GetTile(float X, float Y);

private:
	std::vector<Entity> TileList;

public:
	Map();

public:
	bool OnLoad(char* File, SDL_Renderer* renderer);

	void OnRender(SDL_Renderer *renderer, int MapX, int MapY);
	
};

#endif