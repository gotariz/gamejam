#ifndef PHYSICSFACTORY_H
#define PHYSICSFACTORY_H

#include "general.h"

#include "system/GameData.h"

class PhysicsFactory
{
    public:
        PhysicsFactory(b2World* world = nullptr);
        virtual ~PhysicsFactory();

    public:
        b2World* m_world;

        b2Vec2* getRealCoords(b2Vec2 vertices[], int count);

    public:
        b2Body* createPlayer(float x = 0, float y = 0, void* userPointer = nullptr);
        b2Body* createKinematicPlayer(float x = 0, float y = 0, void* userPointer = nullptr);
        b2Body* createTestShape(void* userPointer = nullptr);
		b2Body* createBattleAxe(void* userPointer = nullptr);
		b2Body* createSwordBasic(void* userPointer = nullptr);

};

#endif // PHYSICSFACTORY_H
