#include "GameLoop.h"

GameLoop::GameLoop() {

}

GameLoop::~GameLoop() {

}

bool GameLoop::Init() {

	// Calling Init For SDL.
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL Could Not Be Initialized\n SDL ERROR: " << SDL_GetError() << std::endl;

		return false;
	}

	// Set SDL OpenGL Version and Core on Modern Features.
	glewExperimental = GL_TRUE;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Create a Window.
	p_window = SDL_CreateWindow("OpenGL Game", 50, 50, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	// Creating and Assigning OpenGL Context to the created Window.
	glContext = SDL_GL_CreateContext(p_window);
	if (glContext == nullptr) {
		std::cerr << "SDL Could Not Initialize GL Context:\n SDL ERROR: " << SDL_GetError() << std::endl;

		return false;
	}

	// Calling Init For GLEW.
	GLenum _glewStatus = glewInit();
	if (_glewStatus != GLEW_OK) {
		std::cerr << "GLEW Could Not Be Initialized\n GLEW ERROR: " << glewGetErrorString(_glewStatus) << std::endl;

		return false;
	}

	// Enable V-Sync.
	if (SDL_GL_SetSwapInterval(1) == -1) {
		std::cerr << "Unable to Enable SDL VSync\n SDL ERROR: " << SDL_GetError() << std::endl;

		return false;
	}

	p_camera = new Camera(45.0f, 0.1f, 100.0f, 640.0f / 480.0f);
	if (p_camera->init() != true) {
		std::cerr << "Camera Cannot be Initialized" << std::endl;
	}

	p_camera->setPosition(0, 0, 1);
	
	p_camera->lookAtPosition(0, 0, 0);

	p_triangle1 = new TriangleRenderer();
	if (p_triangle1->init() != true) {
		std::cerr << "Triangle Renderer could not be Initialized" << std::endl;
	}

	return true;
}

bool GameLoop::ProcessInput() {
	SDL_PumpEvents();

	SDL_Event _event;
	if (SDL_PeepEvents(&_event, 1, SDL_GETEVENT, SDL_QUIT, SDL_QUIT)) {
		return false;
	}

	return true;
}

void GameLoop::Update() {
	p_triangle1->update();
}

void GameLoop::Draw() {
	glClearColor(0.4f, 0.6f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	p_triangle1->draw(p_camera);

	SDL_GL_SwapWindow(p_window);
}

void GameLoop::Clean() {

	p_triangle1->clean();
	delete p_triangle1;

	p_camera->clean();
	delete p_camera;

	// ----- //
	SDL_GL_DeleteContext(glContext);
	glContext = nullptr;

	SDL_DestroyWindow(p_window);
	p_window = nullptr;

	SDL_Quit();
}