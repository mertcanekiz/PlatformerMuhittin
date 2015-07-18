#include "player.h"
#include "../application.h"
#include <string>

Player::Player(vec2 position)
{
	this->position = position;
	this->size = vec2(WIDTH, HEIGHT);
	velocity = vec2(0, 0);
	acceleration = vec2(0, GRAVITY_ACCELERATION);
	directions[0] = false;
	directions[1] = false;
	jump = false;
	sprint = false;
	// boundingBox.x = position.x;
	// boundingBox.y = position.y + 10;
	// boundingBox.w = WIDTH;
	// boundingBox.h = 4;
}

void Player::input(SDL_Event event)
{
	if(event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case KEY_RIGHT:
				directions[0] = true;
				break;
			case KEY_LEFT:
				directions[1] = true;
				break;
			case SDLK_w:
				jump = true;
				break;
			case SDLK_LSHIFT:
				sprint = true;
				break;
		}
	}

	if(event.type == SDL_KEYUP)
	{
		switch(event.key.keysym.sym)
		{
			case KEY_RIGHT:
				directions[0] = false;
				break;
			case KEY_LEFT:
				directions[1] = false;
				break;
			case SDLK_w:
				jump = false;
				break;
			case SDLK_LSHIFT:
				sprint = false;
				break;
		}
	}
}

void Player::update()
{
	velocity += acceleration;

	if(directions[0])
	{
		acceleration.x = sprint ? HORIZONTAL_SPRINT_ACCELERATION : HORIZONTAL_ACCELERATION;
	}
	else if(directions[1])
	{
		acceleration.x = sprint ? -HORIZONTAL_SPRINT_ACCELERATION : -HORIZONTAL_ACCELERATION;
	}
	else
	{
		if(velocity.x > 0.1f)
			acceleration.x = -HORIZONTAL_ACCELERATION;
		else if(velocity.x < -0.1f)
			acceleration.x = HORIZONTAL_ACCELERATION;
		else
		{
			velocity.x = 0;
			acceleration.x = 0;
		}
	}

	if(!sprint)
	{
		if(velocity.x > MAX_VELOCITY)
			velocity.x = MAX_VELOCITY;
		if(velocity.x < -MAX_VELOCITY)
			velocity.x = -MAX_VELOCITY;
	}
	else
	{
		if(velocity.x > MAX_SPRINT_VELOCITY)
			velocity.x = MAX_SPRINT_VELOCITY;
		if(velocity.x < -MAX_SPRINT_VELOCITY)
			velocity.x = -MAX_SPRINT_VELOCITY;
	}

	if(touchingGround && jump)
	{
		velocity.y = JUMP_ACCELERATION;
	}

	position += velocity;
	// boundingBox.x = (int)position.x;
	// boundingBox.y = (int)position.y + 10;
}

void Player::render()
{
	Graphics::fillRect((int)position.x, (int)position.y, WIDTH, HEIGHT, {(int)(0.6*255), 0x00, 0x00});
	//Graphics::fillRect(boundingBox.x, boundingBox.y, boundingBox.w, boundingBox.h, {0x00, 0xff, 0xff});
}

void Player::setPosition(vec2 position)
{
	this->position = position;
}

void Player::setVelocity(vec2 velocity)
{
	this->velocity = velocity;
}
