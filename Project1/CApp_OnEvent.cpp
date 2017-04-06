#include "Main.h"

void Main::OnEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
	if (Event->type == SDL_KEYDOWN) {
		switch (Event->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
			//Camera::CameraControl.OnMove(-1, -1);	//from isometric  to cartezjan	
			Hero3.MoveDown = true;
			Hero3.MoveUp = false;

			Hero3.point.y += 0.01;
			break;
		case SDL_SCANCODE_UP:
			//Camera::CameraControl.OnMove(1, 1);
			Hero3.MoveDown = false;
			Hero3.MoveUp = true;
			if (Hero3.point.y - 0.01 >= 0)
			Hero3.point.y -= 0.01;
			break;
		case SDL_SCANCODE_LEFT:
			Hero3.MoveLeft = true;
			Hero3.MoveRight = false;

			if (Hero3.point.x - 0.01 >= 0)
			Hero3.point.x -= 0.01;//lenghtOfStep
			//Camera::CameraControl.OnMove(1, -1);
			break;
		case SDL_SCANCODE_RIGHT:
			Hero3.MoveLeft = false;
			Hero3.MoveRight = true;
			//Camera::CameraControl.OnMove(-1, 1);
			Hero3.point.x += 0.01;
			break;
		case SDLK_SPACE: 
			Hero3.Jump();
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
			Hero3.MoveDown = false;
			Hero3.MoveUp = false;
			break;
		case SDL_SCANCODE_UP:
			Hero3.MoveDown = false;
			Hero3.MoveUp = false;
			break;
		case SDL_SCANCODE_LEFT:
			Hero3.MoveLeft = false;
			Hero3.MoveRight = false;

			break;
		case SDL_SCANCODE_RIGHT:
			Hero3.MoveLeft = false;
			Hero3.MoveRight = false;

			break;
		case SDLK_ESCAPE:

			break;
		default:
			break;
		}
	}
}
