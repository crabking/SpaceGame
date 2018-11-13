#include "..\include\Joint.h"
#include "..\include\Bike.h"


Joint::Joint() {



}; // Constructor


Joint::Joint(b2World * m_world, b2Body * bodyA, b2Body * bodyB)
{
	//m_ballBody = static_cast<Bike*>(bodyA->GetUserData());
	//m_ballBody2 = static_cast<Bike*>(bodyA->GetUserData());

}

Joint::~Joint()
{
}

void Joint::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}

void Joint::update(sf::View & gameView)
{
}
