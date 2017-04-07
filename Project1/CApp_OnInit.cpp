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
//	Hero2.OnLoad(2, "gfx/yoshi2.png", 10, 3, renderer, 1, 1, 8);


	Entity::EntityList.push_back(&Hero3);
 //   Entity::EntityList.push_back(&Hero2);
//	Camera::CameraControl.TargetMode = TARGET_MODE_CENTER;
//	Camera::CameraControl.SetTarget(&Hero3.point.x, &Hero3.point.y);



//	Hero1.OnLoad(1, "gfx/yoshi.png",9,1, renderer, 1, 1, 8);

//	Anim_Yoshi.MaxFrames = 8;
//	Anim_Yoshi.Oscillate = true;
	
	EntityMap.insert(pair<int, Entity>(1, Entity(1, TILE_TYPE_NORMAL, "gfx/grass2.png",  1, 1, renderer,1,1,8)));
	EntityMap.insert(pair<int, Entity>(2, Entity(2, TILE_TYPE_BLOCK, "gfx/house.png",  1, 2, renderer, 1, 2, 8)));
	EntityMap.insert(pair<int, Entity>(3, Entity(3, TILE_TYPE_BLOCK, "gfx/house2.png",  2, 3, renderer, 2,3, 8)));



	int xTiles = LEVEL_WIDTH;
	int yTiles = LEVEL_HEIGHT;

	//Generate array of pointers Cartezjan

	for (int i = 0; i < (xTiles * yTiles); ++i) {
		Point *p = new Point();
		//render on right side of view x + ((SCREEN_WIDTH / SHAPE_SIZE) / 2)
		levelPoints[i].x = (i % xTiles) +((SCREEN_WIDTH / SHAPE_SIZE) / 2);
		levelPoints[i].y = (i / xTiles );
	}

//	SDL_Texture* texture;
/*	//Render ground
	int k = 0;
	for (int i = 0; i < LEVEL_WIDTH; i++) {
		for (int j = 0; j < LEVEL_HEIGHT; j++) {
			if (levelGround[i][j] != 0) {
				texture = Main::prepareRenderItems(renderer, levelGround[i][j], EntityMap);
				Main::renderGround(texture, renderer, &levelPoints[k], SHAPE_SIZE, EntityMap[levelGround[i][j]].width, EntityMap[levelGround[i][j]].height);

			}
			k++;
		}
	}

	//Render items
	int k = 0;
	
	for (int i = 0; i < LEVEL_WIDTH; i++) {
		for (int j = 0; j < LEVEL_HEIGHT; j++) {
			if (levelItems[i][j] != 0) {

				texture = Main::prepareRenderItems(renderer, levelItems[i][j], EntityMap);
				Main::renderItem(texture, renderer, &levelPoints[k], SHAPE_SIZE, EntityMap[levelItems[i][j]].width, EntityMap[levelItems[i][j]].height);
			//		Main::render(texture, renderer, &levelPoints[k], SHAPE_SIZE);

			//		if (levelItems[i][j] == 2) {
			//		Main::render(Items2, renderer, &levelPoints[k], SHAPE_SIZE, SHAPE_SIZE*2, SHAPE_SIZE * 3);
			//	}
			}
			k++;
		}
	}
	*/


			/* render background, whereas NULL for source and destination
			rectangles just means "use the default" */
	//		SDL_RenderCopy(renderer, Background_Tx, NULL, NULL);

			/* render the current animation step of our shape */
//			SDL_RenderCopy(renderer, BlueShapes, &SrcR, &DestR);


	return true;
}


SDL_Texture* Main::prepareRenderItems(SDL_Renderer* renderer,int i, map <int, Entity> &EntityMap) {

	SDL_Surface* Surf_Temp = NULL;
	SDL_Texture* Texture;

	if (EntityMap.find(i) == EntityMap.end()) {
		// not found
	}
	else {
		char* path = EntityMap.find(i)->second.path;

		Surf_Temp = IMG_Load(path);
	}
	
	
	Texture = SDL_CreateTextureFromSurface(renderer, Surf_Temp);
	SDL_FreeSurface(Surf_Temp);

	return Texture;
}


