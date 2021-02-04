#pragma once

const class GameProcess {
public:

private:

public:
	virtual bool init() = 0;

	virtual void processInput() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	virtual void clean() = 0;

private:

};