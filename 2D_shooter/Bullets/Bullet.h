#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Bullet
{
public:
	Bullet();
	//make private Game.cpp 60line
	sf::Vector2f currVelocity;
	sf::CircleShape shape;
	float maxSpeed = 15.f;
	float radius = 5.f;

private:


};

