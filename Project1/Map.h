#ifndef _MAP_H_
#define _MAP_H_

#include <SDL.h>
#include <vector>

#include "Entity.h"
#include "CSurface.h"

class Map {
public:
	SDL_Surface* Surf_Tileset;

private:
	std::vector<Entity> TileList;

public:
	Map();

public:
	bool OnLoad(char* File, SDL_Renderer* renderer);

	void OnRender(SDL_Renderer *renderer, int MapX, int MapY);
	
};

#endif