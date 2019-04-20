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
	
}
void t(const std::string& s) {
	std::cout << s << std::endl;
}

void Game::run() { 
	

	while(window.isOpen()) 
	{
		processEvents();		
		update();
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
		if (Keyboard::isKeyPressed(Keyboard::A))
			checkPlayerCollision(direction::LEFT);
		if (Keyboard::isKeyPressed(Keyboard::D))
			checkPlayerCollision(direction::RIGHT);
		if (Keyboard::isKeyPressed(Keyboard::W))
			checkPlayerCollision(direction::UP);
		if (Keyboard::isKeyPressed(Keyboard::S))
			checkPlayerCollision(direction::DOWN);


		//Shooting
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			b1.shape.setPosition(playerCenter);
			b1.currVelocity = aimDirNorm * b1.maxSpeed;

			bullets.push_back(Bullet(b1));
		}

		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].shape.move(bullets[i].currVelocity);

			//destroying bullets when out of map border
			if (isCollision(bullets[i]))
			{
				bullets.erase(bullets.begin() + i);
			}
		}

		//player nick position
		playerNameText.setPosition(playerCenter.x - playerNameText.getLocalBounds().width/1.3f, playerCenter.y - player->getPlayerShape().getTexture()->getSize().y/2);
		
		//scroll view
		viewPlayer.setCenter(playerCenter);
		viewPlayer.setSize(sf::Vector2f((float)WINDOW_WIDTH, (float)WINDOW_HEIGHT));
}

void Game::render() {
	window.clear(sf::Color::Black); 
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
	//drawing player (on bullets start location)
	window.draw(player->getPlayerShape());
	window.draw(playerNameText);

	//stop drawing here
	window.display(); 
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


Game::~Game()
{
	delete(map);
	delete(player);
}
