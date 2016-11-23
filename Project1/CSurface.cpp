#include "CSurface.h"
#include <SDL_image.h>
CSurface::CSurface() {
}

/*bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
	if (Surf_Dest == NULL || Surf_Src == NULL) {
		return false;
	}

	SDL_Rect DestR;
	DestR.x = X;
	DestR.y = Y;
	SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

	return true;
}
*/
bool CSurface::OnDraw(SDL_Renderer* renderer, Hero hero, Point &p, int X2, int Y2, int W, int H) {
	Point tmp = p.twoDToIso(&p);

	SDL_Rect dst;
	dst.x = tmp.x*SHAPE_SIZE;
	dst.y = tmp.y * SHAPE_SIZE;
	dst.w = SHAPE_SIZE * 2;
	dst.h = SHAPE_SIZE;
	
	SDL_Rect SrcR;
	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W;
	SrcR.h = H;

//	SDL_FreeSurface(Surf_Temp);
	SDL_UpdateTexture(hero.Texture_Hero, NULL, hero.Surf_Hero->pixels, hero.Surf_Hero->pitch);
	SDL_RenderCopy(renderer, hero.Texture_Hero, &SrcR, &dst);	
	//SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);

	return true;
}



bool CSurface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
	if (Surf_Dest == NULL) {
		return false;
	}

	SDL_SetColorKey(Surf_Dest, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));

	return true;
}