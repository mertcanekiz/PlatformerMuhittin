#include "menu.h"
#include "../application.h"

Menu::Menu()
: buttons{
	Button("start", (Application::SCREEN_WIDTH - Button::WIDTH) / 2, 250),
	Button("help", (Application::SCREEN_WIDTH - Button::WIDTH) / 2, 275),
	Button("exit", (Application::SCREEN_WIDTH - Button::WIDTH) / 2, 300)
}

{
	menubg = nullptr;
}

void Menu::init()
{
	if(menubg == nullptr)
		menubg = Graphics::loadTexture("res/menu/menubg.png");
	for(Button &b : buttons)
		b.loadImages();
	buttons[0].selected = true;
}

void Menu::input(SDL_Event event)
{
	if(event.type == SDL_KEYDOWN)
	{
		if(event.key.keysym.sym == SDLK_UP)
		{
			buttons[currentSelection].selected = false;
			currentSelection--;
			if(currentSelection == -1)
				currentSelection = NUM_BUTTONS - 1;
			buttons[currentSelection].selected = true;
		}
		if(event.key.keysym.sym == SDLK_DOWN)
		{
			buttons[currentSelection].selected = false;
			currentSelection++;
			if(currentSelection == NUM_BUTTONS)
				currentSelection = 0;
			buttons[currentSelection].selected = true;
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
	Graphics::renderTexture(menubg, 0, 0);
	for(Button &b : buttons)
		b.render();
}
