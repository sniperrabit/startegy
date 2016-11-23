#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include "CSurface.h"
#include "Point.h"
#include "Entity.h"
#include "Hero.h"
#include "CAnimation.h"

#include <map>
#include <string>
using namespace std;

#define SHAPE_SIZE 64
#define SCREEN_WIDTH 1100
#define SCREEN_HEIGHT 800
#define LEVEL_HEIGHT 6
#define LEVEL_WIDTH 6

class Main {

private:
	bool    Running;
	SDL_Surface*    Surf_Display;
	SDL_Surface*    Surf_Test;
	SDL_Renderer* renderer;
	Point levelPoints[LEVEL_WIDTH*LEVEL_HEIGHT];

	int levelGround[LEVEL_WIDTH][LEVEL_HEIGHT] = {
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
	};

	int levelItems[LEVEL_WIDTH][LEVEL_HEIGHT] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 3, 0, 0, 2 },
		{ 0, 2, 0, 0, 2, 0 },
		{ 0, 0, 0, 0, 0, 2 },
	};

	Entity         Entity1;
	Entity         Entity2;
	Entity         Entity3;
	
	std::map <int, Entity> EntityMap;
public:
	Hero			Hero1;
	CAnimation      Anim_Yoshi;

	Main();
	
	int OnExecute();

public:

	bool OnInit();

	SDL_Texture * prepareRenderItems(SDL_Renderer * renderer, int i, map <int, Entity> &EntityMap);
	void OnEvent(SDL_Event* Event);
	void OnLoop();

	void renderItem(SDL_Texture *tex, SDL_Renderer *ren,Point* p, int size, int w, int h);

	void render(SDL_Renderer * renderer,  int size);

	

	void OnCleanup();


	void renderGround(SDL_Texture * tex, SDL_Renderer * ren, Point * p, int size, int w, int h);

	

};

#endif