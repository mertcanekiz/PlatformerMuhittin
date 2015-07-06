#include "menu.h"
#include "../application.h"

Menu::Menu()
{
	options.push_back(std::string("Start"));
	options.push_back(std::string("Help"));
	options.push_back(std::string("Exit"));
}

void Menu::init()
{

}

void Menu::input(SDL_Event event)
{
	if(event.type == SDL_KEYDOWN)
	{
		if(event.key.keysym.sym == SDLK_UP)
		{
			currentSelection--;
			if(currentSelection == -1)
				currentSelection = options.size() - 1;
		}
		if(event.key.keysym.sym == SDLK_DOWN)
		{
			currentSelection++;
			if(currentSelection == options.size())
				currentSelection = 0;
		}
		if(event.key.keysym.sym == SDLK_RETURN)
		{
			select();
		}
	}
}

void Menu::select()
{
	switch(currentSelection)
	{
		case 0:
			Application::getInstance().changeState(GameState::LEVEL1);
			break;
		case 1:
			//help
			break;
		case 2:
			Application::getInstance().stop();
			break;
	}
}

void Menu::update()
{

}

void Menu::render()
{
	SDL_Color color;
	for(int i = 0; i < options.size(); i++)
	{
		if(currentSelection == i)
			color = {0xff, 0x00, 0x00};
		else
			color = {0xff, 0xff, 0xff};
		Graphics::renderTexture(
			Graphics::createTextureFromText(options[i], Graphics::DEFAULTFONT, color),
			 300, 200 + i * 25);
	}
}
