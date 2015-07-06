#include "splash.h"
#include "../application.h"

Splash::Splash()
{
	splashImage = nullptr;
}

void Splash::init()
{
	timer = SDL_GetTicks();
	if(splashImage == nullptr)
		splashImage = Graphics::loadTexture("res/splash/splash.png");
}

void Splash::input(SDL_Event event)
{

}

void Splash::update()
{
	if(SDL_GetTicks() - timer >= SPLASH_TIME)
		Application::getInstance().changeState(GameState::MENU);
}

void Splash::render()
{
	Graphics::renderTexture(splashImage, 0, 0);
}
