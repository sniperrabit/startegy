
#include "Camera.h"

//Kamera jest niepotrzebna je�li i tak sie renderuje wszystkopo przesuni�ciu.
//Renderowanie paru map obok nie ma sensu ?

Camera Camera::CameraControl;

Camera::Camera() {
	X = Y = 0;

	TargetX = TargetY = NULL;

	TargetMode = TARGET_MODE_NORMAL;
}

void Camera::OnMove(float MoveX, float MoveY) {
	X += MoveX;
	Y += MoveY;
}

int Camera::GetX() {
	if (TargetX != NULL) {
		if (TargetMode == TARGET_MODE_CENTER) {
			return *TargetX - (WWIDTH / 2);
		}

		return *TargetX;
	}

	return X;
}

int Camera::GetY() {
	if (TargetY != NULL) {
		if (TargetMode == TARGET_MODE_CENTER) {
			return *TargetY - (WHEIGHT / 2);
		}

		return *TargetY;
	}

	return Y;
}

void Camera::SetPos(float X, float Y) {
	this->X = X;
	this->Y = Y;
}

void Camera::SetTarget(float* X, float* Y) {
	TargetX = X;
	TargetY = Y;
}
