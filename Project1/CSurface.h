#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include <SDL.h>
#include "Main.h"
#include "Hero.h"
#include "Point.h"
class CSurface {
public:
	CSurface();

public:
	
	//static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);

	static bool OnDraw(SDL_Renderer* renderer, Hero hero, Point& p, int X2, int Y2, int W, int H);

	static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};

#endif