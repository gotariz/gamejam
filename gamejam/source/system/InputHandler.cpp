#include "InputHandler.h"

InputHandler::InputHandler()
{
    //ctor
}

InputHandler::~InputHandler()
{
    //dtor
}

void InputHandler::init()
{
	ability1 = &gdata.keys[SDL_SCANCODE_UP];
	ability2 = &gdata.keys[SDL_SCANCODE_RIGHT];
	ability3 = &gdata.keys[SDL_SCANCODE_DOWN];
	ability4 = &gdata.keys[SDL_SCANCODE_LEFT];

	moveUp = &gdata.keys[SDL_SCANCODE_W];
	moveDown = &gdata.keys[SDL_SCANCODE_S];
	moveLeft = &gdata.keys[SDL_SCANCODE_A];
	moveRight = &gdata.keys[SDL_SCANCODE_D];

	zoomin = &gdata.keys[SDL_SCANCODE_EQUALS];
	zoomout = &gdata.keys[SDL_SCANCODE_MINUS];

	cameraL = &gdata.keys[SDL_SCANCODE_KP_4];
	cameraR = &gdata.keys[SDL_SCANCODE_KP_6];
	cameraU = &gdata.keys[SDL_SCANCODE_KP_8];
	cameraD = &gdata.keys[SDL_SCANCODE_KP_2];
}

void InputHandler::handleEvents()
{

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            gdata.running = false;
    }
	
	// update bound keys
	gdata.updateKeys();

	// update 
    handlePlayerEvents();

    handleMouseEvents();
    //handleKeybordEvents();
    handleControllerEvents();

    debug_events();

    m_player->setMoveDirection(Vector2(m_rawVelocity));
}

void InputHandler::handlePlayerEvents()
{
    float h = 0;
    float v = 0;

	if (ability1->isKeyPressed);// gz::print_d("ability 1");
	if (ability2->isKeyPressed);// gz::print_d("ability 2");
	if (ability3->isKeyPressed);// gz::print_d("ability 3");
	if (ability4->isKeyPressed);// gz::print_d("ability 4");

    // movement
    if (!js_move)
    {
		if (moveUp->isKeyDown)      { v += 1; }//gz::print_d("move up");}
		if (moveDown->isKeyDown)    { v -= 1; }//gz::print_d("move down");}

		if (moveLeft->isKeyDown)    { h -= 1; }//gz::print_d("move left");}
		if (moveRight->isKeyDown)   { h += 1; }//gz::print_d("move right");}

        m_rawVelocity.Set(h,v);
        if (h || v)// ensure we don't divide by zero
        {
            m_rawVelocity.Set( m_rawVelocity.x / m_rawVelocity.Length(), m_rawVelocity.y / m_rawVelocity.Length() );
        }
    }
}

void InputHandler::debug_events()
{
    //if (gdata.kbKeys.at(sf::Keyboard::Escape).isKeyPressed)  gdata.m_bridge.running = false;

    //zoom TODO: set scale of assets
	if (zoomin->isKeyPressed)		if ((gdata.zoom += 0.1) > 3) gdata.zoom = 3;
	if (zoomout->isKeyPressed)		if ((gdata.zoom -= 0.1) < 0.1) gdata.zoom = 0.1;

	if (cameraU->isKeyDown)			gdata.camera->m_y += 5.0f * (gdata.m_timeDelta / 1000.f);
	if (cameraD->isKeyDown)			gdata.camera->m_y += -5.0f * (gdata.m_timeDelta / 1000.f);
	if (cameraL->isKeyDown)			gdata.camera->m_x += -5.0f * (gdata.m_timeDelta / 1000.f);
	if (cameraR->isKeyDown)			gdata.camera->m_x += 5.0f * (gdata.m_timeDelta / 1000.f);
}

void InputHandler::handleMouseEvents()
{
    //if (lastUsed == 0)
    //{
    //    Vector2 mousePosition = Vector2(sf::Mouse::getPosition(*gdata.m_window).x,sf::Mouse::getPosition(*gdata.m_window).y);

    //    Vector2 playerPosition = m_player->getAbsolutePosition();
    //    playerPosition = gdata.toPixels(playerPosition.x - gdata.m_camera->m_x, playerPosition.y - gdata.m_camera->m_y);

    //    Vector2 distance = mousePosition - playerPosition;


    //    m_player->setRotation( Utils::convertToAngle(360 - distance.getAngle() - 90) );
    //}
}

void InputHandler::handleControllerEvents()
{
    //js_move = false;

    //float jsleft_x = 0;
    //float jsleft_y = 0;
    //float jsright_x = 0;
    //float jsright_y = 0;

    //if (sf::Joystick::isConnected(0))
    //{
    //    jsleft_x = sf::Joystick::getAxisPosition(0,sf::Joystick::X);
    //    jsleft_y = sf::Joystick::getAxisPosition(0,sf::Joystick::Y);
    //    jsright_x = sf::Joystick::getAxisPosition(0,sf::Joystick::U);
    //    jsright_y = sf::Joystick::getAxisPosition(0,sf::Joystick::R);
    //}

    //    float deadzone = 25;

    //    float xjs = jsleft_x;
    //    float yjs = 0 - jsleft_y;

    //    float joystick_distance = sqrt( (xjs * xjs) + (yjs * yjs) );

    //    if (joystick_distance > deadzone)
    //    {
    //        js_move = true;
    //        m_rawVelocity.Set(xjs,yjs);
    //        float nx = xjs / m_rawVelocity.Length();
    //        float ny = yjs / m_rawVelocity.Length();
    //        m_rawVelocity.Set(nx,ny);
    //        //gz::print_value("rv:",m_rawVelocity.Length());
    //    }

    //    deadzone = 50;

    //    float xs = 0 - jsright_x;
    //    float ys = 0 - jsright_y;

    //    float distance = sqrt( (xs * xs) + (ys * ys) );

    //    if (distance > deadzone)
    //    {
    //        float joyu = sf::Joystick::getAxisPosition(0,sf::Joystick::U);
    //        float joyr = 0 - sf::Joystick::getAxisPosition(0,sf::Joystick::R);

    //        // calculate direction to face using mouse pointer
    //        m_rawRotation = atan2( joyr, joyu) * 180.f / PI;
    //        m_player->setRotation(m_rawRotation);
    //        lastUsed = 1;

    //    }
}

