#ifndef OBJECT_H
#define OBJECT_H

#include "general.h"
#include "system/GameData.h"
#include "scene/Camera.h"
#include "video/AnimatedImage.h"

class Object
{
    public:
        Object(int id = -1);
        virtual ~Object();

    protected: // variables
        int                     m_id = -1;
        b2Body*                 m_physicsObject = nullptr;
        Object*                 m_parent = nullptr;
        std::vector<Object*>    m_children;

    public: // variables
        //sf::Sprite*             m_image = nullptr;
        AnimatedImage*			m_image = nullptr;
        std::string             m_name = "";

        bool                    m_lockPosition = false;
        bool                    m_lockRotation = false;
        bool                    m_independent = false;


        // this should be private and used through functions
        std::vector<Object*>    m_collidingObjects;

    public: //events
        virtual void onCreate();
        virtual void onDestroy();
        virtual void onUpdate();
        virtual void onPrePhysicsUpdate();
        virtual void onPostPhysicsUpdate();
        virtual void onCollision();
        virtual void onEnterCollision(Object* objectB);
        virtual void onExitCollision(Object* objectB);
        virtual void onDraw();

    public: // utilities
        virtual void rotateAround(float angle, Vector2 origin);
        virtual void rotate(float angle);
        virtual void translate(Vector2 delta);
        virtual void translateChildren(Vector2 delta);

        float   parentPrimalRotation = 0;
        Vector2 parentPrimalPosition = Vector2(0.3f,0.0f);
        virtual void syncWithParent();
        virtual void syncChildren();

        // setters
        virtual void addChild(Object* child);
        virtual void moveTo(Vector2 newPosition);
        virtual void moveDistance(Vector2 delta);
        virtual void moveAbsoluteDistance(Vector2 delta);

        virtual void setPosition(Vector2 newPosition);
        virtual void setRotation(float angle);
        virtual void setAbsolutePosition(Vector2 newPosition);
        virtual void setAbsoluteRotation(float newAngle);

        virtual void setPhysicsObject(b2Body* physicsObject);
        virtual void applyImpulse(Vector2 impulseForce);
        virtual void setLinearVelocity(Vector2 linearVelocity);

        // getters
        virtual Vector2 getPosition();
        virtual float   getRotation();
        virtual Vector2 getAbsolutePosition();
        virtual float   getAbsoluteRotation();

        virtual int     getID();


};

#endif // OBJECT_H
