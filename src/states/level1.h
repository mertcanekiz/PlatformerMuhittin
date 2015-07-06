#ifndef LEVEL1_H
#define LEVEL1_H

#include "gamestate.h"
#include "../game/player.h"
#include "../math/vec2.h"

class Level1 : public GameState
{
public:
	Level1();
	virtual ~Level1(){ delete player; }

	void init();
	void input(SDL_Event event);
	void update();
	void render();

private:
	Player *player;
};

#endif
