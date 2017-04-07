#ifndef _FPS_H_
#define _FPS_H_

#include <SDL.h>

class FPS {
private:
	int     OldTime;
	int     LastTime;
	float	SpeedFactor;
	int		NumFrames;
	int     Frames;

public:
	static FPS FPSControl;
	FPS();
	void    OnLoop();
	int     GetFPS();
	float   GetSpeedFactor();
};

#endif
