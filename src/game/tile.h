#ifndef TILE_H
#define TILE_H

#include <vector>
#include <SDL2/SDL.h>
#include "../graphics.h"
#include "../math/vec2.h"
#include "../util/fileutil.h"

#define TILE_GREEN  0
#define TILE_RED    1
#define TILE_BLUE   2

#define TILE_TYPE_COUNT 3

class Tile
{
public:
	Tile(int, int, unsigned int);
	~Tile(){}

	static const int TILE_SIZE = 32;

	void render();
	static void loadImages();

	inline const vec2& getPosition() const { return position; }
	inline unsigned int getType() const { return type; }

private:
	int type;
	vec2 position;
	SDL_Texture* image;
	static std::vector<SDL_Texture*> images;
};

#endif