#include "PhysicsFactory.h"

PhysicsFactory::PhysicsFactory(b2World* world) : m_world(world)
{
    //ctor
}

PhysicsFactory::~PhysicsFactory()
{
    //dtor
}

b2Body* PhysicsFactory::createPlayer(float x, float y, void* userPointer)
{
    // create temp physics player
    b2CircleShape shape;
    shape.m_radius = 0.5;

    b2PolygonShape box;
    box.SetAsBox(1,2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape        = &shape;
    fixtureDef.density      = 1;
    fixtureDef.restitution  = 0.0f;
	fixtureDef.friction     = 0.25f;

	fixtureDef.filter.categoryBits = CF_PLAYER;     // what the object is
	fixtureDef.filter.maskBits = CF_ALL;        // what the object collides with

	b2BodyDef bodyDef;
	bodyDef.type            = b2_dynamicBody;
    bodyDef.fixedRotation   = true;

    bodyDef.position.Set(x,y);

    b2Body* body = m_world->CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);
	body->SetLinearDamping(0);
	body->SetBullet(true);
	body->SetSleepingAllowed(false);

	return body;
}

b2Body* PhysicsFactory::createKinematicPlayer(float x, float y, void* userPointer)
{
    b2CircleShape shape;
    shape.m_radius = 0.5;

    b2PolygonShape polygon_shape;
    polygon_shape.SetAsBox(0.05f, 1.0f, b2Vec2 (0.0f, 0.0f), -15 * DEGTORAD);

    b2FixtureDef fixtureDef;
    fixtureDef.shape        = &shape;
    fixtureDef.density      = 1.0f;
    fixtureDef.restitution  = 0.0f;
	fixtureDef.friction     = 0.0f;
	fixtureDef.isSensor     = true;

	fixtureDef.filter.categoryBits = CF_SENSOR;     // what the object is
	fixtureDef.filter.maskBits     = CF_ALL;        // what the object collides with

	b2BodyDef bodyDef;
	//bodyDef.type            = b2_kinematicBody;
	bodyDef.type            = b2_dynamicBody;
    bodyDef.fixedRotation   = true;
    bodyDef.angularDamping  = 0.0f;
    bodyDef.linearDamping   = 0.0f;
    bodyDef.position.Set(x,y);
    bodyDef.allowSleep      = false;

    b2Body* body = m_world->CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);
	body->SetBullet(true);

	return body;
}

b2Body* PhysicsFactory::createTestShape(void* userPointer)
{

    //gz::print_value("-540 mod 360 = ", -540.8 % 360.8);
    //=========================================================================
    // FIXTURE 1
    b2Vec2 v1[4];
    v1[0].Set(21,156);
    v1[1].Set(30,156);
    v1[2].Set(30,31);
    v1[3].Set(21,31);

    b2PolygonShape polygon;
    polygon.Set(getRealCoords(v1,4),4);

    b2FixtureDef f1;
    f1.shape        = &polygon;
    f1.isSensor     = true;
    f1.density      = 1.0f;
    //=========================================================================
    // FIXTURE 2
    b2Vec2 v2[4];
    v2[0].Set(21,31);
    v2[1].Set(30,31);
    v2[2].Set(41,7);
    v2[3].Set(10,7);

    b2PolygonShape p2;
    p2.Set(getRealCoords(v2,4),4);

    b2FixtureDef f2;
    f2.shape        = &p2;
    f2.isSensor     = true;
    f2.density      = 1.0f;
    //=========================================================================
    // FIXTURE 3
    b2Vec2 v3[5];
    v3[0].Set(0,35);
    v3[1].Set(13,40);
    v3[2].Set(21,31);
    v3[3].Set(10,7);
    v3[4].Set(0,1);

    b2PolygonShape p3;
    p3.Set(getRealCoords(v3,5),5);

    b2FixtureDef f3;
    f3.shape        = &p3;
    f3.isSensor     = true;
    f3.density      = 1.0f;
    //=========================================================================
    // FIXTURE 4
    b2Vec2 v4[5];
    v4[0].Set(0,35);
    v4[1].Set(3,46);
    v4[2].Set(13,59);
    v4[3].Set(17,48);
    v4[4].Set(13,40);

    b2PolygonShape p4;
    p4.Set(getRealCoords(v4,5),5);

    b2FixtureDef f4;
    f4.shape        = &p4;
    f4.isSensor     = true;
    f4.density      = 1.0f;
    //=========================================================================
    // FIXTURE 5
    b2Vec2 v5[5];
    v5[0].Set(30,31);
    v5[1].Set(38,40);
    v5[2].Set(51,35);
    v5[3].Set(51,1);
    v5[4].Set(41,7);

    b2PolygonShape p5;
    p5.Set(getRealCoords(v5,5),5);

    b2FixtureDef f5;
    f5.shape        = &p5;
    f5.isSensor     = true;
    f5.density      = 1.0f;
    //=========================================================================
    // FIXTURE 6
    b2Vec2 v6[5];
    v6[0].Set(34,48);
    v6[1].Set(38,59);
    v6[2].Set(48,46);
    v6[3].Set(51,35);
    v6[4].Set(38,40);

    b2PolygonShape p6;
    p6.Set(getRealCoords(v6,5),5);

    b2FixtureDef f6;
    f6.shape        = &p6;
    f6.isSensor     = true;
    f6.density      = 1.0f;
    //=========================================================================

    b2BodyDef polygon_bd;

    polygon_bd.type = b2_kinematicBody;
    polygon_bd.bullet = true;
    b2Body* polygon_body = m_world->CreateBody(&polygon_bd);
    polygon_body->CreateFixture(&f1);
    polygon_body->CreateFixture(&f2);
    polygon_body->CreateFixture(&f3);
    polygon_body->CreateFixture(&f4);
    polygon_body->CreateFixture(&f5);
    polygon_body->CreateFixture(&f6);

	return polygon_body;
}

b2Vec2* PhysicsFactory::getRealCoords(b2Vec2 vertices[], int count)
{
    for (int i = 0; i < count; ++i) {

        Vector2 vec = Vector2(vertices[i]);
        vec.x -= 26;
        vec.y -= 143;

        vec.x *= 0.013;
        vec.y *= 0.013;

        //vec.x *= -1;
        vec.y *= -1;

        vertices[i].Set(vec.x,vec.y);

    }
    return vertices;
}
























