#include "Camera.h"

Camera::Camera(float _fov, float _near, float _far, float _aspectRatio) :
	fov(_fov), near(_near), far(_far), aspectRatio(_aspectRatio) {
	std::cout << "Camera Constructor Called" << std::endl;

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

void Camera::draw() {

}

void Camera::clean() {

}