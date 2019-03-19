#pragma once
#include <SFML/Graphics.hpp>
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<math.h>
#include<vector>
#include<iostream>
#include<vector>
#include "Bullets/Bullet.h"
using namespace sf;

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

	const int WINDOW_HEIGHT = 800;			//window size
	const int WINDOW_WIDTH = 800;
	const float PI = 3.14159265f;

	sf::RenderWindow window;		//window
	sf::CircleShape player;

	//Vectors
	Vector2f playerCenter;
	Vector2f mousePosWindow;
	Vector2f aimDir;				//vector from player to where mouse was clicked
	Vector2f aimDirNorm;			//vector with points x,y over mouse click

	Bullet b1;
	std::vector<Bullet> bullets;
};

