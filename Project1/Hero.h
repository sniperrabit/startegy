#ifndef _HERO_H_
#define _HERO_H_

#include <vector>

//#include "CAnimation.h"
#include "Point.h"
#include <map>
#include <string>
using namespace std;

#include "Entity.h"

class Hero : public Entity {
public:
	Hero();
protected:
	
public:
	/*CAnimation      Anim_Control;
	int		id;
	char* path;
	char* facing;
	SDL_Surface*    Surf_Hero;
	SDL_Texture*  Texture_Hero;
	Point         Cpoint;
	float           Isox;
	float           Isoy;
	int             width;
	int             height;
	int             AnimState;
	int MaxFrames;*/
public:
	
	//Hero(int id, char* path, int x, int y, int width, int  height);

	bool OnLoad(int id,char* File,int x, int y, SDL_Renderer* renderer, int Width, int Height, int MaxFrames);

	void OnLoop();

	void OnAnimate();

	bool OnCollision(Entity* Entity);
};
#endif