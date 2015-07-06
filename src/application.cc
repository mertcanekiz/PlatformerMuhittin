#include "application.h"

int Application::execute()
{
	if(!initialize())
	{
		return -1;
	}

	running = true;
	SDL_Event event;

	Application::changeState(GameState::SPLASH);

	while(running)
	{
		while(SDL_PollEvent(&event))
		{
			input(event);
		}

		update();
		render();
	}

	cleanUp();
	return 0;
}

void Application::input(SDL_Event event)
{
	if(event.type == SDL_QUIT)
		stop();
}

void Application::update()
{
	currentState->update();
}

void Application::render()
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(renderer);
	currentState->render();
	SDL_RenderPresent(renderer);
}

void Application::changeState(int id)
{
	currentState = GameState::getStateByID(id);
	currentState->init();
}

void Application::stop()
{
	if(!running)
		return;
	running = false;
}

bool Application::initialize()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Could not initialize SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow("PlatformerMuhittin", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if(window == nullptr)
	{
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(renderer == nullptr)
	{
		std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	if(Graphics::init() == false)
	{
		return false;
	}

	return true;
}

void Application::cleanUp()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
