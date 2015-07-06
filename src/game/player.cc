#include "player.h"

Player::Player(vec2 position)
{
	this->position = position;
	velocity = vec2(0, 0);
}

void Player::update()
{
	position += velocity;
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
