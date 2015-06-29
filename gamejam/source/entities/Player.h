#ifndef PLAYER_H
#define PLAYER_H

#include "general.h"
#include "entities/Object.h"
#include "entities/MeleeWeapon.h"
#include "animation/Animation.h"

class Player : public Object
{
    public:
        Player(int id = -1);
        virtual ~Player();

    public:

        MeleeWeapon*		weapon = nullptr;
		int					health = 100;

        float decceleration = 18.0f;
        float acceleration = 30.0f; // world units per second
        float maxMoveSpeed = 6.0f; // world units per second
        Vector2 moveDirection = Vector2();

        virtual void onPrePhysicsUpdate();
		virtual void onEnterCollision(Object* objectB);
		virtual void onExitCollision(Object* objectB);

        void setMoveDirection(Vector2 direction);
        void readAnimations();
//        void applyImpulse(Vector2 impulse);

        Animation* a_attack = nullptr;


    private:
};

#endif // PLAYER_H
