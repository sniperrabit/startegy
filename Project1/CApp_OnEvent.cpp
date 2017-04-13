#include "Main.h"

void Main::OnEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		Running = false;
	}

	Entity * heroPtr;
	heroPtr = &Area::AreaControl.EntityList.front();


	if (Event->type == SDL_KEYDOWN) {
		switch (Event->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
			//Camera::CameraControl.OnMove(-1, -1);	//from isometric  to cartezjan	
			heroPtr->MoveDown = true;
			heroPtr->MoveUp = false;

			heroPtr->point.y += 0.01;
			break;
		case SDL_SCANCODE_UP:
			//Camera::CameraControl.OnMove(1, 1);
			heroPtr->MoveDown = false;
			heroPtr->MoveUp = true;
			if (heroPtr->point.y - 0.01 >= 0)
				heroPtr->point.y -= 0.01;
			break;
		case SDL_SCANCODE_LEFT:
			heroPtr->MoveLeft = true;
			heroPtr->MoveRight = false;

			if (heroPtr->point.x - 0.01 >= 0)
				heroPtr->point.x -= 0.01;//lenghtOfStep
			//Camera::CameraControl.OnMove(1, -1);
			break;
		case SDL_SCANCODE_RIGHT:
			heroPtr->MoveLeft = false;
			heroPtr->MoveRight = true;
			//Camera::CameraControl.OnMove(-1, 1);
			heroPtr->point.x += 0.01;
			break;
		case SDLK_SPACE: 
			heroPtr->Jump();
			break;
		
		case SDLK_ESCAPE:
			Running = false;
			break;
		default:
			break;
		}
	}
	if (Event->type == SDL_KEYUP) {
		switch (Event->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
			heroPtr->MoveDown = false;
			heroPtr->MoveUp = false;
			break;
		case SDL_SCANCODE_UP:
			heroPtr->MoveDown = false;
			heroPtr->MoveUp = false;
			break;
		case SDL_SCANCODE_LEFT:
			heroPtr->MoveLeft = false;
			heroPtr->MoveRight = false;

			break;
		case SDL_SCANCODE_RIGHT:
			heroPtr->MoveLeft = false;
			heroPtr->MoveRight = false;

			break;
		case SDLK_ESCAPE:

			break;
		default:
			break;
		}
	}
}
