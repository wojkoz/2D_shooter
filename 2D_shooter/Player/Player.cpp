#include "Player.h"



Player::Player(std::string name)
	: Entity("res/sprite/Player.png")
{
	//inherited
	setNick(name);
	setHp(100);

	Shape.setScale(0.5f, 0.5f);
	Shape.setPosition(50.f, 50.f);
	Shape.setOrigin(sf::Vector2f(Shape.getTexture()->getSize().x / float(2), Shape.getTexture()->getSize().y / float(2)));
}

sf::Sprite& Player::getPlayerShape()
{
	return Shape;
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

void Player::setPlayerNick(std::string & n)
{
	setNick(n);
}


