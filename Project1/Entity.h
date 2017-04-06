#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>

#include "CAnimation.h"
#include "Point.h"
#include <map>
#include <string>
#include <vector>
#include "Camera.h"
#include "FPS.h"


using namespace std;

enum {
	TILE_TYPE_NONE = 5,
	TILE_TYPE_NORMAL = 6,
	TILE_TYPE_BLOCK = 7
};

enum {
	ENTITY_TYPE_GENERIC = 0,
	ENTITY_TYPE_PLAYER
};

enum {
	ENTITY_FLAG_NONE = 0,

	ENTITY_FLAG_GRAVITY = 0x00000001,
	ENTITY_FLAG_GHOST = 0x00000002,
	ENTITY_FLAG_MAPONLY = 0x00000004
};

class Entity {
protected:
	
public:
	static std::vector<Entity*>    EntityList;
	CAnimation      Anim_Control;
	int             AnimState;

	int		id;
	char* path;
	Point         point;
	int     TypeID;
	float           Isox;
	float           Isoy;
	int             width;
	int             height;
	
	SDL_Surface *surfaceEntity;
	SDL_Texture*    textureEntity;
	int MaxFrames;

	bool MoveUp;
	bool MoveDown;
	bool        MoveLeft;
	bool        MoveRight;
	int        Type;
	bool        Dead;
	int        Flags;
	float        MaxSpeedX;
	float        MaxSpeedY;
	int          CurrentFrameCol;
	int          CurrentFrameRow;
protected:
	
	float        SpeedX;
	float        SpeedY;
	float        AccelX;
	float        AccelY;
	int        Col_X;
	int        Col_Y;
	int        Col_Width;
	int        Col_Height;
protected:
	bool    CanJump;

public:
	bool     Jump();
public:
	Entity();
	Entity(int id, char* path,  int width, int  height);
	Entity(int id, int TypeID, char* File, int x, int y, SDL_Renderer* renderer, int Width, int Height, int MaxFrames);
	virtual ~Entity();
	virtual bool OnCollision(Entity* Entity);
	void OnAnimate();
	void    OnMove(float MoveX, float MoveY);
	virtual bool OnLoad(int id, char* File, int x, int y, SDL_Renderer* renderer, int width, int height, int MaxFrames);
	void     StopMove();
	void OnLoop();
public:
	bool    Collides(int oX, int oY, int oW, int oH);

private:
	bool     PosValid(int NewX, int NewY);

	bool     PosValidTile(Entity* Tile);

	bool     PosValidEntity(Entity* Entity, int NewX, int NewY);
};



class EntityCol {
public:
	static std::vector<EntityCol>    EntityColList;

public:
	Entity* EntityA;
	Entity* EntityB;

public:
	EntityCol();
};
#endif