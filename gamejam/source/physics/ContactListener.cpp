#include "ContactListener.h"

ContactListener::ContactListener()
{
    //ctor
}

ContactListener::~ContactListener()
{
    //dtor
}

void ContactListener::BeginContact(b2Contact* contact)
{
    void* userDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* userDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if (userDataA && userDataB)
    {
        Object* objectA = static_cast<Object*>(contact->GetFixtureA()->GetBody()->GetUserData());
        Object* objectB = static_cast<Object*>(contact->GetFixtureB()->GetBody()->GetUserData());

        objectA->m_collidingObjects.push_back(objectB);
        objectB->m_collidingObjects.push_back(objectA);

        objectA->onEnterCollision(objectB);
        objectB->onEnterCollision(objectA);
    }
}

void ContactListener::EndContact(b2Contact* contact)
{
    void* userDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* userDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if (userDataA && userDataB)
    {
        Object* objectA = static_cast<Object*>(contact->GetFixtureA()->GetBody()->GetUserData());
        Object* objectB = static_cast<Object*>(contact->GetFixtureB()->GetBody()->GetUserData());

        //objectA->m_collidingObjects.push_back(objectB);
        //objectB->m_collidingObjects.push_back(objectA);

		// clean this up
		for (unsigned i = 0; i < objectA->m_collidingObjects.size(); ++i)
		{
			if (objectA->m_collidingObjects.at(i) == objectB)
			{
				objectA->m_collidingObjects.erase(objectA->m_collidingObjects.begin() + i);
				i = INT_MAX;
			}
		}

		for (unsigned i = 0; i < objectB->m_collidingObjects.size(); ++i)
		{
			if (objectB->m_collidingObjects.at(i) == objectA)
			{
				objectB->m_collidingObjects.erase(objectB->m_collidingObjects.begin() + i);
				i = INT_MAX;
			}
		}

        objectA->onExitCollision(objectB);
        objectB->onExitCollision(objectA);
    }
}

