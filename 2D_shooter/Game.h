#pragma once
#include <SFML/Graphics.hpp>
class Game
{
public:
			Game();
	void	run();					//main function
			~Game();

private:
	void	processEvents();		//processing user input
	void	update();				//updateing frames
	void	render();				//render new frames

	const int DIM = 800;			//window size DIM x DIM

	sf::RenderWindow mWindow;		//window
	sf::CircleShape mPlayer;
};

