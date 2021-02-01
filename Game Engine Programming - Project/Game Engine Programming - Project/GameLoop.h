#pragma once

#include <SDL.h>

const class GameLoop {

	// Variables
public:


private:
	SDL_Window* window;

	SDL_GLContext glContent;

	// Functions
public:
	GameLoop();
	virtual ~GameLoop();


	bool init();
	bool processInput();

	void update();
	void draw();

	void clean();

private:

};