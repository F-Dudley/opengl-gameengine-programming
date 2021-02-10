#pragma once

#include <iostream>
#include <GL\glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera;

class GameObject {
public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

protected:
	glm::mat4 transformationMatrix;

	GLuint transformUniformId;
	GLuint viewUniformId;
	GLuint projectionUniformId;

public:

	GameObject() {
		position.x = position.y = position.z = 0.0f;
		rotation.x = rotation.y = position.z = 0.0f;
		scale.x = scale.y = scale.z = 1.0f;


	}

	virtual ~GameObject() {

	}

	virtual bool init() = 0;

	virtual void processInput() = 0;
	virtual void update() = 0;
	virtual void draw(Camera* _p_camera) = 0;

	virtual void clean() = 0;

	glm::vec3 getPosition() {
		return position;
	}

	float getPositionX() {
		return position.x;
	}

	float getPositionY() {
		return position.y;
	}

	float getPositionZ() {
		return position.z;
	}

	glm::vec3 getRotation() {
		return rotation;
	}

	float getRotationX() {
		return rotation.x;
	}

	float getRotationY() {
		return rotation.y;
	}

	float getRotationZ() {
		return rotation.z;
	}

	glm::vec3 getScale() {
		return scale;
	}

	float getScaleX() {
		return scale.x;
	}

	float getScaleY() {
		return scale.y;
	}

	float getScaleZ() {
		return scale.z;
	}

	virtual void setPosition(float _x, float _y, float _z) {
		position.x = _x;
		position.y = _y;
		position.z = _z;
	}

	virtual void setPositionX(float _x) {
		position.x = _x;
	}

	virtual void setPositionY(float _y) {
		position.y = _y;
	}

	virtual void setPositionZ(float _z) {
		position.z = _z;
	}

	virtual void setRotation(float _x, float _y, float _z) {
		rotation.x = _x;
		rotation.y = _y;
		rotation.z = _z;
	}

	virtual void setRotationX(float _x) {
		rotation.x = _x;
	}

	virtual void setRotationY(float _y) {
		rotation.y = _y;
	}

	virtual void setRotationZ(float _z) {
		rotation.z = _z;
	}

	virtual void setScale(float _x, float _y, float _z) {
		scale.x = _x;
		scale.y = _y;
		scale.z = _z;
	}

	virtual void setScaleX(float _x) {
		scale.x = _x;
	}

	virtual void setScaleY(float _y) {
		scale.y = _y;
	}

	virtual void setScaleZ(float _z) {
		scale.z = _z;
	}

	virtual void lookAtPosition(float _x, float _y, float _z) {
		glm::lookAt(position, glm::vec3(_x, _y, _z), glm::vec3(0.0f, 1.0f, 0.0f));
	}

protected:


};