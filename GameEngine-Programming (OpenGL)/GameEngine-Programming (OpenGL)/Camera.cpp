#include "Camera.h"

Camera::Camera(float _fov, float _near, float _far, float _aspectRatio) :
	fov(_fov), near(_near), far(_far), aspectRatio(_aspectRatio) {

	updateCameraMatrices();
}

Camera::~Camera() {

}

bool Camera::init() {

	return true;
}

void Camera::processInput() {

}

void Camera::update() {

}

void Camera::draw(Camera *_p_camera) {

}

void Camera::clean() {

}