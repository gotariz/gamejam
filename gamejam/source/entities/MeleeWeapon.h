#ifndef MELEEWEAPON_H
#define MELEEWEAPON_H

#include "general.h"
#include "entities/Object.h"
#include "animation/Animation.h"

class MeleeWeapon : public Object
{
public:
	MeleeWeapon();
	virtual ~MeleeWeapon();

	bool active = false;
	int elapsedTime;

	virtual void onUpdate();
	virtual void onEnterCollision(Object* objectB);
	virtual void onExitCollision(Object* objectB);
	virtual void onCollision(Object* objectB);

	vector <Object*> hitList;
	
};

#endif // MELEEWEAPON_H