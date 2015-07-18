#include "level1.h"
#include "../application.h"
#include "../game/tile.h"

Level1::Level1() : tilemap("res/maps/level1.map", "res/spritesheet.png"), player(vec2(100,100))
{

}

void Level1::init()
{
	if(bg == nullptr)
		bg = Graphics::loadTexture("res/level/level1bg.png");
	player.setPosition(vec2(100, 100));
	player.setVelocity(vec2(0, 0));
	tilemap.init();
}

void Level1::input(SDL_Event event)
{
	if(event.type == SDL_KEYDOWN)
	{
		if(event.key.keysym.sym == SDLK_ESCAPE)
			Application::getInstance().changeState(GameState::MENU);
	}
	player.input(event);
}

void Level1::update()
{
	player.setTouchingGround(false);
	for(unsigned int i = 0; i < 300; i++)
	{
		Tile tile = tilemap.getTile(i);
		if(player.getPosition().y + player.getSize().y + player.getVelocity().y>= tile.getPosition().y 
			&& player.getPosition().y + player.getSize().y + player.getVelocity().y - 12 < tile.getPosition().y 
			&& player.getPosition().x + player.getSize().x - 4 > tile.getPosition().x 
			&& player.getPosition().x + 4 < tile.getPosition().x + Tile::TILE_SIZE 
			&& player.getAcceleration().y > 0 
			&& tile.getType() != 0)
		{
			player.setPosition(vec2(player.getPosition().x, player.getPosition().y + (tile.getPosition().y - player.getPosition().y - player.getSize().y)));
			player.setVelocity(vec2(player.getVelocity().x, 0));
			player.setTouchingGround(true);
		}

		if(tile.getType() != 0 
			&& player.getPosition().x + player.getSize().x >= tile.getPosition().x
			&& player.getPosition().x < tile.getPosition().x
			&& player.getPosition().y + 10 >= tile.getPosition().y
			&& player.getPosition().y + 14 <= tile.getPosition().y + Tile::TILE_SIZE)
		{
			player.setPosition(vec2(player.getPosition().x + (tile.getPosition().x - player.getPosition().x - player.getSize().x), player.getPosition().y));
			player.setVelocity(vec2(0, player.getVelocity().y));
			player.setTouchingGround(player.getDirection(0));
		}

		if(tile.getType() != 0 
			&& player.getPosition().x < tile.getPosition().x + Tile::TILE_SIZE
			&& player.getPosition().x + player.getSize().x >= tile.getPosition().x + Tile::TILE_SIZE
			&& player.getPosition().y + 10 >= tile.getPosition().y
			&& player.getPosition().y + 14 <= tile.getPosition().y + Tile::TILE_SIZE)
		{
			player.setPosition(vec2(player.getPosition().x + (tile.getPosition().x + Tile::TILE_SIZE - player.getPosition().x), player.getPosition().y));
			player.setVelocity(vec2(0, player.getVelocity().y));
			player.setTouchingGround(player.getDirection(1));
		}

		if(player.getPosition().x < 0)
		{
			player.setPosition(vec2(0, player.getPosition().y));
			player.setVelocity(vec2(0, player.getVelocity().y));
		}

		if(player.getPosition().x + player.getSize().x > 640)
		{
			player.setPosition(vec2(player.getPosition().x + 640 - player.getPosition().x - player.getSize().x, player.getPosition().y));
			player.setVelocity(vec2(0, player.getVelocity().y));
		}

		if(tile.getType() != 0 
			&& player.getPosition().x + player.getSize().x > tile.getPosition().x
			&& player.getPosition().x < tile.getPosition().x + Tile::TILE_SIZE
			&& player.getPosition().y >= tile.getPosition().y
			&& player.getPosition().y + player.getVelocity().y <= tile.getPosition().y + Tile::TILE_SIZE)
		{
			player.setPosition(vec2(player.getPosition().x, tile.getPosition().y + Tile::TILE_SIZE));
			player.setVelocity(vec2(player.getVelocity().x, 0));
		}
	}
	player.update();
}

void Level1::render()
{
	Graphics::renderTexture(bg, 0, 0);
	tilemap.render();
	player.render();
}
