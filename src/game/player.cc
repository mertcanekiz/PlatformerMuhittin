#include "player.h"
#include "../application.h"

Player::Player(vec2 position)
{
	this->position = position;
	velocity = vec2(0, 0);
	acceleration = vec2(0, GRAVITY_ACCELERATION);
	directions[0] = false;
	directions[1] = false;
}

void Player::input(SDL_Event event)
{
	if(event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_d:
				directions[0] = true;
				break;
			case SDLK_a:
				directions[1] = true;
				break;
		}
	}

	if(event.type == SDL_KEYUP)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_d:
				directions[0] = false;
				break;
			case SDLK_a:
				directions[1] = false;
				break;
		}
	}
}

void Player::update()
{
	if(directions[0])
	{
		acceleration.x = HORIZONTAL_ACCELERATION;
	}
	else if(directions[1])
	{
		acceleration.x = -HORIZONTAL_ACCELERATION;
	}
	else
	{
		if(velocity.x > 0.01f)
			acceleration.x = -HORIZONTAL_ACCELERATION;
		else if(velocity.x < -0.01f)
			acceleration.x = HORIZONTAL_ACCELERATION;
		else
		{
			velocity.x = 0;
			acceleration.x = 0;
		}
	}

	if(position.y + HEIGHT >= Application::SCREEN_HEIGHT)
	{
		acceleration.y = 0;
		velocity.y = 0;

		position.y += Application::SCREEN_HEIGHT - position.y - HEIGHT;
	}

	velocity += acceleration;
	position += velocity;

	if(velocity.x > MAX_VELOCITY)
		velocity.x = MAX_VELOCITY;
	if(velocity.x < -MAX_VELOCITY)
		velocity.x = -MAX_VELOCITY;

}

void Player::render()
{
	Graphics::fillRect((int)position.x, (int)position.y, WIDTH, HEIGHT, {0xff, 0x00, 0x00});
}

void Player::setPosition(vec2 position)
{
	this->position = position;
}

void Player::setVelocity(vec2 velocity)
{
	this->velocity = velocity;
}
