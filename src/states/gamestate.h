#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>

#include "../graphics.h"

class GameState
{

public:
	virtual ~GameState() {}

	static const int SPLASH = 0x00;
	static const int MENU   = 0x01;
	static const int LEVEL1 = 0x02;

	static GameState* splash;
	static GameState* menu;
	static GameState* level1;

	static GameState* getStateByID(int);
	static void cleanUp();

	virtual void init() = 0;
	virtual void input(SDL_Event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;

};

#endif
