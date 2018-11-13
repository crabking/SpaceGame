/*! \file Game.h
The main game loop.

This class draws, sets the view, updates the screen and processes key presses and more. This class holds all the game logic,
*/

#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>

#include "Line.h"
#include "Bike.h"
#include "Background.h"
#include "BlockShape.h"

#include "ScreenText.h"


using namespace std;

class Game : public sf::Drawable
{
private:
	b2World * m_world; /*!< the world	*/

	sf::Music music; /*!< SF: music 	*/
	
	sf::View gameView; /*!< the game view 	*/
	sf::View textView; /*!< the UI view	 */
	sf::View backgroundView; /*!< the background view 	*/

	int cameraDimensionsX = 32; /*!< dimensions of camera variables	*/
	int cameraDimensionsY = 24; /*!< dimensions of camera variables	*/
	
	Line m_line; /*!< defining the Line object 	*/
	Bike m_bike; /*!< defining the bike object 	*/
	//BlockShape m_blockshape; /*!< defining the block object 	*/
	//Bridge m_bridge; /*!< defining the bridge object 	*/
	Background m_background; /*!< defining the background object  	*/
	ScreenText m_titleScreenText; /*!< defining the UI text object 	*/
	ScreenText m_playerScoreText; /*!< defining the UI text object 	*/
	ScreenText m_playNowText; /*!< defining the UI text object 	*/
	ScreenText m_controlText; /*!< defining the UI text object 	*/
	ScreenText m_controlText2; /*!< defining the UI text object 	*/
	ScreenText m_controlText3; /*!< defining the UI text object 	*/



	bool l_isplaying = false;  /*!< Bool for checking if playing or in menu 	*/
	bool m_leftDown; /*!< boolean checking if left button is down	*/
	bool m_rightDown; /*!< boolean checking if right button is down	*/
	bool m_leftDownBike; /*!< boolean checking if A button is down	*/
	bool m_rightDownBike; /*!< boolean checking if  D button is down	*/
	bool m_BoosterDown; /*!< boolean booster variable	*/

	int playerLives = 1; /*!< currently hold the states of which the player is playing or not	*/
	int iPlayerScore = 0; /*!< currently hold the states of which the player is playing or not	*/



public:
	Game(); // Constructor
	~Game(); // Destructor

	//! Draw function
	/*!
	param a the view
	param b the position
	param c the size
	param d the radius
	param e the orientation
	*/
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	//! Void function that Updates the background
	/*!
	param a the gameView passed in
	*/
	void update(float timestep);


	//! Void function precesses key presses
	/*!
	param a sf::Keyboard::Key
	*/
	void processKeyPress(sf::Keyboard::Key keyPressed);

	//! Void function processes key released
	/*!
	param a sf::Keyboard::Key
	*/
	void processKeyRelease(sf::Keyboard::Key keyReleased);
	

	//! Void function to play music
	/*!
	param a 3d position for music
	param b the pitch 
	param c the volume
	param d the boolean which tells it to loop or not
	*/
	void PlayMusic(sf::Vector3f(musicpos), float pitch, float volume, bool loop);

	//! Void function processes key released
	/*!
	handles the properties of the ike
	*/
	void BikePropertiesUpdates();
};