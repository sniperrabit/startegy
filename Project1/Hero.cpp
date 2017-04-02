#include "Hero.h"

#include <map>
#include <string>
#include <SDL_image.h>

using namespace std;



Hero::Hero() {
/*	Texture_Hero= NULL;
	Surf_Hero = NULL;
	id = NULL;
	Cpoint;
	Isox = Isoy = 0.0f;
	path = "";
	char* facing = NULL;
	width = height = 0;
	MaxFrames = 1;
	AnimState = 0; */
}
/*
Hero::Hero(int id, char* path, CSurface SurSurf_Hero, float x, float y, int AnimState, int width, int  height) {
	this->Surf_Hero = Surf_Hero;
	this->id = id;
	this->x = x;
	this->y = y;
	this->path = path;

	this->width = width;
	this->height = height;

	this->AnimState = AnimState;
}	*/
/*
Hero::Hero(int id, char* path, int x, int y, int width, int  height) {
	this->Surf_Hero = NULL;
	this->id = id;
	this->Cpoint.x= x;
	this->Cpoint.y = y;
	this->path = path;

	this->width = width;
	this->height = height;

	this->AnimState = NULL;
	
}*/

bool Hero::OnLoad(int id, char* File, int x, int y, SDL_Renderer* renderer, int width, int height, int MaxFrames) {
	if (Entity::OnLoad( id,  File,  x,  y,  renderer, width,  height, MaxFrames) == false) {
		return false;
	}

	return true;
}
/*
bool Hero::OnLoad(int id ,char* File,int x ,int y, SDL_Renderer* renderer, int width, int height, int MaxFrames) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		return false;
	}
	this->Surf_Hero = IMG_Load(File);
//	SDL_Surface*    Surf_Hero2;
//	Surf_Hero2 = IMG_Load(File);
	this->Cpoint.x = x;
	this->Cpoint.y = y;

	this->Texture_Hero= SDL_CreateTextureFromSurface(renderer, Surf_Hero);

//	CSurface::Transparent(Surf_Hero, 255, 0, 255);

	this->width = width;
	this->height = height;

	Anim_Control.MaxFrames = MaxFrames;

	return true;
}
*/
void Hero::OnLoop() {
	Entity::OnLoop();
	//Anim_Control.OnAnimate();
}

void Hero::OnAnimate() {
	if (SpeedX != 0) {
		Anim_Control.MaxFrames = 8;
	}
	else {
		Anim_Control.MaxFrames = 0;
	}

	Entity::OnAnimate();
}
void Hero::OnCollision(Entity* Entity) {
}