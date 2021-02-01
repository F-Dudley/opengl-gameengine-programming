#include <iostream>

#include "GameLoop.h"

GameLoop* gameLoop;

int main()
{
	gameLoop = new GameLoop();
	if (!gameLoop->init()) {
		std::cout << "GameEngine Failed to Initialized" << std::endl;

		return 1;
	}
	
	while (gameLoop->processInput()) {
		
		gameLoop->update();
		gameLoop->draw();
	}

	return 0;
}
