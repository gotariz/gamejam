#include "Player.h"

Player::Player(int id) : Object(id)
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::setMoveDirection(Vector2 direction)
{
    moveDirection.set(direction);
}

void Player::onPrePhysicsUpdate()
{
    if (moveDirection.getMagnitude() != 0)
    {
        m_physicsObject->SetLinearDamping(0);
        Vector2 currentVelocity = Vector2(m_physicsObject->GetLinearVelocity());
        Vector2 velocity = currentVelocity + (moveDirection * (acceleration * gdata.m_timeDelta));

        if (velocity.getMagnitude() > maxMoveSpeed) {
            velocity.setMagnitude(maxMoveSpeed);
        }

        setLinearVelocity(velocity);
    }
    else
    {
        m_physicsObject->SetLinearDamping(decceleration);
    }
}

void Player::onEnterCollision(Object* objectB)
{
	cout << "player enter" << endl;
}

void Player::onExitCollision(Object* objectB)
{
	cout << "player exit" << endl;
}



