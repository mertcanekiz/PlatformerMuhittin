#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../math/vec2.h"

class GameObject
{

public:
	virtual ~GameObject() {}

	static const int PLAYER = 0x00;

	virtual void update() = 0;
	virtual void render() = 0;

protected:
	vec2 position, velocity, acceleration;

};

#endif
