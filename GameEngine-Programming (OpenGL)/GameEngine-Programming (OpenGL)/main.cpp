#pragma once
#define SDL_MAIN_HANDLED

#include <iostream>
#include "GameLoop.h"

GameLoop* gameloop;

int main()
{
    gameloop = new GameLoop();

	if (!gameloop->Init()) {
		std::cerr << "\nGameLoop Failed to Initialize." << std::endl;

		return -1;
	}

	while (gameloop->ProcessInput()) {
		gameloop->Update();
		gameloop->Draw();
	}

	gameloop->Clean();

    return 0;
}
