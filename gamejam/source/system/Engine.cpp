#include "Engine.h"

Engine::Engine()
{
    //ctor
}

Engine::~Engine()
{
    //dtor
}

void Engine::run()
{
	gzClock clock;
	float oldTime = clock.getCurrentTimeMilliseconds();
    // check to switch states
    while(running)
    {
		//Sleep(16);
		float newTime = clock.getCurrentTimeMilliseconds();
		float delta = newTime - oldTime;
		int fps = 1000.0f / delta;
		oldTime = newTime;
		string title = "fps" + gz::toString(fps);
		SDL_SetWindowTitle(gdata.window, title.c_str());
		
		gdata.m_timeDelta = delta;


        updateState();

        activeState->handleEvents();
        activeState->update();
        activeState->draw();
        running = gdata.running;

		SDL_Delay(16);
    }
}

void Engine::updateState()
{
    if (!activeState || activeState->getStateType() != gdata.gamestate)
    {
        if (activeState) // delete the active state then create the new one
        {
            activeState->freeResources();
            delete activeState;
            activeState = nullptr;
        }

        if (gdata.gamestate == RunState::STATE_GAME)
        {
            IState* stateGame = new StateGame();
            stateGame->initialise();
            activeState = stateGame;
        }
		else if (gdata.gamestate == RunState::STATE_MENU)
        {
//            IState* stateMenu = new StateMenu(gdata);
//            stateMenu->initialise();
//            activeState = stateMenu;
        }
    }
}

bool Engine::initialise()
{
    running = true;
    return true;
}

void Engine::exit()
{
    if (activeState)
    {
        activeState->freeResources();
        delete activeState;
        activeState = nullptr;
    }

	//Destroy window
	SDL_DestroyWindow(gdata.window);

	//Quit SDL subsystems
	SDL_Quit();
}


