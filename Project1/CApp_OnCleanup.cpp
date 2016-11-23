#include "Main.h"

void Main::OnCleanup() {
	SDL_FreeSurface(Surf_Test);
	SDL_FreeSurface(Surf_Display);
	SDL_Quit();
}