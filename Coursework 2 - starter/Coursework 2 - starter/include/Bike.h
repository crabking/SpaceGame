
/*! \file Bike.h
The bike class that essentially builds a bike from different bodies and sfml drawings.


This class is not very object oriented in terms of reuseability. On the contrary its a 
very complex class with many different things added to it and is not really meant for building differently.

If I where to do different type of player cars I would probably restructure it a little bit in terms of loading in sprites from file etc.

*/

#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "PhysicalObject.h"

#define DEG2RAD 0.017453f;
#define RAD2DEG 57.29577f;



using namespace std;

class Bike : public sf::Drawable, public PhysicalObject
{
private:

	sf::Texture m_BodyTexture;	 /*!< Texture of the bike body	*/
	sf::Texture m_WheelTexture1; /*!< texture of the first wheel	*/
	sf::Texture m_WheelTexture2; /*!< texture of the second wheel	*/

	sf::CircleShape m_wheelOne;     /*!< variable for SFML shape of wheel	*/
	sf::CircleShape m_wheelTwo;     /*!< variable for SFML shape of wheel 2	*/
	sf::RectangleShape m_bikeShape; /*!< variable fo the SFML of the bikebody	*/


	b2Body * m_wheelBodyOne; /*!< variable for the BOX2D body of the first wheel	*/
	b2Body * m_wheelBodyTwo; /*!< variable for the BOX2D body of the second wheel	*/
	b2Body * m_bikeBody;  /*!< variable for the BOX2D body of the bike	*/

	b2DistanceJointDef jointDef; /*!< variable for BOX2D distance Joint */
	b2RevoluteJointDef revoluteJointDef;  /*!< variable BOX2D revolute Joint */

	int iJumpTimeOut; /*!< integer for not letting you jump ... still under constrution */



public:
	//! Default Constructor
	/*!
	*/
	Bike() {};

	//! Main Constructor
	/*!
	param a the view
	param b the position
	param c the size
	param d the radius
	param e the orientation
	*/
	Bike(b2World * m_world, const sf::View& view, const sf::Vector2f& position, const sf::Vector2f &size, const float kfradius, const float kforientation);

	//! Destructor
	/*!
	*/
	~Bike();

	//! Draws the bike textures
	/*!
	*/
	void BikeTextures(const sf::Vector2f& sfmlposition, const sf::Vector2f& sfmlsize, const float sfmlradius);

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

	//! Void function that Throttle to spin the wheels
	/*!*/
	void Throttle();

	//! Void function that Decelerate to spin the wheels other direction
	/*!*/
	void Decelerate();

	//! Boosters to boost the speed of the bike
	/*!*/
	void Boosters();

	//! Void function that torque to spin the bike body in the air clockwise
	/*!*/
	void BikeBodyTorqueClockwise();

	//! Void function that torque to spin the bike body in the air anticlockwise
	/*!*/
	void BikeBodyTorqueAntiClockwise();

	//! Void function that follows the bike with the camera
	/*!
	param a the gameView passed in
	*/
	void Bike::followCamera(sf::View& gameView);

	//! Void function that makes the bike jump
	/*!*/
	void Bike::Jump();

	//! returns a float to get the xPosition of the bike
	/*!*/
	float Bike::BikeGetXPos();

	//! returns a float to get the yPosition of the bike
	/*!*/
	float Bike::BikeGetYPos();
};