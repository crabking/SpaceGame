

#include "Game.h"


using namespace std;




Game::Game()
{


	/// Open music from file
	/** finds hte file and opens it or outputs error*/
	if (!music.openFromFile("./Assets/music/powerglove.ogg"))
	{
		cout << "error..." << endl;
	}

	/// Music settings
	/** sets the 3d pos of hte msuic, the pitch volume and repeat */
	PlayMusic(sf::Vector3f(1, 10, 0), 1, 3, true);
	music.play();//! Play it.

	/// View Settings
	/** Sets the texview centre.
	sets the gameview centre.
	sets the size of the view.
	zooms it out by double.
	sets the backgroundview centre.
	sets the size of the bakcground view. */
	textView.setCenter(sf::Vector2f(450, 450));
	gameView.setCenter(sf::Vector2f(cameraDimensionsX / 2.0f, cameraDimensionsY / 2.0f));
	gameView.setSize(sf::Vector2f(cameraDimensionsX, cameraDimensionsY)); //!<set dimensions of screen
	
	backgroundView.setCenter(sf::Vector2f(cameraDimensionsX / 2.0f, cameraDimensionsY / 2.0f));
	backgroundView.setSize(sf::Vector2f(cameraDimensionsX, cameraDimensionsY)); //!<set dimensions of screen


	m_world = new b2World(b2Vec2(0.f, 9.81f));  //!< sets world and gravity
	m_bike = Bike(m_world, gameView, sf::Vector2f(10, 5), sf::Vector2f(2, 1), 0.5, 0); //!<position, sizeof rect, radius, orientation
	m_bike.BikeTextures(sf::Vector2f(10, 5), sf::Vector2f(6, 2), 0.75); //!<position, sizeof rect, radius,
	m_line = Line(m_world, 1000); //!< passes world and vertices

}

Game::~Game()
{
}


void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	
	if (l_isplaying == true)
	{
		target.clear();
		target.setView(backgroundView);
		target.draw(m_background);

		target.setView(gameView); // sets the view
		target.draw(m_line);
		target.draw(m_bike);

		target.setView(textView);
		target.draw(m_playerScoreText);
	}
	
	if (l_isplaying == false)
	{
		target.clear();
		target.setView(backgroundView);
		target.draw(m_background);

		target.setView(textView);
		target.draw(m_titleScreenText);
		target.draw(m_playNowText);
		target.draw(m_controlText);
		target.draw(m_controlText2);
		target.draw(m_controlText3);
	}


}

void Game::processKeyPress(sf::Keyboard::Key keyPressed)
{



	/// A down boolean
	/** checks if the A on keyboard is down, if so, set to true*/
	if (keyPressed == sf::Keyboard::A)
	{
		m_leftDown = true;

	}

	/// D down boolean
	/** checks if the D on keyboard is down, if so, set to true*/
	else if (keyPressed == sf::Keyboard::D)
	{
		m_rightDown = true;

	}

	/// SPACE down boolean
	/** checks if the SPACE on keyboard is down, if so, set to true*/
	else if (keyPressed == sf::Keyboard::Space)
	{
		m_BoosterDown = true;
	}

	/// Left down boolean
	/** checks if the Left on keyboard is down, if so, set to true*/
	else if (keyPressed == sf::Keyboard::Left)
	{
		m_leftDownBike = true;
	}
	/// Right down boolean
	/** checks if the Right on keyboard is down, if so, set to true*/
	else if (keyPressed == sf::Keyboard::Right)
	{
		m_rightDownBike = true;
	}

	/// Bike Jump if statement
	/** checks if the the player is pressing W , if so, apply force upwards*/
	else if (keyPressed == sf::Keyboard::W)
	{
		m_bike.Jump();

	}


	/// Start game if statement
	/** checks key press for starting the gmae*/
	else if (keyPressed == sf::Keyboard::Return)
	{
		l_isplaying = true;

	}

	/// Go back to menu
	/** checks key press for starting the gmae*/
	else if (keyPressed == sf::Keyboard::M)
	{
		l_isplaying = false;
		//!<TODO, make the game pause while in menu
	}

	/// Zoom out
	/** checks if the the player is pressing F1 , if so, zoom in*/
	else if (keyPressed == sf::Keyboard::O) //! zoom camera in
	{
		gameView.zoom(1.0f * 2);
	}

	/// Zoom in
	/** checks if the the player is pressing F2, if so, zoom out*/
	else if (keyPressed == sf::Keyboard::P) // zoom camera out
	{
		gameView.zoom(1.0f  * 2);
	}

}
void Game::processKeyRelease(sf::Keyboard::Key keyReleased)
{
	if (keyReleased == sf::Keyboard::A) //! releases the key so it stops torquing
	{
		m_leftDown = false;
	}

	if (keyReleased == sf::Keyboard::D) //! releases the key so it stops torquing
	{
		m_rightDown = false;
	}


	if (keyReleased == sf::Keyboard::Left) //! releases the key so it stops torquing
	{
		m_leftDownBike = false;
	}

	if (keyReleased == sf::Keyboard::Right) //! releases the key so it stops torquing
	{
		m_rightDownBike = false;
	}


	if (keyReleased == sf::Keyboard::Space) //! releases the key so it stops boosting
	{
		m_BoosterDown = false;

	}
}


void Game::update(float timestep)
{
	

	


	if (l_isplaying == true)
	{
		/// sets the world relative to time
		/** timestep*/
		m_world->Step(timestep, 5, 3);
		/// Calls the bike properties function
		/** handles throttel inputs and rotations , jumping, boosters etc.*/
		BikePropertiesUpdates();
		/// UI UPDATE bike
		/** Updates the player gameview*/
		m_bike.update(gameView);

		/// UI UPDATE background
		/** Updates the background view*/
		m_background.update(backgroundView, 0);

		/// UI UPDATE ui text
		/** Updates the ui based on where the player is on the screen so the UI doesnt disappear of screen or something */
		if (l_isplaying && m_bike.BikeGetYPos())
		{
			m_playerScoreText.setStringText("Score : " + std::to_string(iPlayerScore));
			m_playerScoreText.setStringPosition(sf::Vector2f(0, -10));
		}

		/// Player score 
		/** checks position of player, and sets core accordingly.*/
		if (m_bike.BikeGetXPos() > iPlayerScore)
		{
			iPlayerScore = (int)m_bike.BikeGetXPos();
		}

	}
	

	
	

	
	if (l_isplaying == false)
	{

		/// UI UPDATE background
		/** Updates the background view*/
		m_background.update(backgroundView, 0);
		/// UI UPDATE ui text
		/** Updates the ui based on where the player is on the screen so the UI doesnt disappear of screen or something */
		if (!l_isplaying)
		{
			m_titleScreenText.setStringText("Space Racer");
			m_titleScreenText.setStringPosition(sf::Vector2f(200, 100));
			m_titleScreenText.setStringCharacterSize(84);


			m_playNowText.setStringText("Press 'Enter' to race!");
			m_playNowText.setStringPosition(sf::Vector2f(130, 300));
			m_playNowText.setStringCharacterSize(64);

			m_controlText.setStringText("Controls: Left-A, Right-D, Jump-W, ");
			m_controlText.setStringPosition(sf::Vector2f(100, 500));
			m_controlText.setStringCharacterSize(32);

			m_controlText2.setStringText("Boost Speed-Space Rotate- Left and Right Key");
			m_controlText2.setStringPosition(sf::Vector2f(100, 600));
			m_controlText2.setStringCharacterSize(32);

			m_controlText3.setStringText("O - Zoom in, P - Zoom out");
			m_controlText3.setStringPosition(sf::Vector2f(100, 700));
			m_controlText3.setStringCharacterSize(32);

		}

	}

}

void Game::PlayMusic(sf::Vector3f(musicpos), float pitch, float volume, bool loop) {
	music.setPosition(musicpos); //! change its 3D position.
	music.setPitch(pitch);           //! increase the pitch.
	music.setVolume(volume);         //! reduce the volume.
	music.setLoop(loop);         //! make it loop.
}

void Game::BikePropertiesUpdates() {
	/// throttle update
	/** if statement checking if right bool is down, if so, throttle */
	if (m_rightDown)
	{
		m_bike.Throttle();
	}

	/// decelerate update
	/** if statement checking if left bool is down, if so, decelerate */
	if (m_leftDown)
	{
		m_bike.Decelerate();
	}

	/// bike air body rotation update
	/** if statement checking if D bool is down, if so, rotate clockwise */
	if (m_rightDownBike)
	{
		m_bike.BikeBodyTorqueClockwise();
	}
	/// bike air body rotation update
	/** if statement checking if A bool is down, if so, rotate anti clcokwise */
	if (m_leftDownBike)
	{
		m_bike.BikeBodyTorqueAntiClockwise();
	}
	/// Bike boosters
	/** if statement checking if left bool is down, if so, apply linear veloicty*/
	if (m_BoosterDown)
	{
		m_bike.Boosters();
	}
}