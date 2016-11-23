#include "Main.h"

void Main::OnEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
	if (Event->type == SDL_KEYDOWN) {
		switch (Event->key.keysym.scancode) {
		case SDL_SCANCODE_DOWN:
			//Entity hero
			//hero facing =down
			//hero y-1
			//hero render
			//	window present
			Hero1.Cpoint.y += 1;

			break;
		case SDL_SCANCODE_UP:
			Hero1.Cpoint.y -= 1;
			break;
		case SDL_SCANCODE_LEFT:
			Hero1.Cpoint.x -= 1;
			break;
		case SDL_SCANCODE_RIGHT:
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