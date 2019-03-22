#include "Bullet.h"



Bullet::Bullet()
	: currVelocity(0.f, 0.f)
{
	this->shape.setRadius(radius);
	this->shape.setFillColor(sf::Color::Red);
}

void Bullet::setRadius(float  r)
{
	this->radius = r;
}






