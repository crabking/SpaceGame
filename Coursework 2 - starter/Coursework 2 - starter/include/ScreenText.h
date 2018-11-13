
/*! \file ScreenText.h
Class that draws text to the screen


This class is currently supposed to keep track of score and win conditions etc.

This class was created to give a nice OO design and reuseability for drawing text to the screen,
such as player score and menu text.
*/
#pragma once

#include <SFML/Graphics.hpp>

using namespace std;

class ScreenText : public sf::Drawable
{
private:
	sf::Font font; //! creates font

	sf::Text UIText; //! need to be in different view

	sf::Text MenuText; //! need to be in different view

	int iPlayerScore = 1; /*!< Holds Playe Score */




public:
	//! Default Constructor
	/*!
	*/
	ScreenText(); // Constructor

	//! Destructor
	/*!
	 */
	~ScreenText();

	//! Draws the background
	/*!
	param a a passed in RenderTarget
	param b a passed in RenderStates
	*/
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;



	//! Void function outputs the lose condition text
	/*!*/
	void setStringText(string text);

	//! Void to set charactersize
	/*!*/
	void setStringCharacterSize(float characterSize);

	//! Void function outputs the lose condition text
	/*!*/
	void setStringPosition(sf::Vector2f pos);

};