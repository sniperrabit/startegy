#include "Main.h"

void Main::OnEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
	if (Event->type == SDL_KEYDOWN) {
		switch (Event->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
			Camera::CameraControl.OnMove(0, -1);			
			Hero1.Cpoint.y += 1;
			break;
		case SDL_SCANCODE_UP:
			Camera::CameraControl.OnMove(0, 1);
			Hero1.Cpoint.y -= 1;
			break;
		case SDL_SCANCODE_LEFT:
			Hero1.Cpoint.x -= 1;
			Camera::CameraControl.OnMove(1, 0);
			break;
		case SDL_SCANCODE_RIGHT:
			Camera::CameraControl.OnMove(-1, 0);
			Hero1.Cpoint.x += 1;
			break;
		case SDLK_ESCAPE:
			Running = false;
			break;
		default:
			break;
		}
	}
}
