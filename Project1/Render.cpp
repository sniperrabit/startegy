#include "Main.h"

void Main::renderMap(SDL_Renderer *renderer,SDL_Texture *tex, Point* p, int size, int w, int h) {
	//parameters in with offset point( x+LEVEL_WIDTH ; y-LEVEL_HEIGHT)

	Point tmp;	
	 tmp = p->twoDToIso(p);
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;

	if (h>1) {//for bigger buildings	
		tmp.y = tmp.y - h/2;
		tmp.x = tmp.x - w/2;
		dst.x = tmp.x*size;
		dst.y = (tmp.y *size);// -((h*size) - size);

		dst.w = w*size * 2;
		dst.h = h*size;
		SDL_RenderCopy(renderer, tex, NULL, &dst);
		//SDL_RenderPresent(ren);
	}
	else {
		dst.x = tmp.x*size;
		dst.y = (tmp.y *size) - ((h*size) - size);

		dst.w = w*size * 2;
		dst.h = h*size;
		SDL_RenderCopy(renderer, tex, NULL, &dst);
		//SDL_RenderPresent(ren);
	}
	

}

void Main::renderEntity(SDL_Renderer* renderer, Entity entity, Point *p, int X2, int Y2, int W, int H) {
	Point tmp = p->twoDToIso(p);
	/*
	SDL_Rect dst;
	dst.x = tmp.x*SHAPE_SIZE; //+(LEVEL_WIDTH*SHAPE_SIZE);
	dst.y = tmp.y * SHAPE_SIZE; //+(LEVEL_WIDTH*SHAPE_SIZE);
	dst.w = SHAPE_SIZE * 2 ;
	dst.h = SHAPE_SIZE ;
	*/

	SDL_Rect dst;
	dst.x = tmp.x*SHAPE_SIZE;
	dst.y = (tmp.y *SHAPE_SIZE) - ((H*SHAPE_SIZE) - SHAPE_SIZE);
	dst.w = W*SHAPE_SIZE * 2;
	dst.h = H*SHAPE_SIZE;

	SDL_Rect SrcR;
	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W*SHAPE_SIZE;
	SrcR.h = H*SHAPE_SIZE;

	//	SDL_FreeSurface(Surf_Temp);
	//	SDL_UpdateTexture(hero.textureEntity, NULL, hero.surfaceEntity->pixels, hero.surfaceEntity->pitch);
	SDL_RenderCopy(renderer, entity.textureEntity, &SrcR, &dst);
	//SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);	
}

void Main::render(SDL_Renderer *renderer,int size) {
	
	SDL_RenderClear(renderer);
	//Render ground
	
	Area::AreaControl.OnRender(renderer, Area::AreaControl.MapList, Camera::CameraControl.GetX(), Camera::CameraControl.GetY());

	Entity hero;
	hero = Area::AreaControl.EntityList.front();
	hero.point.x -= Camera::CameraControl.GetX();
	hero.point.y -= Camera::CameraControl.GetY();

	
	int MapWidth = LEVEL_WIDTH * TILE_SIZE;//6x16
	int MapHeight = LEVEL_HEIGHT * TILE_SIZE;//6x16
	int idMapHero = (hero.point.x+0.5) /( LEVEL_WIDTH);
	idMapHero = idMapHero + ((int)((hero.point.y + 0.9) / (LEVEL_HEIGHT)) * 3);//x3


	Area::AreaControl.OnRender(renderer, Area::AreaControl.BuildingMapList, Camera::CameraControl.GetX(), Camera::CameraControl.GetY(), hero, idMapHero);

//	Hero3.point.x -= Camera::CameraControl.GetX();
//	Hero3.point.y -= Camera::CameraControl.GetY();
//	Point* p = new Point(Hero3.point.x+LEVEL_WIDTH, Hero3.point.y - LEVEL_HEIGHT);//OFFSET
//	CSurface::OnDraw(renderer, Hero3, *p, Hero3.CurrentFrameCol * 64,
//		(Hero3.CurrentFrameRow + Hero3.Anim_Control.GetCurrentFrame()) * 64, 1, 1);

	//Area::AreaControl.BuildingMapList.addToMap(Hero3);

//	delete p;

	SDL_RenderPresent(renderer);	
}
