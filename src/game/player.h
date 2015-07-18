#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "gameobject.h"
#include "../graphics.h"

#define KEY_RIGHT SDLK_d
#define KEY_LEFT  SDLK_a

class Player : public GameObject
{

public:
	Player(vec2);
	virtual ~Player() {}

	static const int WIDTH = 16;
	static const int HEIGHT = 24;

	void input(SDL_Event event);
	void update();
	void render();

	inline const vec2& getPosition() const { return position; }
	inline const vec2& getSize() const { return size; }
	inline const vec2& getAcceleration() const { return acceleration; }
	inline const vec2& getVelocity() const { return velocity; }
	inline bool getDirection(int i) const { return directions[i]; }

	void setPosition(vec2);
	void setVelocity(vec2);
	inline void setAcceleration(const vec2& acceleration) { this->acceleration = acceleration; }
	inline void setTouchingGround(bool b) { this->touchingGround = b; }

private:
	const float GRAVITY_ACCELERATION = 0.3f;
	const float HORIZONTAL_ACCELERATION = 0.1f;
	const float HORIZONTAL_SPRINT_ACCELERATION = 0.17f;
	const float MAX_VELOCITY = 3.0f;
	const float MAX_SPRINT_VELOCITY = 4.5f;
	const float JUMP_ACCELERATION = -5.0f;

	bool directions[2];
	bool touchingGround;
	bool jump;
	bool sprint;


};

#endif
