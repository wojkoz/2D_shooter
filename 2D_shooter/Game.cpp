#include "Game.h"


Game::Game()
	:	window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH),"2D Shooter")
{
	player = new Player("TheEnter3");
	map = new Map();
	window.setFramerateLimit(60);
							//font for player name
	if (!font.loadFromFile("res/Font/PlayerName/data-latin.ttf")) {
		std::cout << "Error, couldn't find Font/PlayerName/RemachineScript_Personal_Use.ttf"<<std::endl;
	}
	else {					//text above player
		playerNameText.setFont(font);
		playerNameText.setFillColor(sf::Color::White);
		playerNameText.setScale(1.5f,1.5f);
		playerNameText.setString(player->getPlayerNick());
	}
	//network
	unsigned short x;
	std::string s;
	std::cin >> x;
	std::cin >> s;
	network = new Network(x, s);
	enemy = new Enemy("enemy");
	enemy->getEnemyShape().setPosition(sf::Vector2f(0,0));

	packet << 2.f << 3.f;
	network->sendPacket(packet);
	packet.clear();
}

void Game::run() { 


	while(window.isOpen()) 
	{
		processEvents();
		std::future<void> r(std::async(&Game::update, this));
		r.get();
		render();		
	}
	
}

void Game::processEvents() { 
	sf::Event event; 
	while(window.pollEvent(event)) 
	{ 
		if (event.type == sf::Event::Closed)
			window.close();		
	} 

}

void Game::update() {
	//network recevie packet
	std::future<void> rp(std::async(&Game::asyncReceivePacket, this));

	rp.get();
	sf::Vector2f a;//do usuaniecia TEST
	packet >> a.x >> a.y;
	if (a.x != NAN || a.x != -NAN) {
		std::cout << a.x << "\t" << a.y << std::endl;
		enemy->getEnemyShape().setPosition(a);//TEST
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
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		b1.shape.setPosition(playerCenter);
		b1.currVelocity = aimDirNorm * b1.maxSpeed;
		bullets.push_back(Bullet(b1));
	}

	//async call checiking bullets collision
	std::future<void> result(std::async(&Game::asyncCollision,this));

	//player nick position
	playerNameText.setPosition(playerCenter.x - playerNameText.getLocalBounds().width/1.3f, playerCenter.y - player->getPlayerShape().getTexture()->getSize().y/2);
		
	//scroll view
	viewPlayer.setCenter(playerCenter);
	viewPlayer.setSize(sf::Vector2f((float)WINDOW_WIDTH, (float)WINDOW_HEIGHT));
	
	//bullets collision result
	result.get();

	packet.clear();
	//network send packet
	//packet << player->getPlayerNick() << player->getPlayerShape().getPosition();
	packet << player->getPlayerShape().getPosition().x << player->getPlayerShape().getPosition().y;
	//network->sendPacket(packet);
	std::future<void> t1(std::async(&Game::AsyncPacketSend, this));
	t1.get();
	
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

void Game::render() {
	window.clear(sf::Color(0,153,0)); 
	//start drawing here
	 for(int i = 0; i<20;i++)
		 for (int j = 0; j < 20; j++) {
			 window.draw(map->shapes[i][j]);
		 }
	 //centering view on player
	 window.setView(viewPlayer);
	
	//drawing bullets
	 for (auto i = 0; i < bullets.size(); i++)
	 {
		 window.draw(bullets[i].shape);
	 }

	//drawing enemy, player
	window.draw(enemy->getEnemyShape());
	window.draw(player->getPlayerShape());
	window.draw(playerNameText);

	//stop drawing here
	window.display(); 
}

void Game::asyncCollision() {
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].shape.move(bullets[i].currVelocity);

		//destroying bullets when out of map border or hit object with collision
		//std::future<bool> result(std::async(&Game::isCollision, bullets[i]));
		if (isCollision(bullets[i]))
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}

bool Game::isCollision(Bullet bullet)
{
	if (bullet.shape.getPosition().x < 0 || bullet.shape.getPosition().x > map->getMapX()
		|| bullet.shape.getPosition().y < 0 || bullet.shape.getPosition().y > map->getMapY()) {
			return true;
	}			
	else {
		for (int i = 0; i < map->getShapeRows(); i++) {
			for (int j = 0; j < map->getShapeCols(); j++) {
				if (Collision::PixelPerfectTest(bullet.shape, map->shapes[i][j] )) {
					return true;
				}
			}
		}
		
	}
	return false;
}

void Game::checkPlayerCollision(direction d)
{
			if (d == direction::LEFT) {
				if (player->getPlayerShape().getGlobalBounds().left - playerSpeed >= -30 )
					player->getPlayerShape().move(-playerSpeed, 0.f);
				if(playerCollision())
					player->getPlayerShape().move(playerSpeed, 0.f);
			}
			if (d == direction::RIGHT) {
				if (player->getPlayerShape().getGlobalBounds().width + player->getPlayerShape().getGlobalBounds().left + playerSpeed <= map->getMapX() - 55)
					player->getPlayerShape().move(playerSpeed, 0.f);
				if (playerCollision())
					player->getPlayerShape().move(-playerSpeed, 0.f);
			}
			if (d == direction::UP) {
				if (player->getPlayerShape().getGlobalBounds().top - playerSpeed >= -30)
					player->getPlayerShape().move(0.f, -playerSpeed);
				if (playerCollision())
					player->getPlayerShape().move(0.f, playerSpeed);
			}
			if (d == direction::DOWN) {
				if (player->getPlayerShape().getGlobalBounds().height + player->getPlayerShape().getGlobalBounds().top + playerSpeed <= map->getMapY() - 70)
					player->getPlayerShape().move(0.f, playerSpeed);
				if (playerCollision())
					player->getPlayerShape().move(0.f, -playerSpeed);
			}			
}

bool Game::playerCollision()
{
	for (int i = 0; i < map->getShapeRows(); i++) {
		for (int j = 0; j < map->getShapeCols(); j++) {
			if (Collision::PixelPerfectTest(player->getPlayerShape(), map->shapes[i][j])) {
				return true;
			}
		}
	}
	return false;
}

void Game::AsyncPacketSend() {
	network->sendPacket(packet);
}

void Game::asyncReceivePacket()
{
	network->receivePacket(packet);//unzip packet
}

Game::~Game()
{
	delete(map);
	delete(player);
	delete(network);
}


