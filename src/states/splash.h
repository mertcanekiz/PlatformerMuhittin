#ifndef SPLASH_H
#define SPLASH_H

#include "gamestate.h"

class Splash : public GameState
{

public:
	Splash();
	virtual ~Splash() {}

	static const int SPLASH_TIME = 2000;

	void init();
	void input(SDL_Event);
	void update();
	void render();

private:
	SDL_Texture* splashImage;
	int timer;

};

#endif
