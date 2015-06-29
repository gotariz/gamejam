#include "StateGame.h"

StateGame::StateGame() : IState(STATE_GAME)
{
    //ctor
}

StateGame::~StateGame()
{
    //dtor
}

void StateGame::load()
{
	assets.renderer = gdata.renderer;
	assets.loadAssetList("data/assets.xml");

	camera.m_x = 0;
	camera.m_y = 0;
	camera.m_w = gdata.settings->getScreenWidth();
	camera.m_h = gdata.settings->getScreenHeight();
	gdata.camera = &camera;

	visualDebugger = new VisualDebugger();
	visualDebugger->SetFlags(b2Draw::e_shapeBit | b2Draw::e_jointBit | b2Draw::e_pairBit | b2Draw::e_centerOfMassBit);
	visualDebugger->cam = &camera;

	world = new b2World(GRAVITY);
	world->SetDebugDraw(visualDebugger);
	world->SetContactListener(&d_contactListener);

	factory = PhysicsFactory(world);

	purista12 = new sdlFontRenderer(gdata.renderer);
	purista12->setFont(assets.getFont("purista-medium-14-white"));

	manager.setPhysicsWorld(world);

	player = new Player(manager.getValidID());
	player->setPhysicsObject(factory.createPlayer(2, 2, player));
	player->setRotation(0);
	player->m_name = "Object: player";
	player->objType = OBJ_PLAYER;
	manager.addObject(player);

	d_inputHandler.init();
	d_inputHandler.m_player = player;

	wep = new MeleeWeapon();
	wep->setPhysicsObject(factory.createSwordBasic(wep));
	player->addChild(wep);
	wep->setPosition(Vector2(0,0));
	player->weapon = wep;
	wep->objType = OBJ_WEAPON;
	//manager.addObject(wep);

	enemy = new Object;
	enemy->setPhysicsObject(factory.createKinematicPlayer(0, 0, enemy));
	enemy->setPosition(Vector2(0, 0));
	enemy->m_name = "Object: enemy";
	enemy->objType = OBJ_NPC;
	manager.addObject(enemy);

	img.setTexture(assets.getTexture("loading"));

	level.init();

    loading = false;
}

bool StateGame::initialise()
{
	load();

    return true;
}

void StateGame::start()
{
}


void StateGame::handleEvents()
{
	d_inputHandler.handleEvents();
}

void StateGame::update()
{
	manager.update();
}

void StateGame::draw()
{
	//aimg.m_angle += 90.f / 60.f;
	SDL_RenderClear(gdata.renderer);

	//level.draw();

	img.renderImage(gdata.renderer);
	manager.draw();

	world->DrawDebugData();


	//purista12->drawString(200, 200, "this is a test ;)");
	
	// flip the buffer
	SDL_RenderPresent(gdata.renderer);
}

void StateGame::freeResources()
{
}
