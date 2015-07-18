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

	unsigned int lastTime = SDL_GetTicks();
	double ms = 1000.0 / 60.0;
	double delta = 0.0;
	int updates = 0, frames = 0;
	unsigned int timer = SDL_GetTicks();

	while(running)
	{
		unsigned int now = SDL_GetTicks();
		delta += (now - lastTime) / ms;
		lastTime = now;
		while(SDL_PollEvent(&event))
		{
			input(event);
		}
		if(delta >= 1.0)
		{
			update();
			updates++;
			delta--;
		}
		render();
		frames++;

		if(SDL_GetTicks() - timer > 1000)
		{
			timer += 1000;
			std::cout << updates << " ups, " << frames << " fps" << std::endl;
			frames = 0;
			updates = 0;
		}

	}

	cleanUp();
	return 0;
}

void Application::input(SDL_Event event)
{
	if(event.type == SDL_QUIT)
		stop();
	currentState->input(event);
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
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error", "Could not initialize SDL", Application::getInstance().getWindow());
		return false;
	}

	window = SDL_CreateWindow("PlatformerTeddy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if(window == nullptr)
	{
		std::cout << "Could not create SDL window: " << SDL_GetError() << std::endl;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error", "Could not create SDL window", Application::getInstance().getWindow());
		SDL_Quit();
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(renderer == nullptr)
	{
		std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error", "Could not create SDL renderer", Application::getInstance().getWindow());
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
	GameState::cleanUp();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
