/*! \file Line.h
This class draws and sets the line in the world.

This line is specifically used for acting as the ground  which the player will drive around on with the bike.
This class takes x amount of floats and sets them as vertices, it also creates a box2d chain object and draws an sfml line
.the positions are loaded in from file to make it kind of easier to construct the level.
the file reads two vertices and sets them as the line and draws them in random colour to give it a funky space look.


*/

#pragma once




#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "..\include\LevelLoader.h"


using namespace std;

class Line : public sf::Drawable
{
private:

	
	sf::VertexArray m_groundLine; //!< line of sf shape


	b2Body * m_lineBody; //!< pointer to lnebody
	


public:
	//! Default Constructor
	/*!
	*/
	Line(){}; 

	//! Main constructor
	/*!
	param a gameworld, param b float v for vector point
	*/
	Line(b2World * m_world, const float v);

	//! Destructor
	/*!
	*/
	~Line();

	//! Void draw 
	/*!
	param a the renderwindow, param b render states
	*/
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};