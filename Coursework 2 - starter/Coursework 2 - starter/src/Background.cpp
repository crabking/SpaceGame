



#include "..\include\Background.h"
#include <iostream>

const int WINDOW_WIDTH = 800; /*!< DEFINITION FOR WINDOW WIDTH */
const int WINDOW_HEIGHT = 600; /*!< DEFINITION FOR WINDOW WIDTH */

Background::Background()
{

	/// Main Background.
	/** Loads in main background through file. */
	if (!m_backgroundTexture.loadFromFile("./Assets/parallaxbackgound.png"))
	{
		cout << "failed to load space Background Image" << endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setScale(0.05, 0.05);
	m_backgroundTexture.setRepeated(true);

	/// Texture for parallaxing stars.
	/** Loads in main parallaxing stars through file. */
	if (!m_StarsTexture.loadFromFile("./Assets/parallaxspacestars.png"))
	{
		cout << "failed to load space Background Image" << endl;
	}
	m_StarsSprite.setTexture(m_StarsTexture);
	m_StarsSprite.setPosition(0, 0);
	m_StarsSprite.setScale(0.14, 0.14);

	/// Texture for parallaxing stars.
	/** Loads in main parallaxing stars through file. */
	if (!m_StarsTexture2.loadFromFile("./Assets/parallaxspacestars.png"))
	{
		cout << "failed to load space Background Image" << endl;
	}
	m_StarsSprite2.setTexture(m_StarsTexture2);
	m_StarsSprite2.setPosition(40, 0);
	m_StarsSprite2.setScale(0.14, 0.14);

	/// Texture for Small Planets.
	/** Loads in main parallaxing small planets through file. */
	if (!m_SmallPlanetTexture.loadFromFile("./Assets/parallaxspacefarplanets.png"))
	{
		cout << "failed to load space image" << endl;
	}
	m_SmallPlanetSprite.setTexture(m_SmallPlanetTexture);
	m_SmallPlanetSprite.setPosition(0, 0);
	m_SmallPlanetSprite.setScale(0.14, 0.14);

	/// Texture for Small Planets.
	/** Loads in main parallaxing small planets through file. */
	if (!m_SmallPlanetTexture2.loadFromFile("./Assets/parallaxspacefarplanets.png"))
	{
		cout << "failed to load space image" << endl;
	}
	m_SmallPlanetSprite2.setTexture(m_SmallPlanetTexture2);
	m_SmallPlanetSprite2.setPosition(40, 0);
	m_SmallPlanetSprite2.setScale(0.14, 0.14);

	/// Texture for Medium Planets.
	/** Loads in main parallaxing medium planets through file. */
	if (!m_MediumPlanetTexture.loadFromFile("./Assets/parallaxspaceringplanet.png"))
	{
		cout << "failed to load space image" << endl;
	}
	m_MediumPlanetSprite.setTexture(m_MediumPlanetTexture);
	m_MediumPlanetSprite.setPosition(0, 3);
	m_MediumPlanetSprite.setScale(0.14, 0.14);

	/// Texture for Medium Planets.
	/** Loads in main parallaxing medium planets through file. */
	if (!m_MediumPlanetTexture2.loadFromFile("./Assets/parallaxspaceringplanet.png"))
	{
		cout << "failed to load space image" << endl;
	}
	m_MediumPlanetSprite2.setTexture(m_MediumPlanetTexture2);
	m_MediumPlanetSprite2.setPosition(40, 3);
	m_MediumPlanetSprite2.setScale(0.14, 0.14);

	/// Texture for Large Planets.
	/** Loads in main parallaxing Large planets through file. */
	if (m_LargePlanetTexture.loadFromFile("./Assets/parallaxspacebigplanet.png"))
	{
		cout << "failed to load space image" << endl;
	}
	m_LargePlanetSprite.setTexture(m_LargePlanetTexture);
	m_LargePlanetSprite.setPosition(0, 15);
	m_LargePlanetSprite.setScale(0.14, 0.14);

	/// Texture for Large Planets.
	/** Loads in main parallaxing Large planets through file. */
	if (m_LargePlanetTexture2.loadFromFile("./Assets/parallaxspacebigplanet.png"))
	{
		cout << "failed to load space image" << endl;
	}
	m_LargePlanetSprite2.setTexture(m_LargePlanetTexture2);
	m_LargePlanetSprite2.setPosition(-40, 15);
	m_LargePlanetSprite2.setScale(0.14, 0.14);



}

Background::~Background()
{
}


void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_backgroundSprite); //!< Draws background.

	target.draw(m_StarsSprite);  //!< Draws stars sprite.
	target.draw(m_StarsSprite2);  //!< Draws stars sprite 2.

	target.draw(m_SmallPlanetSprite);  //!< Draws smallplanetsprite.
	target.draw(m_SmallPlanetSprite2); //!< Draws smallplanetsprite 2.

	target.draw(m_MediumPlanetSprite); //!< Draws mediumplanetsprite.
	target.draw(m_MediumPlanetSprite2); //!< Draws mediumplanetsprite 2 .

	target.draw(m_LargePlanetSprite);  //!< Draws large planetsprite.
	target.draw(m_LargePlanetSprite2); //!< Draws large planetsprite 2.

}

void Background::update(sf::View& gameView, float elapsedTime)
{

	/// Moves stars sprites on screen.
	/** The idea of these movements is to make the background look parallaxing. */
	m_StarsSprite.move(-0.01f, 0.f);
	if (m_StarsSprite.getPosition().x < -(40)) //! Had to fiddle around with numbers to find the width? It might be  cause of scaling...
	{
		m_StarsSprite.setPosition(0, 0); //! Sets the new position of the sprite after it goes to a position
	}

	m_StarsSprite2.move(-0.01f, 0.f);
	if (m_StarsSprite2.getPosition().x < -(0)) //! Had to fiddle around with numbers to find the width? It might be  cause of scaling...
	{
		m_StarsSprite2.setPosition(40, 0); //! Sets the new position of the sprite after it goes to a position
	}

	//!< SMALL PLANETS
	m_SmallPlanetSprite.move(-0.03f, 0.f);
	if (m_SmallPlanetSprite.getPosition().x < -(40)) //! Had to fiddle around with numbers to find the width? It might be  cause of scaling...
	{
		m_SmallPlanetSprite.setPosition(0, 0); //! Sets the new position of the sprite after it goes to a position
	}

	m_SmallPlanetSprite2.move(-0.03f, 0.f);
	if (m_SmallPlanetSprite2.getPosition().x < -(0)) //! Had to fiddle around with numbers to find the width? It might be  cause of scaling...
	{
		m_SmallPlanetSprite2.setPosition(40, 0); //! Sets the new position of the sprite after it goes to a position
	}

	//!< MEDIUM PLANETS
	m_MediumPlanetSprite.move(-0.06f, 0.f); // moves the background
	if (m_MediumPlanetSprite.getPosition().x < -(40)) //! Had to fiddle around with numbers to find the width? It might be  cause of scaling...
	{
		m_MediumPlanetSprite.setPosition(0, 3); //! Sets the new position of the sprite after it goes to a position
	}

	m_MediumPlanetSprite2.move(-0.06f, 0.f); // moves the background
	if (m_MediumPlanetSprite2.getPosition().x < -(0)) //! Had to fiddle around with numbers to find the width? It might be  cause of scaling...
	{
		m_MediumPlanetSprite2.setPosition(40, 3); //! Sets the new position of the sprite after it goes to a position
	}

	//!< LARGE PLANETS
	m_LargePlanetSprite.move(-0.08f, 0.f); // moves the background 
	if (m_LargePlanetSprite.getPosition().x < -(40)) //! Had to fiddle around with numbers to find the width? It might be  cause of scaling...
	{
		m_LargePlanetSprite.setPosition(0, 15); //! Sets the new position of the sprite after it goes to a position
	}

	m_LargePlanetSprite2.move(-0.08f, 0.f); // moves the background
	if (m_LargePlanetSprite2.getPosition().x < -(0)) //! Had to fiddle around with numbers to find the width? It might be  cause of scaling...
	{
		m_LargePlanetSprite2.setPosition(40, 15);  //! Sets the new position of the sprite after it goes to a position
	}

}
