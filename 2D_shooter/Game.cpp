#include "Game.h"



////LENGTH OF VECTOR: |V| = sqrt(V.x^2 + V.y^2)
////NORMALIZE VECTOR: U = V / |V|

Game::Game()
	:	window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH),"2D Shooter"),
		player()
{
	window.setFramerateLimit(60);
	player.setRadius(80.f);  
	player.setPosition(100.f, 100.f);  
	player.setFillColor(sf::Color::Cyan);
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
	//Vectors
		playerCenter = Vector2f(player.getPosition());
		mousePosWindow = Vector2f(Mouse::getPosition(window));
		aimDir = mousePosWindow - playerCenter;
		aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

		float deg = atan2(aimDirNorm.y, aimDirNorm.x) * 180 / PI;
		player.setRotation(deg + 90);

		//Set Final Rotation of Ship
		std::cout << deg << "\n";

		//Player
		if (Keyboard::isKeyPressed(Keyboard::A))
			player.move(-10.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::D))
			player.move(10.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::W))
			player.move(0.f, -10.f);
		if (Keyboard::isKeyPressed(Keyboard::S))
			player.move(0.f, 10.f);


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
			if (bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > window.getSize().x
				|| bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > window.getSize().y)
			{
				bullets.erase(bullets.begin() + i);
				
			}
		}


}

void Game::render() {
	window.clear(); 
	window.draw(player); 

	//drawing bullets
	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i].shape);
	}

	window.display(); 
}


Game::~Game()
{
}
