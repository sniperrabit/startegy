#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <SDL.h>
#include "Define.h"

enum {
	TARGET_MODE_NORMAL = 0,
	TARGET_MODE_CENTER
};

class Camera {
private:
	int X;
	int Y;
	float* TargetX;
	float* TargetY;

public:
	float TargetMode;
	static Camera CameraControl;

	Camera();
	int GetX();
	int GetY();
	void SetPos(float X, float Y);
	void SetTarget(float* X, float* Y);
	void OnMove(float MoveX, float MoveY);
};

#endif