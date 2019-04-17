#include "Player.h"



Player::Player(std::string name)
{
	//inherited
	nick = name;
	hp = 100;

	playerShape.setRadius(45.f);
	playerShape.setPosition(50.f, 50.f);
	playerShape.setOrigin(playerShape.getRadius(), playerShape.getRadius());
	playerShape.setFillColor(sf::Color::Cyan);
}

std::string Player::getNick()
{
	return nick;
}

void Player::decreseHp(int dmg)
{
	hp -= dmg;
}

int Player::getHp()
{
	return hp;
}


