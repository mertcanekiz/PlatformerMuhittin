#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <vector>
#include "gamestate.h"

#define NUM_BUTTONS 3

class Button
{

public:
	Button(std::string name, int x, int y) : name(name), x(x), y(y) { selected = false;}
	void render() { Graphics::renderTexture(selected ? image1 : image0, x, y);}
	void loadImages() { image0 = Graphics::loadTexture("res/menu/buttons/" + name + "0.png");
						image1 = Graphics::loadTexture("res/menu/buttons/" + name + "1.png");}

	static const int WIDTH = 45;
	bool selected;

private:
	std::string name;
	int x, y;
	SDL_Texture *image0, *image1;
};

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
	Button buttons[NUM_BUTTONS];
	int currentSelection;

	void select();

};



#endif
