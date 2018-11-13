/*! \file BlockShape.h
This class has some simple block body and drawing.

it currently draws and creates one block in the world and updates it.

This class was created to make some building blocks that would act as obstacles or similiary,
due to other issues I had to pause this part of the project and just leave it as an OO class that
has a decent block shape with reuseability when I would need it ni the future.


*/

#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "PhysicalObject.h"

#define DEG2RAD 0.017453f;
#define RAD2DEG 57.29577f;




using namespace std;

class BlockShape : public sf::Drawable, public PhysicalObject
{

private:

	sf::RectangleShape m_blockShape; /*!< defines a block shape	*/




	b2Body * m_blockBody; /*!< defines a block body	*/


public:

	//! Default constructor
	/*!
	*/
	BlockShape() {};

	//! Main Constructor
	/*!
	param a the view
	param b the position
	param c the size
	param d the orientation
	*/
	BlockShape(b2World * m_world, const sf::View& view, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);

	//! Destructor
	/*!
	*/
	~BlockShape();

	//! Draws the background
	/*!
	param a a passed in RenderTarget
	param b a passed in RenderStates
	*/
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//! Void function that Updates the background
	/*!
	param a the gameView passed in
	*/
	void update(sf::View& gameView);

};

