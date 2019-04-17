#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Entity.h"
class Player : private Entity
{
public:
	Player(std::string name);
	sf::CircleShape playerShape;
	std::string getNick();
	void decreseHp(int dmg);
	int getHp();
private:

};

