#pragma once
#include <SFML/Graphics.hpp>
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<math.h>
#include<vector>
#include<iostream>
#include <thread>
#include <future>
#include <ctime>    
#include <cstdlib>  
#include "Player/Player.h"
#include "Player/Enemy.h"
#include "Bullets/Bullet.h"
#include "Map/Map.h"
#include "Collisions/Collision.h"
//#include "Network/Network.h"
//#include "Network/PacketType.h"


using namespace sf;

class Game
{
public:
			Game();
	void	run();					//main function
			~Game();
	void	update(sf::RenderWindow& window);				//updateing frames
	void	render(sf::RenderWindow& window);				//render new frames
	bool dead = false;

	void setNick(std::string n);

private:



	void asyncPlayerMovement();
	enum direction {
		UP, DOWN, LEFT, RIGHT
	};
	direction player_dir;

	bool isCollision(Bullet bullet);

	const int WINDOW_HEIGHT = 800;			//window size
	const int WINDOW_WIDTH = 800;
	const float PI = 3.14159265f;
	const int MAX_BULLET_COUNT = 5;
	const int MIN_ENEMY_ON_MAP = 5;

	int MAX_ENEMY_ON_MAP = 15;		//player can change this up to 25


	//player & enemy
	Player *player;
	sf::Font font;
	sf::Text playerNameText;
	sf::Text killCounterText;
	int killCounter;

	//Enemy * enemy;
	std::vector<Enemy*> enemy;
	void checkAmountOfEnemy();
	void addEnemy();
	void respawnEntity(sf::Sprite *s, char entity);	//use ONLY after Map init	
	void enemyMovment();
	void changeEnemyDir(sf::Sprite *s);
	sf::Vector2f getSpawnCoords();			

	//Colissions
	const float playerSpeed = 10.f;
	const float enemySpeed = 2.f;
	void checkPlayerCollision(direction d);
	bool spriteCollision(sf::Sprite *s);
	void asyncCollision();
	bool enemyPlayerCollisionSpawn();
	bool checkAllEnemyPosCollision(sf::Sprite *s);
	bool checkPlayerPos(sf::Sprite *s);
	bool enemyNotInMapBorder(sf::Sprite *s);

	//Vectors
	Vector2f playerCenter;
	Vector2f mousePosWindow;
	Vector2f aimDir;				//vector from player to where mouse was clicked
	Vector2f aimDirNorm;			//vector with points x,y over mouse click
	Vector2f playerPrevPos;

	Bullet b1;
	std::vector<Bullet> bullets;

	Map *map;

	sf::View viewPlayer;

	//network
	//Network *network;
	//sf::Packet packet;
	//void AsyncPacketSend();
	//void asyncReceivePacket();
	//void checkPacketType();

	//PacketType packetType;


};

