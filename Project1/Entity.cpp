#include "Entity.h"
#include "Main.h"
#include <map>
#include <string>
#include <SDL_image.h>
using namespace std;


std::vector<Entity*>     Entity::EntityList;



Entity::Entity() {
	
	CanJump = false;
	TypeID = TILE_TYPE_NONE;
	textureEntity = NULL;
	surfaceEntity = NULL;
	id = NULL;
	point;
	Isox = Isoy = 0.0f;
	path = "";
	width = height = 0;
	AnimState = 0;

	
	MoveUp = false;
	MoveDown = false;
	MoveLeft = false;
	MoveRight = false;
	Type = ENTITY_TYPE_GENERIC;
	Dead = false;
	Flags = ENTITY_FLAG_GRAVITY;
	SpeedX = 0;
	SpeedY = 0;
	AccelX = 0;
	AccelY = 0;
	MaxSpeedX = 0.5;
	MaxSpeedY = 0.5;
	CurrentFrameCol = 0;
	CurrentFrameRow = 0;
	Col_X = SHAPE_SIZE;
	Col_Y = SHAPE_SIZE;
	Col_Width = 0.5;
	Col_Height = 0.5;
}

Entity::Entity(int id, char* path, int width, int  height) {
	this->textureEntity = NULL;
	this->surfaceEntity = NULL;
	this->id = id;
	this->point.x;
	this->point.y;
	this->path = path;

	this->width = width;
	this->height = height;

	this->AnimState = NULL;
}
Entity::~Entity() {
}


Entity::Entity(int id,int TypeID, char* File, int x, int y, SDL_Renderer* renderer, int width, int height, int MaxFrames) {
	this->TypeID = TypeID;
	this->surfaceEntity = IMG_Load(File);
	this->point.x = x;
	this->point.y = y;

	this->textureEntity = SDL_CreateTextureFromSurface(renderer, surfaceEntity);

	//	CSurface::Transparent(Surf_Hero, 255, 0, 255);

	this->width = width;
	this->height = height;

	Anim_Control.MaxFrames = MaxFrames;

}
bool Entity::Jump() {
	if (CanJump == false) return false;

	SpeedY = -MaxSpeedY;

	return true;
}
void Entity::OnLoop() {
	//We're not Moving
	if (MoveLeft == false && MoveRight == false && MoveUp == false && MoveDown == false) {
		StopMove();
	}

	if (MoveLeft) {
		AccelX = -0.05;
	}
	if (MoveRight) {
		AccelX = 0.05;
	}

	

	if (MoveUp) {
		AccelY = -0.05;
	}
	if (MoveDown) {
		AccelY = 0.05;
	}

//	if (Flags & ENTITY_FLAG_GRAVITY) {
//		AccelY = 0.75f;
//	}

	//SpeedX += AccelX * FPS::FPSControl.GetSpeedFactor();
	//SpeedY += AccelY * FPS::FPSControl.GetSpeedFactor();
	SpeedX += AccelX * 0.05;
	SpeedY += AccelY * 0.05;

	if (SpeedX > MaxSpeedX)  SpeedX = MaxSpeedX;
	if (SpeedX < -MaxSpeedX) SpeedX = -MaxSpeedX;
	if (SpeedY > MaxSpeedY)  SpeedY = MaxSpeedY;
	if (SpeedY < -MaxSpeedY) SpeedY = -MaxSpeedY;

	
	
	
	OnAnimate();
	OnMove(SpeedX, SpeedY);
}

void Entity::OnAnimate() {
	if (MoveLeft) {
		CurrentFrameCol = 0;
	}
	else

		if (MoveRight) {
			CurrentFrameCol = 1;
		}

	Anim_Control.OnAnimate();
}
bool Entity::OnCollision(Entity* Entity) {
	Jump();

	return true;
}
void Entity::OnMove(float MoveX, float MoveY) {
	CanJump = false;

	if (MoveX == 0 && MoveY == 0) {
		return;
	}
	double NewX = 0;
	double NewY = 0;

	//MoveX *= FPS::FPSControl.GetSpeedFactor();
	//MoveY *= FPS::FPSControl.GetSpeedFactor();
	MoveX *= 0.05f;
	MoveY *= 0.05f;

	if (MoveX != 0) {
		if (MoveX >= 0) {
		//	NewX = FPS::FPSControl.GetSpeedFactor();
			NewX = 0.1;
		}
		else {
		//	NewX = -FPS::FPSControl.GetSpeedFactor();
			NewX = -0.1;
		}
	}

	if (MoveY != 0) {
		if (MoveY >= 0) {
		//	NewY = FPS::FPSControl.GetSpeedFactor();
			NewY = 0.1;
		}
		else {
		//	NewY = -FPS::FPSControl.GetSpeedFactor();
			NewY = -0.1;
		}
	}

	while (true) {
		if (Flags & ENTITY_FLAG_GHOST) {
			//PosValid((int)(point.x + NewX), (int)(point.y + NewY)); //We don't care about collisions, but we need to send events to other entities

//			point.x += NewX;
//			point.y += NewY;
		}
		else {
			printf("Check PosValid FOR X\n");
			if (PosValid((int)(point.x + NewX+ 0.5), (int)(point.y + 0.9))) {  //+0.5 +0.9 set solid point on center on foot of shape 1x1
				if(point.x + NewX >=0)//end of map
				point.x += NewX;
			}
			else {
				SpeedX = 0;
			}
			printf("\nCheck PosValid FOR Y\n");
			if (PosValid((int)(point.x + 0.5 ), (int)(point.y + NewY + 0.9))) {
				if (point.y + NewY >= 0)//end of map
				point.y += NewY;
			}else{
				if (MoveY > 0) {
					CanJump = true;
				}
				SpeedY = 0;
			}
		}

		MoveX += -NewX;
		MoveY += -NewY;

		if (NewX > 0 && MoveX <= 0) NewX = 0;
		if (NewX < 0 && MoveX >= 0) NewX = 0;

		if (NewY > 0 && MoveY <= 0) NewY = 0;
		if (NewY < 0 && MoveY >= 0) NewY = 0;

		if (MoveX == 0) NewX = 0;
		if (MoveY == 0) NewY = 0;

		if (MoveX == 0 && MoveY == 0)     break;
		if (NewX == 0 && NewY == 0)     break;
	}
}
void Entity::StopMove() {
	if (SpeedX > 0) {
		AccelX = -0.1;
	}

	if (SpeedX < 0) {
		AccelX = 0.1;
	}

	if (SpeedX < 2.0f && SpeedX > -2.0f) {
		AccelX = 0;
		SpeedX = 0;
	}

	if (SpeedY > 0) {
		AccelY = -0.1;
	}

	if (SpeedY < 0) {
		AccelY = 0.1;
	}

	if (SpeedY < 2.0f && SpeedY > -2.0f) {
		AccelY = 0;
		SpeedY = 0;
	}

}
bool Entity::Collides(int oX, int oY, int oW, int oH) {
	int left1, left2;
	int right1, right2;
	int top1, top2;
	int bottom1, bottom2;

	int tX = (int)point.x + Col_X;
	int tY = (int)point.y + Col_Y;

	left1 = tX;
	left2 = oX;

	right1 = left1 + width - 1 - Col_Width;
	right2 = oX + oW - 1;

	top1 = tY;
	top2 = oY;

	bottom1 = top1 + height - 1 - Col_Height;
	bottom2 = oY + oH - 1;


	if (bottom1 < top2) return false;
	if (top1 > bottom2) return false;

	if (right1 < left2) return false;
	if (left1 > right2) return false;

	return true;
}
bool Entity::PosValid(int NewX, int NewY) {
	bool Return = true;
	printf("NewX= %d , NewY= %d \n", NewX, NewY);
	//Simple check tile in cordinates
	Entity* Tile = Area::AreaControl.GetTile(NewX * TILE_SIZE, NewY * TILE_SIZE);

	if (PosValidTile(Tile) == false) {
		Return = false;
		printf("block\n");
		printf("Hx=%f , Hy=%f \n", this->point.x, this->point.y);
		printf("x=%f , y=%f \n", Tile->point.x, Tile->point.y);
		printf("block\n\n");
		return  false;
	}
	else {
		printf("--free---\n");
		printf("Hx=%f , Hy=%f \n", this->point.x, this->point.y);
		printf("x=%f , y=%f \n", Tile->point.x, Tile->point.y);
		printf("--free---\n\n");
	}



//	int StartX = (NewX + Col_X) /SHAPE_SIZE;
//	int StartY = (NewY + Col_Y) / SHAPE_SIZE;
//	int StartX = NewX;
//	int StartY = NewY;
//	int StartX = NewX;
//	int StartY = NewY;
//	printf("StartX= %d , StartY= %d \n", StartX, StartY);
//	int EndX = 1;
//	int EndY = 0;

	//int EndX = ((NewX + 10) + 64 - 20 - 1) / TILE_SIZE;
	//int EndY = ((NewY + 10) + 64 - 20 - 1) / TILE_SIZE;
	//int EndX = ((NewX + 10) + width - Col_Width - 1) / SHAPE_SIZE;
	//int EndY = ((NewY + 10) + height - Col_Height - 1) / SHAPE_SIZE;
	//int EndX = ((NewX + Col_X) + SHAPE_SIZE - Col_Width - 1) / SHAPE_SIZE;
	//int EndY = ((NewY + Col_Y) + SHAPE_SIZE - Col_Height - 1) / SHAPE_SIZE;
	//int EndX = StartX + 1;
	//int EndY = StartY + 1;
/*
	for (int iY = StartY; iY <= EndY; iY++) {
		for (int iX = StartX; iX <= EndX; iX++) {
			Entity* Tile = Area::AreaControl.GetTile(iX * TILE_SIZE, iY * TILE_SIZE);

			if (PosValidTile(Tile) == false) {
				Return = false;
				printf("block\n");
				printf("Hx=%f , Hy=%f \n", this->point.x, this->point.y);
				printf("x=%f , y=%f \n", Tile->point.x, Tile->point.y);
				printf("block\n\n");
				return  false;
			}
			else {
				printf("--free---\n");
				printf("Hx=%f , Hy=%f \n", this->point.x, this->point.y);
				printf("x=%f , y=%f \n", Tile->point.x, Tile->point.y);
				printf("--free---\n\n");
			}
		}
	}


	if (Flags & ENTITY_FLAG_MAPONLY) {
	}
	else {
		for (int i = 0; i < EntityList.size(); i++) {
			if (PosValidEntity(EntityList[i], NewX, NewY) == false) {
				Return = false;
			}
		}
	}
*/
	return Return;
}
bool Entity::PosValidTile(Entity* Tile) {
	if (Tile == NULL) {
		return true;
	}

	if (Tile->TypeID == TILE_TYPE_BLOCK) {
		return false;
	}

	return true;
}
bool Entity::PosValidEntity(Entity* Entity, int NewX, int NewY) {
	if (this != Entity && Entity != NULL && Entity->Dead == false &&
		Entity->Flags ^ ENTITY_FLAG_MAPONLY &&
		Entity->Collides(NewX + Col_X, NewY + Col_Y, width - Col_Width - 1, height - Col_Height - 1) == true) {

		EntityCol EntityCol;

		EntityCol.EntityA = this;
		EntityCol.EntityB = Entity;

		EntityCol::EntityColList.push_back(EntityCol);

		return false;
	}

	return true;
}

bool Entity::OnLoad(int id, char* File, int x, int y, SDL_Renderer* renderer, int width, int height, int MaxFrames) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		return false;
	}
	this->surfaceEntity = IMG_Load(File);
	
	//	SDL_Surface*    Surf_Hero2;
	//	Surf_Hero2 = IMG_Load(File);
	this->point.x = x;
	this->point.y = y;

	this->textureEntity = SDL_CreateTextureFromSurface(renderer, surfaceEntity);

	//	CSurface::Transparent(Surf_Hero, 255, 0, 255);

	this->width = width;
	this->height = height;

	Anim_Control.MaxFrames = MaxFrames;

	return true;
}
