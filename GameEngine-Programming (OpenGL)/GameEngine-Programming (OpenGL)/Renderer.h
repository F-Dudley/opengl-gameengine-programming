#pragma once

#include <vector>

class Renderer {
public:

protected:
	struct Vertex {
		float x, y, z;

		Vertex(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }
		Vertex() {
			x = y = z = 0.0f;
		}
		
	};
	std::vector<Vertex> shapeVerticies;

public:


protected:

	
};