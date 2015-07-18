#include "graphics.h"
#include "application.h"

TTF_Font* Graphics::DEFAULT_FONT = nullptr;
SDL_Renderer* Graphics::renderer = nullptr;

bool Graphics::init()
{
	if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << "Could not initialize SDL_image: " << IMG_GetError() << std::endl;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_image Error", "Could not initialize SDL_image", Application::getInstance().getWindow());
		return false;
	}

	if(TTF_Init() == -1)
	{
		std::cout << "Could not initialize SDL_ttf: " << TTF_GetError() << std::endl;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_ttf Error", "Could not initialize SDL_ttf", Application::getInstance().getWindow());
		return false;
	}

	DEFAULT_FONT = TTF_OpenFont("res/font.ttf", 18);

	if(DEFAULT_FONT == nullptr)
	{
		std::cout << "Could not load font: " << TTF_GetError() << std::endl;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Could not read font", "Could not load font file from res/font.ttf", Application::getInstance().getWindow());
		return false;
	}

	renderer = SDL_GetRenderer(Application::getInstance().getWindow());

	if(renderer == nullptr)
	{
		std::cout << "Could not get renderer from window" << std::endl;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error", "Could not get renderer from window", Application::getInstance().getWindow());
		return false;
	}

	return true;
}

void Graphics::fillRect(int x, int y, int w, int h, SDL_Color color)
{
	SDL_Rect r = { x, y, w, h };
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0xff);
	SDL_RenderFillRect(renderer, &r);
}

SDL_Texture* Graphics::loadTexture(const char* filename, SDL_Color color)
{
	SDL_Texture* texture = nullptr;

	SDL_Surface* loadedSurface = IMG_Load(filename);
	if(loadedSurface == nullptr)
	{
		std::cout << "Could not load image: " << filename << ": " << IMG_GetError() << std::endl;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_image Error", "Could not load image", Application::getInstance().getWindow());

	}
	else
	{
		if(color.r != -1)
			SDL_SetColorKey(loadedSurface, SDL_TRUE, 0xff00ff);
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

		if(texture == nullptr)
		{
			std::cout << "Could not create texture: " << filename << ": " << IMG_GetError() << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_image Error", "Could not create texture", Application::getInstance().getWindow());
		}

		SDL_FreeSurface(loadedSurface);
	}

	std::cout << "Loaded texture: " << filename << std::endl;

	return texture;
}

SDL_Texture* Graphics::loadTexture(std::string filename, SDL_Color color)
{
	return Graphics::loadTexture(filename.c_str(), color);
}


SDL_Texture* Graphics::createTextureFromText(std::string text, TTF_Font* font, SDL_Color color)
{
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* texture = nullptr;

	if(textSurface == nullptr)
	{
		std::cout << "Could not render text surface: " << TTF_GetError() << std::endl;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_ttf Error", "Could not render text surface", Application::getInstance().getWindow());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);

		if(texture == nullptr)
		{
			std::cout << "Could not create texture from text surface: " << SDL_GetError() << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error", "Could not creat texture from text surface", Application::getInstance().getWindow());
		}

		SDL_FreeSurface(textSurface);
	}

	return texture;
}

void Graphics::renderTexture(SDL_Texture* texture, int x, int y, float scale)
{
	if(texture == nullptr) return;

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, nullptr, nullptr, &dst.w, &dst.h);
	dst.w *= scale;
	dst.h *= scale;
	SDL_RenderCopy(renderer, texture, nullptr, &dst);
}

void Graphics::cleanUp()
{
	TTF_CloseFont(DEFAULT_FONT);
	DEFAULT_FONT = nullptr;
}
