
#include "..\include\Bike.h"

#include <Box2D/Box2D.h>

#include <SFML/Graphics.hpp>

#include "PhysicalObject.h"

#define DEG2RAD 0.017453f
#define RAD2DEG 57.29577f

using namespace std;

Bike::Bike(b2World* m_world, const sf::View& view, const sf::Vector2f& position, const sf::Vector2f& size, const float kfradius, const float kforientation)
{


	/// Box2d Definitions
	/** defining the body, the circle shape and the fixture, 
	sets the density, friction and restitution of the body*/
	b2BodyDef l_bodyDef;
	b2CircleShape l_circleShape;
	b2FixtureDef l_fixtureDef;

	l_fixtureDef.density = 1.0;
	l_fixtureDef.friction = 3;
	l_fixtureDef.restitution = 0.01;

	/// First Wheel Body
	/** defining the body, sets the body to dynamic, 
	sets the bodys position in the world, 
	creates the body in the world and creates the fixture*/
	l_bodyDef.type = b2_dynamicBody;
	l_bodyDef.position.Set(position.x, position.y); // Ball1 Pos 10,5

	m_wheelBodyOne = m_world->CreateBody(&l_bodyDef);
	l_circleShape.m_radius = (kfradius); //!< 0.5

	l_fixtureDef.shape = &l_circleShape;
	m_wheelBodyOne->CreateFixture(&l_fixtureDef);

	/// Second wheel Body
	/** defining the body, sets the body to dynamic, sets the bodys position in the world,
	creates the body in the world and creates the fixture*/
	l_bodyDef.type = b2_dynamicBody;
	l_bodyDef.position.Set(position.x + 3, position.y); //!< Ball2 Posx + 3, 5

	m_wheelBodyTwo = m_world->CreateBody(&l_bodyDef);
	l_circleShape.m_radius = (kfradius); //!< 0.5

	l_fixtureDef.shape = &l_circleShape;
	m_wheelBodyTwo->CreateFixture(&l_fixtureDef);

	/// Bike body
	/** defining the body, sets body to dynamic, sets its orientation, sets its shape,
	sets its position, creates the body in the world, creates the fixture*/
	b2PolygonShape l_polyShape;
	l_bodyDef.type = b2_dynamicBody;
	l_bodyDef.angle = kforientation * DEG2RAD;

	l_polyShape.SetAsBox(size.x, size.y); //!< a 2x1 rectangle
	l_bodyDef.position.Set(position.x + 1.2, position.y - 1); //!< Polyong Posx + 1.2 Posy - 1, 11.2, 4 - Poly SetasBox, 2, 1

	m_bikeBody = m_world->CreateBody(&l_bodyDef);
	m_bikeBody->CreateFixture(&l_fixtureDef); //!< add a fixture to the body


	/// Revolute Joint for first wheel
	/** initializes the joints, sets collision to true, 
	anchors the joints, and creates the joint in the world*/
	revoluteJointDef.bodyA = m_bikeBody;
	revoluteJointDef.bodyB = m_wheelBodyOne;
	revoluteJointDef.collideConnected = true;
	revoluteJointDef.localAnchorA.Set(-2.5, 0.5);
	revoluteJointDef.localAnchorB.Set(0, 0);

	m_world->CreateJoint(&revoluteJointDef);

	/// Revolute Joint for the second wheel
	/** initializes the joints, sets collision to true, 
	anchors the joints, and creates the joint in the world*/
	revoluteJointDef.bodyA = m_bikeBody;
	revoluteJointDef.bodyB = m_wheelBodyTwo;
	revoluteJointDef.collideConnected = true;
	revoluteJointDef.localAnchorA.Set(2.5, 0.5);
	revoluteJointDef.localAnchorB.Set(0, 0);


	m_world->CreateJoint(&revoluteJointDef);


}

void Bike::BikeTextures(const sf::Vector2f& sfmlposition, const sf::Vector2f& sfmlsize, const float sfmlradius)
{

	/// SFML for first wheel
	/** sets radius, sets position, sets origin, loads in the image from file, sets the texture*/
	m_wheelOne.setRadius(sfmlradius); //<! 0.75
	m_wheelOne.setPosition(sfmlposition.x, sfmlposition.y); //<! 10, 5
	m_wheelOne.setOrigin(m_wheelOne.getGlobalBounds().width / 2, m_wheelOne.getGlobalBounds().width / 2);
	m_WheelTexture1.loadFromFile("./Assets/terrywheel.png");
	m_wheelOne.setTexture(&m_WheelTexture1);

	/// SFML for second wheel
	/** sets radius, sets position, sets origin, loads in the image from file, sets the texture*/
	m_wheelTwo.setRadius(sfmlradius); //<! 0.75
	m_wheelTwo.setPosition(sfmlposition.x +3, sfmlposition.y) ;  //<! 13, 5
	m_wheelTwo.setOrigin(m_wheelOne.getGlobalBounds().width / 2, m_wheelOne.getGlobalBounds().width / 2);
	m_WheelTexture2.loadFromFile("./Assets/terrywheel.png");
	m_wheelTwo.setTexture(&m_WheelTexture2);

	/// SFML for bike BODY
	/** sets radius, sets position, sets origin, loads in the image from file, sets the texture*/
	m_bikeShape.setSize(sf::Vector2f(sfmlsize.x, sfmlsize.y));  //<! vector2f 6,2
	m_bikeShape.setPosition(sfmlposition.x, sfmlposition.y +1); //<! 10, 4
	m_bikeShape.setOrigin(3, 1);  //<! 3,1
	m_BodyTexture.loadFromFile("./Assets/Body.png");
	m_bikeShape.setTexture(&m_BodyTexture);
}

Bike::~Bike()
{
}

void Bike::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_wheelOne); //! draw wheel1 
	target.draw(m_wheelTwo); //! draw wheel2
	target.draw(m_bikeShape); //! draws bike
}

void Bike::update(sf::View& gameView)
{

	/// Setting position of first wheel to BOX2d Body
	/** gets position, sets position, checks rotation with getangle, then sets rotation*/
	b2Vec2 pos = m_wheelBodyOne->GetPosition();
	m_wheelOne.setPosition(pos.x, pos.y);

	float l_wheel1Rot = m_wheelBodyOne->GetAngle();
	m_wheelOne.setRotation(l_wheel1Rot * RAD2DEG);

	/// Setting position of second wheel to BOX2d Body
	/** gets position, sets position, checks rotation with getangle, then sets rotation*/
	b2Vec2 pos2 = m_wheelBodyTwo->GetPosition();
	m_wheelTwo.setPosition(pos2.x, pos2.y);

	float l_wheel2Rot = m_wheelBodyTwo->GetAngle();
	m_wheelTwo.setRotation(l_wheel2Rot * RAD2DEG);

	/// Setting position of body wheel to BOX2d Body
	/** gets position, sets position, checks rotation with getangle, then sets rotation*/
	b2Vec2 pos3 = m_bikeBody->GetPosition();
	m_bikeShape.setPosition(pos3.x, pos3.y);

	float l_bikerot = m_bikeBody->GetAngle();
	m_bikeShape.setRotation((l_bikerot * RAD2DEG));

	/// Function call for camera
	/** Setting camera relative to the player*/
	followCamera(gameView);

}

void Bike::Throttle()
{
	/// Wheel torque
	/** makes the wheels spin if a boolean is true*/
	m_wheelBodyOne->ApplyTorque(15.f, true);
	m_wheelBodyTwo->ApplyTorque(15.f, true);
}

void Bike::Decelerate()
{
	/// Wheel torque
	/** makes the wheels spin anticlockwise if a boolean is true*/
	m_wheelBodyOne->ApplyTorque(-15.f, true);
	m_wheelBodyTwo->ApplyTorque(-15.f, true);
}


void Bike::BikeBodyTorqueClockwise()
{
	/// Wheel torque
	/** makes the wheels spin if a boolean is true*/
	m_bikeBody->ApplyTorque(100.f, true);

}

void Bike::BikeBodyTorqueAntiClockwise()
{
	/// Wheel torque
	/** makes the wheels spin anticlockwise if a boolean is true*/
	m_bikeBody->ApplyTorque(-100.f, true);

}


void Bike::followCamera(sf::View& gameView)
{

	/// Sets gameview to follow the player
	/** */
	b2Vec2 ballPos = m_wheelBodyOne->GetPosition(); //! gets position of wheel body
	gameView.setCenter(m_bikeBody->GetPosition().x, m_bikeBody->GetPosition().y); //! sets the centre to the position
}

void Bike::Jump()
{
	/// Force application
	/** sets a linear velocity to the wheels */
	m_wheelBodyOne->SetLinearVelocity(b2Vec2(0, 15));
	m_wheelBodyTwo->SetLinearVelocity(b2Vec2(0, 15));

}


void Bike::Boosters()
{
	/// Wheel torque
	/** makes the wheels spin if a boolean is true*/
	m_wheelBodyOne->ApplyTorque(5000.f, true);
	m_wheelBodyTwo->ApplyTorque(5000.f, true);

}

float Bike::BikeGetXPos()
{

	return m_bikeBody->GetPosition().x; //!< returns the position of the bike in the x */
}

float Bike::BikeGetYPos()
{

	return m_bikeBody->GetPosition().y; //!< returns the position of the bike in the y */
}
