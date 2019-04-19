#pragma once
#include <string>
#include <SFML/Graphics.hpp>
//base class for player and enemy
class Entity
{
public:
	void setHp(int a);
	void setNick(std::string name);
	sf::CircleShape& getShape();

	std::string getNick();
	void decreseHp(int dmg);
	int getHp();
private:
	int hp;
	std::string nick;
	sf::CircleShape playerShape;
};

