#include "Main.h"

void Main::renderGround(SDL_Texture *tex, SDL_Renderer *ren, Point* p, int size, int w, int h) {
	Point tmp = p->twoDToIso(p);
	//Point tmp = *p;
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;

	dst.x = tmp.x*size;
	dst.y = (tmp.y *size);

	dst.w = w*size * 2;
	dst.h = h*size;
	SDL_RenderCopy(ren, tex, NULL, &dst);
	//SDL_RenderPresent(ren);

}
void Main::renderItem(SDL_Texture *tex, SDL_Renderer *ren, Point* p, int size, int w, int h) {
	Point tmp=p->twoDToIso(p);
	//Point tmp = *p;
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;	
	
	dst.x = tmp.x*size;
	dst.y = (tmp.y *size) - ((h*size)-size);
	
	dst.w = w*size*2;
	dst.h = h*size;
	SDL_RenderCopy(ren, tex, NULL, &dst);
	//SDL_RenderPresent(ren);

}
void Main::render(SDL_Renderer *renderer,int size) {
	
	SDL_RenderClear(renderer);
	//Render ground
	SDL_Texture* texture=NULL;
	
	int k = 0;
	for (int i = 0; i < LEVEL_WIDTH; i++) {
		for (int j = 0; j < LEVEL_HEIGHT; j++) {
			if (levelGround[i][j] != 0) {


				//Render ground
			//	texture = Main::prepareRenderItems(renderer, levelGround[i][j], EntityMap);
				Main::renderGround(EntityMap[levelGround[i][j]].textureEntity, renderer, &levelPoints[k], SHAPE_SIZE, EntityMap[levelGround[i][j]].width, EntityMap[levelGround[i][j]].height);

				//Render items
				if (levelItems[i][j] != 0) {
				//	texture = Main::prepareRenderItems(renderer, levelItems[i][j], EntityMap);
					Main::renderItem(EntityMap[levelItems[i][j]].textureEntity, renderer, &levelPoints[k], SHAPE_SIZE, EntityMap[levelItems[i][j]].width, EntityMap[levelItems[i][j]].height);
				}

				//render Hero
				CSurface::OnDraw(renderer, Hero1, Hero1.Cpoint, 0, Hero1.Anim_Control.GetCurrentFrame() * 64, 64, 64);
			}						
			k++;
		}
	}
	k = 0;
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(renderer);
	
}
