#include "MeleeWeapon.h"


MeleeWeapon::MeleeWeapon()
{
}


MeleeWeapon::~MeleeWeapon()
{
	
}

void MeleeWeapon::onCollision(Object* objectB)
{
	cout << "collisions" << endl;

	// check for collisions
	if (objectB->objType == OBJ_NPC)
	{
		// if obj is not in hitlist: addit and do collision code
		if (std::find(hitList.begin(), hitList.end(), objectB) == hitList.end())
		{
			hitList.push_back(objectB);
			// dmg enemy
			cout << "Hit enemy" << endl;
		}
		//else ignore it
	}
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
			hitList.clear();
		}
	}
}
