#include "Main.h"

void Main::renderMap(SDL_Renderer *renderer,SDL_Texture *tex, Point* p, int size, int w, int h) {
	//parameters in with offset point( x+LEVEL_WIDTH ; y-LEVEL_HEIGHT)

	Point tmp;
	 tmp = p->twoDToIso(p);
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;

	dst.x = tmp.x*size;
	dst.y = (tmp.y *size) - ((h*size) - size);

	dst.w = w*size * 2;
	dst.h = h*size;
	SDL_RenderCopy(renderer, tex, NULL, &dst);
	//SDL_RenderPresent(ren);

}
void Main::render(SDL_Renderer *renderer,int size) {
	
	SDL_RenderClear(renderer);
	//Render ground
	SDL_Texture* texture=NULL;

	Area::AreaControl.OnRender(renderer, Area::AreaControl.MapList, Camera::CameraControl.GetX(), Camera::CameraControl.GetY());
	Area::AreaControl.OnRender(renderer, Area::AreaControl.BuildingMapList, Camera::CameraControl.GetX(), Camera::CameraControl.GetY());

	Hero3.point.x -= Camera::CameraControl.GetX();
	Hero3.point.y -= Camera::CameraControl.GetY();
	Point* p = new Point(Hero3.point.x+LEVEL_WIDTH, Hero3.point.y - LEVEL_HEIGHT);//OFFSET

	CSurface::OnDraw(renderer, Hero3, *p, Hero3.CurrentFrameCol * 64,
		(Hero3.CurrentFrameRow + Hero3.Anim_Control.GetCurrentFrame()) * 64, 1, 1);

	SDL_DestroyTexture(texture);
	SDL_RenderPresent(renderer);	
}
