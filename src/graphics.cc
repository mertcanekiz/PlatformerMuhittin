#include "graphics.h"
#include "application.h"

TTF_Font* Graphics::DEFAULTFONT = nullptr;
SDL_Renderer* Graphics::renderer = nullptr;

bool Graphics::init()
{
	if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << "Could not initialize SDL_image: " << IMG_GetError() << std::endl;
		return false;
	}

	if(TTF_Init() == -1)
	{
		std::cout << "Could not initialize SDL_ttf: " << TTF_GetError() << std::endl;
		return false;
	}

	DEFAULTFONT = TTF_OpenFont("res/font.ttf", 18);

	if(DEFAULTFONT == nullptr)
	{
		std::cout << "Could not load font: " << TTF_GetError() << std::endl;
		return false;
	}

	renderer = Application::getInstance().getRenderer();

	if(renderer == nullptr)
	{
		std::cout << "Could not grab renderer" << std::endl;
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
		std::cout << "Could not load image: " << filename << ": " << IMG_GetError() << std::endl;
	else
	{
		if(color.r != -1)
			SDL_SetColorKey(loadedSurface, SDL_TRUE, 0xff00ff);
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

		if(texture == nullptr)
			std::cout << "Could not load texture: " << filename << ": " << IMG_GetError() << std::endl;

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
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);

		if(texture == nullptr)
			std::cout << "Could not create texture from text surface: " << SDL_GetError() << std::endl;

		SDL_FreeSurface(textSurface);
	}

	return texture;
}

void Graphics::renderTexture(SDL_Texture* texture, int x, int y)
{
	if(texture == nullptr) return;

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, nullptr, nullptr, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, texture, nullptr, &dst);
}

void Graphics::renderTexture2x(SDL_Texture* texture, int x, int y)
{
	if(texture == nullptr) return;

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, nullptr, nullptr, &dst.w, &dst.h);
	dst.w *= 2;
	dst.h *= 2;
	SDL_RenderCopy(renderer, texture, nullptr, &dst);
}

void Graphics::cleanUp()
{
	TTF_CloseFont(DEFAULTFONT);
	DEFAULTFONT = nullptr;
}
