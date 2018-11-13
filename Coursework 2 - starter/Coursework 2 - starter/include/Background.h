/*!\file Background.h

This class builds a fixed background, and because of that it doesnt really pass many arguments
or have any special reuseability to it, its kind of just a seperate class that builds once instance of a background.

If I did not struggle with some things I would spend time passing these backgrounds in thorugh file.

*/

#pragma once

#include <SFML/Graphics.hpp>



using namespace std;

class Background : public sf::Drawable
{
private:


	sf::Sprite m_backgroundSprite;		/*!<  background sprite variable // background static   */
	sf::Texture m_backgroundTexture;	/*!<  background texture variable */

	sf::Sprite m_StarsSprite;			/*!< parallaxing stars sprite variable	*/
	sf::Sprite m_StarsSprite2;			/*!< parallaxing stars sprite variable 2*/

	sf::Sprite m_SmallPlanetSprite;		/*!<  parallaxing small planets sprite variable	*/
	sf::Sprite m_SmallPlanetSprite2;	/*!<  parallaxing small planets sprite variable 2*/

	sf::Sprite m_MediumPlanetSprite;	/*!<  parallaxing medium planets sprite variable */
	sf::Sprite m_MediumPlanetSprite2;	/*!<  parallaxing medium planets sprite variable 2 */

	sf::Sprite m_LargePlanetSprite;		/*!<  parallaxing large planet sprite variable	*/
	sf::Sprite m_LargePlanetSprite2;	/*!<  parallaxing large planet sprite variable 2 */



	sf::Texture m_StarsTexture;			/*!< parallaxing stars texture variable	*/
	sf::Texture m_StarsTexture2;		/*!< parallaxing stars texture variable 2 */

	sf::Texture m_SmallPlanetTexture;	/*!< parallaxing small planets texture variable	*/
	sf::Texture m_SmallPlanetTexture2;	/*!< parallaxing small planets texture variable 2*/

	sf::Texture m_MediumPlanetTexture;  /*!< parallaxing medium planets texture variable*/
	sf::Texture m_MediumPlanetTexture2;	/*!< parallaxing medium planets texture variable 2*/

	sf::Texture m_LargePlanetTexture;	/*!< parallaxing large planet texture variable*/
	sf::Texture m_LargePlanetTexture2;	/*!< parallaxing large planet texture variable 2*/

public:

	//! Default constructor
	/*!
	*/
	Background(); // Constructor

	//! Destructor
	/*!
	*/
	~Background(); 

	//! Draws the background
	/*!
	param a a passed in RenderTarget
	param b a passed in RenderStates
	*/
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//! Updates the background
	/*!
	param a the gameView passed in
	param b a float that updates the timeflow
	*/
	void update(sf::View& gameView, float elapsedTime);

};