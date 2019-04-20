#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../Collisions/Collision.h"
//base class for player and enemy
class Entity
{
public:
	Entity(std::string src_texture);
	void setHp(int a);
	void setNick(std::string name);
	sf::Sprite Shape;

	std::string getNick();
	void decreseHp(int dmg);
	int getHp();
private:
	int hp;
	std::string nick;
	
	sf::Texture texture;
};

