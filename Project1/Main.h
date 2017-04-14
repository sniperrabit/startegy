#ifndef _MAIN_H_
#define _MAIN_H_

#include <SDL.h>
#include "CSurface.h"
#include "Point.h"
#include "Entity.h"
#include "Hero.h"
#include "CAnimation.h"
#include "Area.h"
#include "Camera.h"
#include <windows.h>

#include <map>
#include <string>
using namespace std;

#define SHAPE_SIZE 64
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define LEVEL_HEIGHT 6
#define LEVEL_WIDTH 6

class Entity;

class Main {

private:
	bool    Running;
	SDL_Surface*    Surf_Display;
	SDL_Surface*    Surf_Test;
	
	//std::map <int, Entity> EntityMap;
public:	
	//CAnimation      Anim_Yoshi;
	SDL_Renderer* renderer;
	//Entity    entityHero;

	Main();	
	int OnExecute();	
	bool OnInit();	
	void OnEvent(SDL_Event* Event);
	void OnLoop();
	

	
	void render(SDL_Renderer * renderer,  int size);
	static void renderMap(SDL_Renderer *renderer, SDL_Texture *tex, Point* p, int size, int w, int h);

	static void renderEntity(SDL_Renderer * renderer, Entity entity, Point * p, int X2, int Y2, int W, int H);

	void OnCleanup();
	
	
};

#endif