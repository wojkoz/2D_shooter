#pragma once
#include <SFML/Graphics.hpp>
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<math.h>
#include<vector>
#include<iostream>
#include <thread>
#include "Player/Player.h"
#include "Bullets/Bullet.h"
#include "Map/Map.h"
#include "Collisions/Collision.h"
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

	enum direction {
		UP, DOWN, LEFT, RIGHT
	};
	direction player_dir;

	bool isCollision(Bullet bullet);

	const int WINDOW_HEIGHT = 800;			//window size
	const int WINDOW_WIDTH = 800;
	const float PI = 3.14159265f;

	sf::RenderWindow window;		//window

	Player *player;
	sf::Font font;
	sf::Text playerNameText;

	const float playerSpeed = 10.f;
	void checkPlayerCollision(direction d);
	bool playerCollision();

	//Vectors
	Vector2f playerCenter;
	Vector2f mousePosWindow;
	Vector2f aimDir;				//vector from player to where mouse was clicked
	Vector2f aimDirNorm;			//vector with points x,y over mouse click

	Bullet b1;
	std::vector<Bullet> bullets;

	Map *map;

	sf::View viewPlayer;
};

