#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "2D Shooter");
	sf::CircleShape shape(300.f);
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}