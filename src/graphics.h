#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <cstdlib>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Graphics
{

public:
	static bool init();
	static SDL_Texture* createTextureFromText(std::string, TTF_Font*, SDL_Color);
	static SDL_Texture* loadTexture(const char*, SDL_Color = {-1,-1,-1});
	static SDL_Texture* loadTexture(std::string, SDL_Color = {-1,-1,-1});
	static void renderTexture(SDL_Texture*, int, int);
	static void renderTexture2x(SDL_Texture*, int, int);
	static void fillRect(int, int, int, int, SDL_Color);
	static void cleanUp();
	static SDL_Texture* getSubImageFromSpriteSheet(SDL_Texture*, unsigned int);

	static TTF_Font* DEFAULTFONT;

private:
	static SDL_Renderer* renderer;

};

#endif
