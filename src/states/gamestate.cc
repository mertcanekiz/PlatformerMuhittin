#include "gamestate.h"

#include "splash.h"
#include "menu.h"

GameState* GameState::splash = new Splash();
GameState* GameState::menu = new Menu();

GameState* GameState::getStateByID(int id)
{
	switch(id)
	{
		case SPLASH:
			return splash;
		case MENU:
			return menu;
	}

	std::cout << "Invalid GameState ID" << std::endl;
	return nullptr;
}

void GameState::cleanUp()
{
	delete splash;
	delete menu;
}
