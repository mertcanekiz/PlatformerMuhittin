#include "tile.h"

std::vector<SDL_Texture*> Tile::images;

Tile::Tile(int x, int y, unsigned int type) : position(x, y), type(type)
{
	if(!images.empty())
		image = images[type];
}

void Tile::loadImages()
{
	if(images.empty())
	{
		for(int i = 0; i < TILE_TYPE_COUNT; i++)
		{
				images.push_back(Graphics::loadTexture(std::string("res/tiles/tile" + std::to_string(i) + ".png")));
		}
	}
	std::cout << images.size() << std::endl;
}

void Tile::render()
{
	Graphics::renderTexture(image, (int)position.x, (int)position.y, 2.0f);
}