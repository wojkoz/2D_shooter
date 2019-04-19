#include "Player.h"



Player::Player(std::string name)
{
	//inherited
	setNick(name);
	setHp(100);

	getShape().setRadius(45.f);
	getShape().setPosition(50.f, 50.f);
	getShape().setOrigin(getShape().getRadius(), getShape().getRadius());
	getShape().setFillColor(sf::Color::Cyan);
}

sf::CircleShape& Player::getPlayerShape()
{
	return getShape();
}

std::string Player::getPlayerNick()
{
	return  getNick();
}

void Player::decresePlayerHp(int dmg)
{
	decreseHp(dmg);
}

int Player::getPlayerHp()
{
	return getHp();
}


