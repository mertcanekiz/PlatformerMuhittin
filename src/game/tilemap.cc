#include "tilemap.h"


TileMap::TileMap(const char* mapFilename, const char* spriteSheetFilename)
{
	map = loadMap(mapFilename);
}

void TileMap::init()
{
	map = loadMap("res/maps/level1.map");
	Tile::loadImages();
	if(tiles.empty())
	{
		for(unsigned int i = 0; i < map.size(); i++)
			tiles.push_back(Tile((i % TILEMAP_WIDTH) * Tile::TILE_SIZE, (i / TILEMAP_WIDTH) * Tile::TILE_SIZE, map[i]));
	}
	std::cout << tiles.size() << std::endl;
}

void TileMap::render()
{
	for(Tile &t : tiles)
		t.render();
}