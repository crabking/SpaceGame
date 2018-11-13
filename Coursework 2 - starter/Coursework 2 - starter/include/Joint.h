
#pragma once
/*!
\file main.cpp
\brief Don't forget your doxygen comments!
*/

#include <Box2D/Box2D.h>

#include <SFML/Graphics.hpp>

#include "PhysicalObject.h"

#define DEG2RAD 0.017453f;
#define RAD2DEG 57.29577f;

using namespace std;

class Joint : public sf::Drawable, public PhysicalObject
{
private:

	//sfml shape
	//sf::CircleShape m_ball;
	//sfml shape
	//sf::CircleShape m_ball2;

	//b2d shape
	//b2CircleShape circle;

	//b2Body * m_ballBody;
	//b2Body * m_ballBody2;



public:
	Joint() {}; // Constructor
	Joint( b2World * m_world, b2Body * bodyA, b2Body * bodyB); // Constructor
	~Joint(); // Destructor

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::View& gameView);

	
	void Joint::followCamera(sf::View& gameView);
};