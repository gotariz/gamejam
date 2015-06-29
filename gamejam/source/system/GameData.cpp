#include "GameData.h"

GameData gdata;

GameData::GameData()
{
    keys.reserve( 282 );
    for (unsigned i = 0; i < 300; ++i)
    {
        keys.push_back( NULL );
    }

    //Alphabet
	keys[SDL_SCANCODE_A] = KeyboardKey(SDL_SCANCODE_A, "A");
	keys[SDL_SCANCODE_B] = KeyboardKey(SDL_SCANCODE_B, "B");
	keys[SDL_SCANCODE_C] = KeyboardKey(SDL_SCANCODE_C, "C");
	keys[SDL_SCANCODE_D] = KeyboardKey(SDL_SCANCODE_D, "D");
	keys[SDL_SCANCODE_E] = KeyboardKey(SDL_SCANCODE_E, "E");
	keys[SDL_SCANCODE_F] = KeyboardKey(SDL_SCANCODE_F, "F");
	keys[SDL_SCANCODE_G] = KeyboardKey(SDL_SCANCODE_G, "G");
	keys[SDL_SCANCODE_H] = KeyboardKey(SDL_SCANCODE_H, "H");
	keys[SDL_SCANCODE_I] = KeyboardKey(SDL_SCANCODE_I, "I");
	keys[SDL_SCANCODE_J] = KeyboardKey(SDL_SCANCODE_J, "J");
	keys[SDL_SCANCODE_K] = KeyboardKey(SDL_SCANCODE_K, "K");
	keys[SDL_SCANCODE_L] = KeyboardKey(SDL_SCANCODE_L, "L");
	keys[SDL_SCANCODE_M] = KeyboardKey(SDL_SCANCODE_M, "M");
	keys[SDL_SCANCODE_N] = KeyboardKey(SDL_SCANCODE_N, "N");
	keys[SDL_SCANCODE_O] = KeyboardKey(SDL_SCANCODE_O, "O");
	keys[SDL_SCANCODE_P] = KeyboardKey(SDL_SCANCODE_P, "P");
	keys[SDL_SCANCODE_Q] = KeyboardKey(SDL_SCANCODE_Q, "Q");
	keys[SDL_SCANCODE_R] = KeyboardKey(SDL_SCANCODE_R, "R");
	keys[SDL_SCANCODE_S] = KeyboardKey(SDL_SCANCODE_S, "S");
	keys[SDL_SCANCODE_T] = KeyboardKey(SDL_SCANCODE_T, "T");
	keys[SDL_SCANCODE_U] = KeyboardKey(SDL_SCANCODE_U, "U");
	keys[SDL_SCANCODE_V] = KeyboardKey(SDL_SCANCODE_V, "V");
	keys[SDL_SCANCODE_W] = KeyboardKey(SDL_SCANCODE_W, "W");
	keys[SDL_SCANCODE_X] = KeyboardKey(SDL_SCANCODE_X, "X");
	keys[SDL_SCANCODE_Y] = KeyboardKey(SDL_SCANCODE_Y, "Y");
	keys[SDL_SCANCODE_Z] = KeyboardKey(SDL_SCANCODE_Z, "Z");

	keys[SDL_SCANCODE_1] = KeyboardKey(SDL_SCANCODE_1, "1");
	keys[SDL_SCANCODE_2] = KeyboardKey(SDL_SCANCODE_2, "2");
	keys[SDL_SCANCODE_3] = KeyboardKey(SDL_SCANCODE_3, "3");
	keys[SDL_SCANCODE_4] = KeyboardKey(SDL_SCANCODE_4, "4");
	keys[SDL_SCANCODE_5] = KeyboardKey(SDL_SCANCODE_5, "5");
	keys[SDL_SCANCODE_6] = KeyboardKey(SDL_SCANCODE_6, "6");
	keys[SDL_SCANCODE_7] = KeyboardKey(SDL_SCANCODE_7, "7");
	keys[SDL_SCANCODE_8] = KeyboardKey(SDL_SCANCODE_8, "8");
	keys[SDL_SCANCODE_9] = KeyboardKey(SDL_SCANCODE_9, "9");
	keys[SDL_SCANCODE_0] = KeyboardKey(SDL_SCANCODE_0, "0");

	keys[SDL_SCANCODE_RETURN]		= KeyboardKey(SDL_SCANCODE_RETURN, "Enter");
	keys[SDL_SCANCODE_ESCAPE]		= KeyboardKey(SDL_SCANCODE_ESCAPE, "Escape");
	keys[SDL_SCANCODE_BACKSPACE]	= KeyboardKey(SDL_SCANCODE_BACKSPACE, "Backspace");
	keys[SDL_SCANCODE_TAB]			= KeyboardKey(SDL_SCANCODE_TAB, "Tab");
	keys[SDL_SCANCODE_SPACE]		= KeyboardKey(SDL_SCANCODE_SPACE, "Space");
	keys[SDL_SCANCODE_MINUS]		= KeyboardKey(SDL_SCANCODE_MINUS, "-");
	keys[SDL_SCANCODE_EQUALS]		= KeyboardKey(SDL_SCANCODE_EQUALS, "=");
	keys[SDL_SCANCODE_LEFTBRACKET]	= KeyboardKey(SDL_SCANCODE_LEFTBRACKET, "[");
	keys[SDL_SCANCODE_RIGHTBRACKET] = KeyboardKey(SDL_SCANCODE_RIGHTBRACKET, "]");
	keys[SDL_SCANCODE_BACKSLASH]	= KeyboardKey(SDL_SCANCODE_BACKSLASH, "\\");
	keys[SDL_SCANCODE_NONUSHASH]	= KeyboardKey(SDL_SCANCODE_NONUSHASH, "");
	keys[SDL_SCANCODE_SEMICOLON]	= KeyboardKey(SDL_SCANCODE_SEMICOLON, ";");
	keys[SDL_SCANCODE_APOSTROPHE]	= KeyboardKey(SDL_SCANCODE_APOSTROPHE, "'");
	keys[SDL_SCANCODE_GRAVE]		= KeyboardKey(SDL_SCANCODE_GRAVE, "`");
	keys[SDL_SCANCODE_COMMA]		= KeyboardKey(SDL_SCANCODE_COMMA, ",");
	keys[SDL_SCANCODE_PERIOD]		= KeyboardKey(SDL_SCANCODE_PERIOD, ".");
	keys[SDL_SCANCODE_SLASH]		= KeyboardKey(SDL_SCANCODE_SLASH, "/");
	keys[SDL_SCANCODE_CAPSLOCK]		= KeyboardKey(SDL_SCANCODE_CAPSLOCK, "Capslock");

	keys[SDL_SCANCODE_F1] = KeyboardKey(SDL_SCANCODE_F1, "F1");
	keys[SDL_SCANCODE_F2] = KeyboardKey(SDL_SCANCODE_F2, "F2");
	keys[SDL_SCANCODE_F3] = KeyboardKey(SDL_SCANCODE_F3, "F3");
	keys[SDL_SCANCODE_F4] = KeyboardKey(SDL_SCANCODE_F4, "F4");
	keys[SDL_SCANCODE_F5] = KeyboardKey(SDL_SCANCODE_F5, "F5");
	keys[SDL_SCANCODE_F6] = KeyboardKey(SDL_SCANCODE_F6, "F6");
	keys[SDL_SCANCODE_F7] = KeyboardKey(SDL_SCANCODE_F7, "F7");
	keys[SDL_SCANCODE_F8] = KeyboardKey(SDL_SCANCODE_F8, "F8");
	keys[SDL_SCANCODE_F9] = KeyboardKey(SDL_SCANCODE_F9, "F9");
	keys[SDL_SCANCODE_F10] = KeyboardKey(SDL_SCANCODE_F10, "F10");
	keys[SDL_SCANCODE_F11] = KeyboardKey(SDL_SCANCODE_F11, "F11");
	keys[SDL_SCANCODE_F12] = KeyboardKey(SDL_SCANCODE_F12, "F12");

	keys[SDL_SCANCODE_PRINTSCREEN] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_SCROLLLOCK] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_PAUSE] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_INSERT] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_HOME] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_PAGEUP] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_RIGHT] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_LEFT] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_DOWN] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_UP] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_NUMLOCKCLEAR] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	
	keys[SDL_SCANCODE_KP_DIVIDE] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_KP_MULTIPLY] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_KP_MINUS] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_KP_PLUS] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_KP_ENTER] = KeyboardKey(SDL_SCANCODE_F12, "F12");
	keys[SDL_SCANCODE_KP_1] = KeyboardKey(SDL_SCANCODE_KP_1, "1");
	keys[SDL_SCANCODE_KP_2] = KeyboardKey(SDL_SCANCODE_KP_2, "2");
	keys[SDL_SCANCODE_KP_3] = KeyboardKey(SDL_SCANCODE_KP_3, "3");
	keys[SDL_SCANCODE_KP_4] = KeyboardKey(SDL_SCANCODE_KP_4, "4");
	keys[SDL_SCANCODE_KP_5] = KeyboardKey(SDL_SCANCODE_KP_5, "5");
	keys[SDL_SCANCODE_KP_6] = KeyboardKey(SDL_SCANCODE_KP_6, "6");
	keys[SDL_SCANCODE_KP_7] = KeyboardKey(SDL_SCANCODE_KP_7, "7");
	keys[SDL_SCANCODE_KP_8] = KeyboardKey(SDL_SCANCODE_KP_8, "8");
	keys[SDL_SCANCODE_KP_9] = KeyboardKey(SDL_SCANCODE_KP_9, "9");
	keys[SDL_SCANCODE_KP_0] = KeyboardKey(SDL_SCANCODE_KP_0, "0");

	keys[SDL_SCANCODE_MOUSE_LEFT]			= KeyboardKey(SDL_SCANCODE_MOUSE_LEFT, "Mouse Left");
	keys[SDL_SCANCODE_MOUSE_MIDDLE]			= KeyboardKey(SDL_SCANCODE_MOUSE_MIDDLE, "Mouse Middle");
	keys[SDL_SCANCODE_MOUSE_RIGHT]			= KeyboardKey(SDL_SCANCODE_MOUSE_RIGHT, "Mouse Right");
	keys[SDL_SCANCODE_MOUSE_FORWARD]		= KeyboardKey(SDL_SCANCODE_MOUSE_FORWARD, "Mouse Forward");
	keys[SDL_SCANCODE_MOUSE_BACK]			= KeyboardKey(SDL_SCANCODE_MOUSE_BACK, "Mouse Back");
	keys[SDL_SCANCODE_MOUSE_SCROLL_UP]		= KeyboardKey(SDL_SCANCODE_MOUSE_SCROLL_UP, "Scroll Up");
	keys[SDL_SCANCODE_MOUSE_SCROLL_DOWN]	= KeyboardKey(SDL_SCANCODE_MOUSE_SCROLL_DOWN, "Scroll Down");

    //gz::print_value("keycount=",sf::Keyboard::KeyCount);


    //kbKeys[40] = kbKeys(7,"B");
}

void GameData::updateKeys()
{
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < keys.size() - 18; ++i)
	{
		KeyboardKey* key = &keys[i];
		if (key != NULL)
		{
			key->updateKey(keystate[key->m_key]);
		}
	}

	keys[SDL_SCANCODE_MOUSE_LEFT].updateKey(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT));
	keys[SDL_SCANCODE_MOUSE_MIDDLE].updateKey(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE));
	keys[SDL_SCANCODE_MOUSE_RIGHT].updateKey(SDL_GetMouseState(NULL, NULL) &SDL_BUTTON(SDL_BUTTON_RIGHT));

}

/*
GameData::~GameData()
{
    //dtor
}

void GameData::setDeltaTime(float dt)
{
//    if (dt > MAX_TIME_STEP)
//    {
//        deltaTime = MAX_TIME_STEP;
//        deltaTimeExcess = dt - MAX_TIME_STEP;
//    }
//    else
    {
        m_deltaTime = dt;
        m_deltaTimeExcess = 0;
    }
}

int GameData::getScreenWidth()
{
    return m_window->getSize().x;
}

int GameData::getScreenHeight()
{
    return m_window->getSize().y;
}

int GameData::getHalfScreenWidth()
{
    return m_window->getSize().x / 2;
}

int GameData::getHalfScreenHeight()
{
    return m_window->getSize().y / 2;
}

*/
Vector2 GameData::toPixels(float x, float y)
{
	
	int pixel_x = surface->w / 2 + (x * (WORLD_SCALE * zoom));
	int pixel_y = surface->h / 2 - (y * (WORLD_SCALE * zoom));

    return Vector2(pixel_x,pixel_y);
}


