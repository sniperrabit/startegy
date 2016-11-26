#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>

#include "CAnimation.h"
#include "Point.h"
#include <map>
#include <string>
using namespace std;

enum {
	TILE_TYPE_NONE = 0,

	TILE_TYPE_NORMAL = 1,
	TILE_TYPE_BLOCK 
};

class Entity {
protected:
	
public:
	CAnimation      Anim_Control;
	int		id;
	char* path;
	Point         Cpoint;
	int     TypeID;
	float           Isox;
	float           Isoy;
	int             width;
	int             height;
	int             AnimState;
	SDL_Surface *surfaceEntity;
	SDL_Texture*    textureEntity;
	int MaxFrames;
public:
	Entity();
	Entity(int id, char* path,  int width, int  height);
	Entity(int id, char* File, int x, int y, SDL_Renderer* renderer, int Width, int Height, int MaxFrames);
	virtual ~Entity();


//	virtual bool OnLoad(char* File, SDL_Renderer* renderer, int Width, int Height, int MaxFrames);

//	virtual void OnLoop();

//	virtual void OnRender(SDL_Surface* Surf_Display);

//	virtual void OnCleanup();
};
#endif