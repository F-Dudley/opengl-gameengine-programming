#pragma once

#include "GameObject.h"

class Camera : public GameObject{
public:
	

private:
	float fov;
	float near, far;
	float aspectRatio;

	glm::mat4 projectionMatrix;
	glm::mat4 viewMat;

public:
	Camera(float _fov, float _near, float _far, float _aspectRatio);
	virtual ~Camera();

	bool init();

	void processInput();
	void update();
	void draw();

	void clean();

	glm::mat4 getViewMatrix() {

	}

	glm::mat4 getProjectionMatrix() {

	}

	void setPosition(float _x, float _y, float _z) override {
		GameObject::setPosition(_x, _y, _z);

		updateCameraMatrices();
	}

	void setPositionX(float _x) override {
		GameObject::setPositionX(_x);

		updateCameraMatrices();
	}

	void setPositionY(float _y) override {
		GameObject::setPositionZ(_y);

		updateCameraMatrices();
	}

	void setPositionZ(float _z) override {
		GameObject::setPositionZ(_z);

		updateCameraMatrices();
	}

	void lookAtPosition(glm::vec3 _targetPos) override {
		GameObject::lookAtPosition(_targetPos);

		updateCameraMatrices();
	}

	void setFov(float _fov) {
		fov = _fov;

		updateCameraMatrices();
	}

	void setNearClip(float _near) {
		near = _near;

		updateCameraMatrices();
	}

	void setFarClip(float _far) {
		far = _far;

		updateCameraMatrices();
	}

	void setAspectRatio(float _aspectRatio) {
		aspectRatio = _aspectRatio;

		updateCameraMatrices();
	}

private:
	void updateCameraMatrices() {
		projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, near, far);
	}
};