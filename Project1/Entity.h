#include <vector>

#include "CAnimation.h"
#include "Point.h"
#include <map>
#include <string>
using namespace std;

class Entity {
	
protected:
	CAnimation      Anim_Control;


public:
	int		id;
	char* path;
	Point         Cpoint;
	float           Isox;
	float           Isoy;
	int             width;
	int             height;
	int             AnimState;
	SDL_Surface *surfaceEntity;
	SDL_Texture*    textureEntity;
public:
	Entity::Entity();
	Entity::Entity(int id, char* path,  int width, int  height);
	Entity::Entity(int id, char* File, int x, int y, SDL_Renderer* renderer, int Width, int Height, int MaxFrames);
	virtual ~Entity();


//	virtual bool OnLoad(char* File, SDL_Renderer* renderer, int Width, int Height, int MaxFrames);

//	virtual void OnLoop();

//	virtual void OnRender(SDL_Surface* Surf_Display);

//	virtual void OnCleanup();
};