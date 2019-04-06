#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>

class Map
{
public:
	Map();
	sf::RectangleShape shapes[20][20];
	~Map();
private:
	void loadMap();
	void makeShapes();

	std::fstream file;
	sf::Vector2i map[20][20];
	sf::Vector2i counter;

	
};

