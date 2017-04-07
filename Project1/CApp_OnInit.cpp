#include "Main.h"
#include <stdio.h>
#include <SDL_image.h>

#include <map>
#include <string>
using namespace std;

bool Main::OnInit() {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		return false;
	}
	
	SDL_Window* window = NULL;
	

	window = SDL_CreateWindow("Game Main View",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (window == NULL) {
		fprintf(stderr, "Window could not be created: %s\n", SDL_GetError());
		return false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		fprintf(stderr, "Renderer could not be created: %s\n", SDL_GetError());
		SDL_Quit();
		return false;
	}
		
	
	if (Area::AreaControl.OnLoad("layers/ground/1area.txt", Area::AreaControl.MapList, renderer) == false) {
		return false;
	}
	if (Area::AreaControl.OnLoad("layers/building/1area.txt", Area::AreaControl.BuildingMapList, renderer) == false) {
		return false;
	}
	
	Hero3.OnLoad(3, "gfx/yoshi2.png", 0, 0, renderer, 1, 1, 8);
	Entity::EntityList.push_back(&Hero3);
 
//	Camera::CameraControl.TargetMode = TARGET_MODE_CENTER;
//	Camera::CameraControl.SetTarget(&Hero3.point.x, &Hero3.point.y);

	EntityMap.insert(pair<int, Entity>(1, Entity(1, TILE_TYPE_NORMAL, "gfx/grass2.png",  1, 1, renderer,1,1,8)));
	EntityMap.insert(pair<int, Entity>(2, Entity(2, TILE_TYPE_BLOCK, "gfx/house.png",  1, 2, renderer, 1, 2, 8)));
	EntityMap.insert(pair<int, Entity>(3, Entity(3, TILE_TYPE_BLOCK, "gfx/house2.png",  2, 3, renderer, 2,3, 8)));	

	return true;
}




