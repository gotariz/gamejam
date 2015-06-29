// using SDL and standard IO
#include "SDL.h"
#include <stdio.h>

#include "system/GameData.h"
#include "source/system/Engine.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	
	// create the engine
	Engine engine;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	} 
	else
	{
		// read settings
		engine.settings.readSettings();
		gdata.settings = &engine.settings;

		//Create window
		window = SDL_CreateWindow("Pluto fps:", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, engine.settings.getScreenWidth(), engine.settings.getScreenHeight(), SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);
		}

		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == nullptr)
		{
			cout << "CreateRenderer Error:" << SDL_GetError() << endl;
			SDL_Quit();
			SDL_DestroyWindow(window);
			return 1;
		}

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
		{
			cout << "OpenAudio Error:" << SDL_GetError() << endl;
		}

		gdata.window = window;
		gdata.surface = screenSurface;
		gdata.renderer = renderer;
	}
	engine.initialise();
	engine.run();
	engine.exit();

	return 0;
}