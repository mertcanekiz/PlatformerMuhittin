#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"
#include "../graphics.h"

class Player : public GameObject
{

public:
	Player(vec2);
	virtual ~Player() {}

	static const int WIDTH = 16;
	static const int HEIGHT = 16;

	void update();
	void render();

	void setPosition(vec2);
	void setVelocity(vec2);


};

#endif
