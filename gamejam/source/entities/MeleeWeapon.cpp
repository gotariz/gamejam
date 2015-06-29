#include "MeleeWeapon.h"


MeleeWeapon::MeleeWeapon()
{
}


MeleeWeapon::~MeleeWeapon()
{
}


void MeleeWeapon::onEnterCollision(Object* objectB)
{
	cout << "melee weapon enter" << endl;
}

void MeleeWeapon::onExitCollision(Object* objectB)
{
	cout << "melee weapon exit" << endl;
}