
#include "ScreenText.h"



ScreenText::ScreenText()
{
	font.loadFromFile("Assets/fonts/upheavtt.TTF"); //! load in font
	
	UIText.setFont(font); //! sets font
	
}

ScreenText::~ScreenText()
{
}

void ScreenText::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(UIText); //! draws  UI
}


void ScreenText::setStringText(string text)
{
	UIText.setString( text ); //! sets string
}

void ScreenText::setStringPosition(sf::Vector2f pos) 
{
	UIText.setPosition(pos); //! sets pos
}


void ScreenText::setStringCharacterSize(float characterSize) 
{
	UIText.setCharacterSize(characterSize); //! sets character size of string
}
