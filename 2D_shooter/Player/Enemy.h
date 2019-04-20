#pragma once
#include<vector>
#include "Entity.h"
#include "../Bullets/Bullet.h"
class Enemy : private Entity
{
public:
	Enemy(std::string name);
	~Enemy();
	sf::Sprite& getEnemyShape();

	std::string getEnemyNick();
	void decreseEnemyHp(int dmg);
	int getEnemyHp();
private:
	std::vector<Bullet> bullets; //objects created from server signal

};

