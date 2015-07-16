#ifndef TILEMAP_H
#define TILEMAP_H

#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include "tile.h"
#include "../util/fileutil.h"

#define TILEMAP_WIDTH 20

class TileMap
{

public:
	TileMap(const char*, const char*);

	void init();
	void render();

	const Tile& getTile(int index) const { return tiles[index]; }

private:
	std::vector<unsigned int> map;
	std::vector<Tile> tiles;

};

#endif