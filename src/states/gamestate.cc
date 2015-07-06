#include "gamestate.h"

#include "splash.h"
#include "menu.h"
#include "level1.h"

GameState* GameState::splash = new Splash();
GameState* GameState::menu = new Menu();
GameState* GameState::level1 = new Level1();

GameState* GameState::getStateByID(int id)
{
	switch(id)
	{
		case SPLASH:
			return splash;
		case MENU:
			return menu;
		case LEVEL1:
			return level1;
	}

	std::cout << "Invalid GameState ID" << std::endl;
	return nullptr;
}

void GameState::cleanUp()
{
	delete splash;
	delete menu;
}
