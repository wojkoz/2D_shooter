#include "Enemy.h"



Enemy::Enemy(std::string name)
	: Entity("res/sprite/Enemy.png")
{
	setNick(name);
	setHp(100);

	Shape.setScale(0.5f, 0.5f);
	Shape.setPosition(50.f, 50.f);
	Shape.setOrigin(Shape.getTexture()->getSize().x/2, Shape.getTexture()->getSize().y/2);
}

sf::Sprite& Enemy::getEnemyShape()
{
	return Shape;
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
