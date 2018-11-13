

#include <Box2D/Box2D.h>

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <iomanip>
#include <fstream>







void main() /** Don't forget your doxygen comments! */
{
	
	/// Vector for screen dimensions
	/** sets the dimensions to 800 by 600. */
	sf::Vector2i screenDimensions(800, 600); //! 800x600
	sf::RenderWindow window; //! window object
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "My game"); //! set screen dimensions 
	window.setFramerateLimit(60); //! set framerate

	Game game; //!gameobject



	sf::Clock clock; //! Clock
	sf::Time time = clock.getElapsedTime(); //! a timer, Create a clock for measuring the time elapsed.
	float delay = 1.0f; //! delay




	while (window.isOpen())//! Start game loop.
	{

		sf::Event event; //! Process events.
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)//! Close window : exit.
			{
				window.close(); //! close window
			}


			if (event.type == sf::Event::KeyPressed) //! Key press.
			{

				if (event.key.code == sf::Keyboard::Escape)//! Escape key : exit.
				{
					window.close(); //! close window
				}

				else //! Pass key press to game.
				{
					game.processKeyPress(event.key.code);
					cout << "Key pressed" << endl;
				}



			}
			if (event.type == sf::Event::KeyReleased) //! Key released.
			{
				game.processKeyRelease(event.key.code);
				cout << "Key Released" << endl;
			}

		}

		/// CLOCK
		/** updates the clock with the gameworld.*/
		delay = clock.getElapsedTime().asSeconds(); //// Run at 40 frame a second.
		if (delay>0.025) {
			game.update(delay);

			std::cout << 1.0f / time.asSeconds() << std::endl;

			clock.restart();
		}



		window.clear(sf::Color::Black); //! Clear the window.
		window.draw(game); 	//! Draws the game.					
		window.display(); //! Finally, display the rendered frame on screen.
	}




}