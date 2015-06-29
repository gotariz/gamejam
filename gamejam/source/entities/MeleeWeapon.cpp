#include "MeleeWeapon.h"


MeleeWeapon::MeleeWeapon()
{
}


MeleeWeapon::~MeleeWeapon()
{
}


void MeleeWeapon::onEnterCollision(Object* objectB)
{
	if (active)
		cout << "melee weapon enter" << endl;
}

void MeleeWeapon::onExitCollision(Object* objectB)
{
	if (active)
		cout << "melee weapon exit" << endl;
}

void MeleeWeapon::onUpdate()
{
	//cout << "num collisions" << m_collidingObjects.size() << endl;
	Object::onUpdate();

	if (active)
	{
		elapsedTime += gdata.m_timeDelta;
		//cout << elapsedTime << " TIME" << endl;
		if (elapsedTime >= 150)
		{
			active = false;
			elapsedTime = 0;
			cout << "Finished" << endl;
		}

		// check for collisions
		for (int i = 0; i < m_collidingObjects.size(); i++)
		{
			if (m_collidingObjects.at(i)->objType == OBJ_NPC)
			{
				cout << "Hit enemy" << endl;
			}
		}
	}
}
