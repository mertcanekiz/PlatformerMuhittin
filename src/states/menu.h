#ifndef MENU_H
#define MENU_H

#include <vector>
#include "gamestate.h"

class Menu : public GameState
{

public:
	Menu();
	virtual ~Menu() {}

	void init();
	void input(SDL_Event);
	void update();
	void render();

private:
	SDL_Texture* menubg;
	std::vector<std::string> options;
	int currentSelection;
	void select();

};

#endif
