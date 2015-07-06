#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <SDL2/SDL.h>

#include "graphics.h"
#include "states/gamestate.h"

class Application
{

public:
	static Application& getInstance()
	{
		static Application instance;
		return instance;
	}

	int execute();
	void changeState(int);
	void stop();

	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;

	inline SDL_Renderer* getRenderer() const { return renderer; }

private:
	Application() {}
	bool initialize();
	void input(SDL_Event);
	void update();
	void render();
	void cleanUp();

	SDL_Window *window;
	SDL_Renderer *renderer;
	bool running;

	GameState* currentState;

	Application(const Application&);
	void operator=(const Application&);
};

#endif
