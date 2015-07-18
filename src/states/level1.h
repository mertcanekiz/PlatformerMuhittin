#ifndef LEVEL1_H
#define LEVEL1_H

#include "gamestate.h"
#include "../game/player.h"
#include "../game/tilemap.h"
#include "../math/vec2.h"
#include "../graphics.h"

class Level1 : public GameState
{
public:
	Level1();
	virtual ~Level1() {}

	void init();
	void input(SDL_Event event);
	void update();
	void render();

private:
	Player player;
	TileMap tilemap;
	SDL_Texture* bg;
};

#endif
