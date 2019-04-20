#pragma once
#include<SFML/Graphics.hpp>
#include"../Collisions/Collision.h"
using namespace sf;
class Bullet
{
public:
	Bullet();

	void setRadius(float r);

	sf::Vector2f currVelocity;
	sf::Sprite shape;
    float maxSpeed = 15.f;


private:
	sf::Texture yellowTexture;
	sf::Sprite yellowSprite;

	float radius = 5.f;

};

