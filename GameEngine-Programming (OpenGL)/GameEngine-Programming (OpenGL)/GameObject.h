#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class GameObject abstract {
public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

protected:
	

public:

	GameObject() {
		std::cout << "Gameobject Constructor Called" << std::endl;

		position.x = position.y = position.z = 0.0f;
		rotation.x = rotation.y = position.z = 0.0f;
		scale.x = scale.y = scale.z = 1.0f;
	}

	virtual ~GameObject() {

	}

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

	virtual void lookAtPosition(glm::vec3 _targetPos) {

	}

protected:


};