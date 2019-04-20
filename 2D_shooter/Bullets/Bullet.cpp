#include "Bullet.h"


Bullet::Bullet()
	: currVelocity(0.f, 0.f)
{
	Collision::CreateTextureAndBitmask(yellowTexture, "res/sprite/Player.png");
	shape.setTexture(yellowTexture);
	shape.setScale(0.1f, 0.1f);
	shape.setOrigin(shape.getTexture()->getSize().x/2, shape.getTexture()->getSize().y / 2);
	shape.setColor(sf::Color(0, 255, 0));//color of sprite (red, green, blue)
}

void Bullet::setRadius(float  r)
{
	this->radius = r;
}






