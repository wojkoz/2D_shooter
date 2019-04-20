#include "Bullet.h"


Bullet::Bullet()
	: currVelocity(0.f, 0.f)
{
	Collision::CreateTextureAndBitmask(yellowTexture, "res/sprite/Player.png");
	shape.setTexture(yellowTexture);
	shape.setScale(0.3f, 0.3f);
	shape.setOrigin(shape.getTexture()->getSize().x/2, shape.getTexture()->getSize().y / 2);
}

void Bullet::setRadius(float  r)
{
	this->radius = r;
}






