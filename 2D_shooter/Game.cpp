#include "Game.h"


Game::Game()
	:	window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH),"2D Shooter")
{
	player = new Player("TheEnter3");
	map = new Map();
	window.setFramerateLimit(60);
	
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
		playerCenter = Vector2f(player->playerShape.getPosition());
		mousePosWindow = Vector2f(worldPos);
		
		aimDir = mousePosWindow - playerCenter;
		aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

		float deg = atan2(aimDirNorm.y, aimDirNorm.x) * 180 / PI;

		player->playerShape.setRotation(deg+90);

		//Player
		if (Keyboard::isKeyPressed(Keyboard::A))
			player->playerShape.move(-playerSpeed, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::D))
			player->playerShape.move(playerSpeed, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::W))
			player->playerShape.move(0.f, -playerSpeed);
		if (Keyboard::isKeyPressed(Keyboard::S))
			player->playerShape.move(0.f, playerSpeed);


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
			if (bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > 2000//window.getSize().x
				|| bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > 2000)//window.getSize().y)
			{
				bullets.erase(bullets.begin() + i);
				
			}
		}
		
		//scroll view
		viewPlayer.setCenter(playerCenter);
		viewPlayer.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
		
}

void Game::render() {
	window.clear(sf::Color::Green); 
	//start drawing here
	 for(int i = 0; i<20;i++)
		 for (int j = 0; j < 20; j++) {
			 window.draw(map->shapes[i][j]);
		 }
	 //centering view on player
	 window.setView(viewPlayer);
	
	//drawing bullets
	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i].shape);
	}
	//drawing player (on bullets start location)
	window.draw(player->playerShape);

	//stop drawing here
	window.display(); 
}


Game::~Game()
{
	delete(map);
}
