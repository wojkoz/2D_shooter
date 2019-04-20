#include "Entity.h"

Entity::Entity(std::string src_texture)
{
	Collision::CreateTextureAndBitmask(texture, src_texture);
	Shape.setTexture(texture);
}

void Entity::setHp(int a)
{
	hp = a;
}

void Entity::setNick(std::string name)
{
	nick = name;
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
