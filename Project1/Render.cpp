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

//	CSurface::OnDraw(renderer, Hero3, Hero3.point, 0, Hero3.Anim_Control.GetCurrentFrame() * 64, 64, 64);
	/*
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
				// CSurface::OnDraw(Surf_Display, Surf_Entity, X - CCamera::CameraControl.GetX(), Y - CCamera::CameraControl.GetY(), CurrentFrameCol * Width, (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height, Width, Height);
				CSurface::OnDraw(renderer, Hero1, X - CCamera::CameraControl.GetX(), Y - CCamera::CameraControl.GetY(), CurrentFrameCol * Width, (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height, Width, Height);
				CSurface::OnDraw(renderer, Hero1, Hero1.Cpoint, 0, Hero1.Anim_Control.GetCurrentFrame() * 64, 64, 64);
			
			}						
			k++;
		}
	}
	k = 0;
	*/
	SDL_DestroyTexture(texture);

	SDL_RenderPresent(renderer);
	
}
