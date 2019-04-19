#include "Entity.h"

void Entity::setHp(int a)
{
	hp = a;
}

void Entity::setNick(std::string name)
{
	nick = name;
}

sf::CircleShape & Entity::getShape()
{
	return playerShape;
}

std::string Entity::getNick()
{
	return nick;
}

void Entity::decreseHp(int dmg)
{
	hp -= dmg;
}

int Entity::getHp()
{
	return hp;
}
