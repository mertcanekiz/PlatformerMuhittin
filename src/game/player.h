#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "gameobject.h"
#include "../graphics.h"

class Player : public GameObject
{

public:
	Player(vec2);
	virtual ~Player() {}

	static const int WIDTH = 16;
	static const int HEIGHT = 16;

	void input(SDL_Event event);
	void update();
	void render();

	void setPosition(vec2);
	void setVelocity(vec2);

private:
	const float GRAVITY_ACCELERATION = 0.3f;
	const float HORIZONTAL_ACCELERATION = 0.1f;
	const float MAX_VELOCITY = 3.0f;
	bool directions[2];


};

#endif
