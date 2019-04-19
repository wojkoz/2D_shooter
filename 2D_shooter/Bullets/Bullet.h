#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Bullet
{
public:
	Bullet();

	void setRadius(float r);

	sf::Vector2f currVelocity;
	sf::CircleShape shape;
    float maxSpeed = 15.f;


private:

	float radius = 5.f;

};

