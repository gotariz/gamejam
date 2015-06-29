#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "general.h"

class Camera;
class Settings;
class AssetManager;

class GameData
{
    public:
		GameData();
		virtual ~GameData(){}

    public: // variables

		int mousea = 0;
		int mouseb = 0;

		int m_what = 0;
		AssetManager*	assets = nullptr;
		Camera*			camera = nullptr;

		bool			running = true;
		SDL_Window*		window = nullptr;
		SDL_Surface*	surface = nullptr;
		SDL_Renderer*	renderer = nullptr;
		Settings*		settings = nullptr;
		RunState		gamestate = STATE_GAME;

		float			zoom = 1.0;
		int				m_timeDelta = 0;

    public:
		void updateKeys();
		vector<KeyboardKey>	keys;
		Vector2 toPixels(float x, float y);
};


extern GameData gdata;
#endif // GAMEDATA_H
