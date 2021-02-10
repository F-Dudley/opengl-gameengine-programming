#pragma once

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

class MeshRenderer {
public:

private:
	GLuint programID;


public:
	MeshRenderer();
	virtual ~MeshRenderer();

	bool init();
	
	void processInput();
	void update();
	void draw();

	void clean();

private:

};