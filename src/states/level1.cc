#include "level1.h"

Level1::Level1()
{
	player = new Player(vec2(100, 100));
}

void Level1::init()
{
	player->setPosition(vec2(100, 100));
	player->setVelocity(vec2(0, 0));
}

void Level1::input(SDL_Event event)
{

}

void Level1::update()
{
	player->update();
}

void Level1::render()
{
	player->render();
}
