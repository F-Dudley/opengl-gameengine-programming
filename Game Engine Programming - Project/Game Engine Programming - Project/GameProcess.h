#pragma once

class GameProcess abstract{
public:

	virtual bool Init() = 0;
	virtual bool ProcessInput() = 0;
	
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual void Clean() = 0;
};