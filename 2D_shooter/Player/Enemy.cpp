#include "Enemy.h"



Enemy::Enemy(std::string name)
{
	setNick(name);
	setHp(100);

	getShape().setRadius(45.f);
	getShape().setPosition(50.f, 50.f);
	getShape().setOrigin(getShape().getRadius(), getShape().getRadius());
	getShape().setFillColor(sf::Color::Red);
}

sf::CircleShape& Enemy::getEnemyShape()
{
	return getShape();
}

std::string Enemy::getEnemyNick()
{
	return  getNick();
}

void Enemy::decreseEnemyHp(int dmg)
{
	decreseHp(dmg);
}

int Enemy::getEnemyHp()
{
	return getHp();
}


Enemy::~Enemy()
{
}
