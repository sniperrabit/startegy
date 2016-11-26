#include "Entity.h"
#include <map>
#include <string>
#include <SDL_image.h>
using namespace std;


Entity::Entity() {
	

	TypeID = TILE_TYPE_NONE;
	textureEntity = NULL;
	surfaceEntity = NULL;
	id = NULL;
	Cpoint;
	Isox = Isoy = 0.0f;
	path = "";

	width = height = 0;

	AnimState = 0;
}

Entity::Entity(int id, char* path, int width, int  height) {
	this->textureEntity = NULL;
	this->surfaceEntity = NULL;
	this->id = id;
	this->Cpoint.x;
	this->Cpoint.y;
	this->path = path;

	this->width = width;
	this->height = height;

	this->AnimState = NULL;
}
Entity::~Entity() {
}


Entity::Entity(int id, char* File, int x, int y, SDL_Renderer* renderer, int width, int height, int MaxFrames) {
	
	this->surfaceEntity = IMG_Load(File);
	this->Cpoint.x = x;
	this->Cpoint.y = y;

	this->textureEntity = SDL_CreateTextureFromSurface(renderer, surfaceEntity);

	//	CSurface::Transparent(Surf_Hero, 255, 0, 255);

	this->width = width;
	this->height = height;

	Anim_Control.MaxFrames = MaxFrames;

}
/*
void Entity::OnLoop() {
	Anim_Control.OnAnimate();
}


void Entity::OnCleanup() {
	if (Surf_Entity) {
		SDL_FreeSurface(Surf_Entity);
	}

	Surf_Entity = NULL;
	
}
*/