#pragma once
#include "Entity.h"
class Player : private Entity		//nick, hp, playerShape
{
public:
	Player(std::string name);
	sf::CircleShape& getPlayerShape();

	std::string getPlayerNick();
	void decresePlayerHp(int dmg);
	int getPlayerHp();
private:
	
};

