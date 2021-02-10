#pragma once

#include <iostream>

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

#include "TriangleRenderer.h"

const class GameLoop {
public:

private:
	SDL_Window *p_window;
	SDL_GLContext glContext;

	TriangleRenderer *p_triangle1;

public:
	
	GameLoop();
	virtual ~GameLoop();

	bool Init();
	bool ProcessInput();

	void Update();
	void Draw();

	void Clean();

private:
	
};