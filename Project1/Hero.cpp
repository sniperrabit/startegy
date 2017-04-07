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



bool Hero::OnLoad(int id, char* File, int x, int y, SDL_Renderer* renderer, int width, int height, int MaxFrames) {
	if (Entity::OnLoad( id,  File,  x,  y,  renderer, width,  height, MaxFrames) == false) {
		return false;
	}

	return true;
}

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
bool Hero::OnCollision(Entity* Entity) {
	Jump();
	return true;
}