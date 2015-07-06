#ifndef MENU_H
#define MENU_H

#include "gamestate.h"

class Menu : public GameState
{

public:
	Menu();
	virtual ~Menu() {};

	void init();
	void input(SDL_Event);
	void update();
	void render();

private:
	SDL_Texture* menubg;

};

#endif
