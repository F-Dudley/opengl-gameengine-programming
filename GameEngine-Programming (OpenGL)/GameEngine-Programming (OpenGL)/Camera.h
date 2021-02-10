#pragma once

#include "GameObject.h"

class Camera : public GameObject{
public:
	

private:
	float fov;
	float near, far;
	float aspectRatio;

	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;

public:
	Camera(float _fov, float _near, float _far, float _aspectRatio);
	virtual ~Camera();

	bool init();

	void processInput();
	void update();
	void draw(Camera *_p_camera);

	void clean();

	glm::mat4 getViewMatrix() {
		return viewMatrix;
	}

	glm::mat4 getProjectionMatrix() {
		return projectionMatrix;
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

	void setRotation(float _x, float _y, float _z) override {
		GameObject::setRotation(_x, _y, _z);

		updateCameraMatrices();
	}

	void setRotationX(float _x) override {
		GameObject::setRotationX(_x);

		updateCameraMatrices();
	}

	void setRotationY(float _y) override {
		GameObject::setRotationY(_y);

		updateCameraMatrices();
	}

	void setRotationZ(float _z) override {
		GameObject::setRotationZ(_z);

		updateCameraMatrices();
	}

	void setScale(float _x, float _y, float _z) override {
		GameObject::setScale(_x, _y, _z);

		updateCameraMatrices();
	}

	void setScaleX(float _x) override {
		GameObject::setScaleX(_x);

		updateCameraMatrices();
	}

	void setScaleY(float _y) override {
		GameObject::setScaleY(_y);
		
		updateCameraMatrices();
	}

	void setScaleZ(float _z) override {
		GameObject::setScaleZ(_z);

		updateCameraMatrices();
	}

	void lookAtPosition(float _x, float _y, float _z) override {
		GameObject::lookAtPosition(_x, _y, _z);

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