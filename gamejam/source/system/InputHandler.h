#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "general.h"

#include "scene/Camera.h"
#include "system/GameData.h"

#include "entities/Player.h"

class InputHandler
{
    public:
        InputHandler();
        virtual ~InputHandler();

        void init();
        void handleEvents();

        void handleMouseEvents();
        void handleControllerEvents();
        void handlePlayerEvents();

        void debug_events();

        Player* m_player;
    private:

        int         lastUsed = 0;
        b2Vec2      m_rawVelocity;
        float       m_rawRotation = 0;
        bool        js_move = false;

        KeyboardKey* moveUp;
		KeyboardKey* moveDown;
		KeyboardKey* moveLeft;
		KeyboardKey* moveRight;
		KeyboardKey* ability1;
		KeyboardKey* ability2;
		KeyboardKey* ability3;
		KeyboardKey* ability4;

		KeyboardKey* zoomin;
		KeyboardKey* zoomout;

		KeyboardKey* cameraL;
		KeyboardKey* cameraR;
		KeyboardKey* cameraU;
		KeyboardKey* cameraD;


};

#endif // INPUTHANDLER_H
