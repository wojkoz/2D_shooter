#include "Game.h"


Game::Game()
{
	srand(unsigned int(time(nullptr)));

	map = new Map();

	//player nick
	player = new Player("TheEnter3");
	
	respawnEntity(&player->getPlayerShape(), 'p');

	
							//font for player name
	if (!font.loadFromFile("res/Font/PlayerName/data-latin.ttf")) {
		std::cout << "Error, couldn't find Font/PlayerName/data-latin.ttf"<<std::endl;
		return;
	}
	else {					//text above player
		playerNameText.setFont(font);
		playerNameText.setFillColor(sf::Color::White);
		playerNameText.setScale(1.5f,1.5f);
		playerNameText.setString(player->getPlayerNick());

		//killCounter text
		killCounterText.setFont(font);
		killCounterText.setFillColor(sf::Color::White);
		killCounterText.setScale(1.5f, 1.5f);
	}
	
	killCounter = 0;

	minimapView.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));
	//network
	// dodac GUI i pobierac IP, port, nick

	//network = new Network(x, s);
	//enemy->getEnemyShape().setPosition(sf::Vector2f(0,0));

	//packetType.makePacketType(packetType.Connect, packet);	//sending information that client is connecting to server
	//packet << n << 0 << 0;		//name
	//network->sendPacket(packet);
	//packet.clear();
}

void Game::update(sf::RenderWindow& window) {
	//network recevie packet
	//std::future<void> rp(std::async(&Game::asyncReceivePacket, this));

	

	//std::future<void> cpt(std::async(&Game::checkPacketType, this));
	//checkPacketType();
	if (killCounter > 0 && killCounter % 10 == 0 && MAX_ENEMY_ON_MAP < 50)
		MAX_ENEMY_ON_MAP += 5;
	
	//Enemy
	checkAmountOfEnemy();
	enemyMovment();


	if (enemyPlayerCollisionSpawn()) {
		return;
	}
	
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos); //changing coordinates of mouse in window to world coordinates when windows is resized or player is further than
																//window height or width
	//Vectors
	playerCenter = Vector2f(player->getPlayerShape().getPosition());
	mousePosWindow = Vector2f(worldPos);
	
	aimDir = mousePosWindow - playerCenter;
	aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	float deg = atan2(aimDirNorm.y, aimDirNorm.x) * 180 / PI;
	player->getPlayerShape().setRotation(deg+90);

	//Player movement
	std::future<void> pm(std::async(&Game::asyncPlayerMovement, this));
	pm.get();

	
	//Shooting
	if (Mouse::isButtonPressed(Mouse::Left) && bullets.size() < MAX_BULLET_COUNT)
	{
		b1.shape.setPosition(playerCenter);
		b1.currVelocity = aimDirNorm * b1.maxSpeed;
		bullets.push_back(Bullet(b1));
	}

	//async call checiking bullets collision
	std::future<void> bulletColl(std::async(&Game::asyncCollision,this));

	//player nick position
	playerNameText.setPosition(playerCenter.x - playerNameText.getLocalBounds().width/1.3f, playerCenter.y - player->getPlayerShape().getTexture()->getSize().y/2);
		
	//scroll view
	viewPlayer.setCenter(playerCenter);
	minimapView.setCenter(playerCenter);
	viewPlayer.setSize(sf::Vector2f((float)WINDOW_WIDTH, (float)WINDOW_HEIGHT));
	
	//bullets collision result
	//rp.get();
	//cpt.get();
	bulletColl.get();

	//network send packet
	//packetType.makePacketType(packetType.Player_Update, packet);		//function from PacketType.h

	//std::future<void> t1(std::async(&Game::AsyncPacketSend, this));
	//t1.get();
	
	//killCounter text and position
	killCounterText.setString(std::to_string(killCounter));
	killCounterText.setPosition(playerCenter.x + (WINDOW_WIDTH/3 ), playerCenter.y + (WINDOW_HEIGHT/3));
}

void Game::asyncPlayerMovement()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
		checkPlayerCollision(direction::LEFT);
	if (Keyboard::isKeyPressed(Keyboard::D))
		checkPlayerCollision(direction::RIGHT);
	if (Keyboard::isKeyPressed(Keyboard::W))
		checkPlayerCollision(direction::UP);
	if (Keyboard::isKeyPressed(Keyboard::S))
		checkPlayerCollision(direction::DOWN);
}

void Game::render(sf::RenderWindow& window) {
	window.clear(sf::Color(0,153,0)); 
	//start drawing here
	 for(int i = 0; i<map->getShapeRows();i++)
		 for (int j = 0; j < map->getShapeCols(); j++) {
			 window.draw(map->shapes[i][j]);
		 }
	 //drawing enemy, player
	 for (int i = 0; i < enemy.size(); i++) {
		 window.draw(enemy.at(i)->getEnemyShape());
	 }
	 window.setView(minimapView);

	 for (int i = 0; i < map->getShapeRows(); i++)
		 for (int j = 0; j < map->getShapeCols(); j++) {
			 window.draw(map->shapes[i][j]);
		 }
	 //drawing enemy, player
	 for (int i = 0; i < enemy.size(); i++) {
		 window.draw(enemy.at(i)->getEnemyShape());
	 }
	 window.draw(player->getPlayerShape());
	 //centering view on player
	 window.setView(viewPlayer);
	
	//drawing bullets
	 for (auto i = 0; i < bullets.size(); i++)
	 {
		 window.draw(bullets[i].shape);
	 }


	window.draw(player->getPlayerShape());
	window.draw(playerNameText);
	window.draw(killCounterText);

	//stop drawing here
	window.display(); 
}

void Game::setNick(std::string n)
{
	player->setPlayerNick(n);
	playerNameText.setString(n);
}

void Game::asyncCollision() {
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].shape.move(bullets[i].currVelocity);

		//destroying bullets when out of map border or hit object with collision
		if (isCollision(bullets[i]))
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}

bool Game::enemyPlayerCollisionSpawn()
{
	for (int i = 0; i < enemy.size() ; i++) {

		if (Collision::PixelPerfectTest(player->getPlayerShape(), enemy.at(i)->getEnemyShape())) {
			//player death
			killCounter = 0;
			respawnEntity(&player->getPlayerShape(), 'p');
			dead = true;
			bullets.clear();
			enemy.clear();
			return true;
		}
	}
	return false;
}

bool Game::checkAllEnemyPosCollision(sf::Sprite * s)
{
	for (int i = 0; i < enemy.size(); i++) {

		if (Collision::PixelPerfectTest(*s, enemy.at(i)->getEnemyShape())) {
			return true;
		}
	}
	return false;
}

bool Game::checkPlayerPos(sf::Sprite * s)
{
	if (Collision::PixelPerfectTest(*s, player->getPlayerShape()))
		return true;
	return false;
}

bool Game::enemyNotInMapBorder(sf::Sprite * s)
{
	if ((s->getGlobalBounds().width + s->getGlobalBounds().left > map->getMapX())) {
		return true;
	}
	if ((s->getGlobalBounds().left < 0)) {
		return true;
	}
	if (s->getGlobalBounds().top < 0) {
		return true;
	}
	if (s->getGlobalBounds().top + s->getGlobalBounds().height > map->getMapY()) {
		return true;
	}
	return false;
	
}

bool Game::isCollision(Bullet bullet)
{
	//map border collision
	if (bullet.shape.getPosition().x < 0 || bullet.shape.getPosition().x > map->getMapX()
		|| bullet.shape.getPosition().y < 0 || bullet.shape.getPosition().y > map->getMapY()) {
			return true;
	}			
	else {//map collision
		for (int i = 0; i < map->getShapeRows(); i++) {
			for (int j = 0; j < map->getShapeCols(); j++) {
				if (Collision::PixelPerfectTest(bullet.shape, map->shapes[i][j] )) {
					return true;
				}
				else {//enemy collision with bullets
					for(int k = 0; k<enemy.size(); k++)
						if (Collision::PixelPerfectTest(bullet.shape, enemy.at(k)->getEnemyShape())) {
							killCounter++;
							enemy.erase(enemy.begin() + k);
							return true;
						}
				}
			}
		}
		
	}
	return false;
}

void Game::checkAmountOfEnemy()
{
	if (enemy.size() < MIN_ENEMY_ON_MAP) {
		for (auto i = 0; i < (MAX_ENEMY_ON_MAP - MIN_ENEMY_ON_MAP); i++)
			addEnemy();
	}
}

void Game::addEnemy()
{
	enemy.push_back(new Enemy("1"));
	respawnEntity(&enemy.back()->getEnemyShape(), 'e');
}

void Game::respawnEntity(sf::Sprite * s, char entity = 'e')//p player, e enemy
{
	while (true) {
		s->setPosition(getSpawnCoords());
		
		if (entity == 'p') {
			if (!spriteCollision(s)) {
				std::cout << "test";
				if (!checkAllEnemyPosCollision(&player->getPlayerShape())) {
					break;
				}
				else {
					continue;
				}
			}
		}
		else {
			if (!spriteCollision(s) && !checkPlayerPos(s)) {
				break;
			}
			else {
				continue;
			}
		}

	}
}

void Game::enemyMovment()
{
	for (auto i = 0; i < enemy.size(); i++) {
		changeEnemyDir(&enemy.at(i)->getEnemyShape());
		if (enemyNotInMapBorder(&enemy.at(i)->getEnemyShape())) {
			enemy.erase(enemy.begin() + i);
		}
	}
}

void Game::changeEnemyDir(sf::Sprite * s)
{
	auto eX = s->getPosition().x;//enemy x pos
	auto eY = s->getPosition().y;//enemy y pos

	auto pX = player->getPlayerShape().getPosition().x;
	auto pY = player->getPlayerShape().getPosition().y;

	if (eX <= pX) {
		if(spriteCollision(s))
			s->move(-enemySpeed, 0.0f);
		else
			s->move(enemySpeed, 0.0f);
	}
	if(eX > pX) {
		if (spriteCollision(s))
			s->move(enemySpeed, 0.0f);
		else
			s->move(-enemySpeed, 0.0f);
	}

	if (eY <= pY) {
		if (spriteCollision(s))
			s->move(0.0f, -enemySpeed);
		else
			s->move(0.0f, enemySpeed);	
	}
	else {
		if (spriteCollision(s))
			s->move(0.0f, enemySpeed);
		else
			s->move(0.0f, -enemySpeed);	
	}

}

sf::Vector2f Game::getSpawnCoords()
{
	return sf::Vector2f(float((rand() % map->getMapX()) + 1), float((rand() % map->getMapY()) + 1));
}

void Game::checkPlayerCollision(direction d)
{
			if (d == direction::LEFT) {
				if (player->getPlayerShape().getGlobalBounds().left - playerSpeed >= -30 )
					player->getPlayerShape().move(-playerSpeed, 0.f);
				if(spriteCollision( &player->getPlayerShape() ))
					player->getPlayerShape().move(playerSpeed, 0.f);
			}
			else {
				if (d == direction::RIGHT) {
					if (player->getPlayerShape().getGlobalBounds().width + player->getPlayerShape().getGlobalBounds().left + playerSpeed <= map->getMapX() - 55)
						player->getPlayerShape().move(playerSpeed, 0.f);
					if (spriteCollision(&player->getPlayerShape()))
						player->getPlayerShape().move(-playerSpeed, 0.f);
				}
			}
			
			if (d == direction::UP) {
				if (player->getPlayerShape().getGlobalBounds().top - playerSpeed >= -30)
					player->getPlayerShape().move(0.f, -playerSpeed);
				if (spriteCollision( &player->getPlayerShape() ))
					player->getPlayerShape().move(0.f, playerSpeed);
			}
			else {
				if (d == direction::DOWN) {
					if (player->getPlayerShape().getGlobalBounds().height + player->getPlayerShape().getGlobalBounds().top + playerSpeed <= map->getMapY() - 70)
						player->getPlayerShape().move(0.f, playerSpeed);
					if (spriteCollision(&player->getPlayerShape()))
						player->getPlayerShape().move(0.f, -playerSpeed);
				}
			}
			
}

bool Game::spriteCollision(sf::Sprite *s)
{
	for (int i = 0; i < map->getShapeRows(); i++) {
		for (int j = 0; j < map->getShapeCols(); j++) {
			if (Collision::PixelPerfectTest(*s, map->shapes[i][j])) {
				return true;
			}
		}
	}
	return false;
}

//void Game::AsyncPacketSend() {
	//if (player->getPlayerShape().getPosition().x != playerPrevPos.x || player->getPlayerShape().getPosition().y != playerPrevPos.y) {
		//std::cout << "\nSENDING\n" << packetType.Player_Update << player->getPlayerNick() << player->getPlayerShape().getPosition().x << player->getPlayerShape().getPosition().y;
		//packet << player->getPlayerNick() << player->getPlayerShape().getPosition().x << player->getPlayerShape().getPosition().y;
		//playerPrevPos = player->getPlayerShape().getPosition();
		//network->sendPacket(packet);
	//}	
//}

//void Game::asyncReceivePacket()
//{
	//network->receivePacket(packet);
	//checkPacketType();
//}

//void Game::checkPacketType()
//{
	//int pType;
	//std::string name;
	//packet >> pType >> name >> a.x >> a.y;
	//std::cout << "\npType:\t"<<pType << "\tname\t" << name;

	//if (pType ==packetType.Player_Update) {
		//do usuaniecia TEST
		//if (a.x != NAN || a.x != -NAN) {
			//std::cout <<"\t"<< a.x << "\t" << a.y << std::endl;
			//for (int i = 0; i < enemy.size(); i++) {
				//if (enemy.at(i)->getEnemyNick() == name) {
					//enemy.at(i)->getEnemyShape().setPosition(a);
					//break;
				//}
			//}
		//}
	//}
	//else {
		//if (pType == packetType.Connect) {
			//enemy.push_back(new Enemy(name));
			//std::cout << "NOWY PRZECIWNIK";
		//}
		//else {
			//for (int i = 0; i < enemy.size(); i++) {
				//if (enemy.at(i)->getEnemyNick() == name) {
					//enemy.erase(enemy.begin() + i);
					//break;
				//}

			//}

		//}
	//}
	
	//packet.clear();
//}

Game::~Game()
{
	delete(map);
	delete(player);
	//delete(network);
}


