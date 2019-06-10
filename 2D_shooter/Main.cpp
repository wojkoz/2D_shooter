#include "Game.h"
#include "Menu/Menu.h"
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML WORK!", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	Game* game = new Game();
	Menu menu(float(window.getSize().x), float(window.getSize().y));

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;

						case sf::Keyboard::Down:
							menu.MoveDown();
							break;

						case sf::Keyboard::Return:
							switch (menu.GetPressedItem())
							{
								case 0:
									std::cout << "Play button has been pressed" << std::endl;
									game->dead = false;
									while (!game->dead) {
										game->update(window);
										game->render(window);
									}

									
									break;
								case 1:
									std::cout << "Exit button has been pressed" << std::endl;
									window.close();
									break;
							}

							break;
					}

					break;

				case sf::Event::Closed:
					window.close();

					break;

			}
		}

		window.clear();

		menu.draw(window);

		window.display();
		

	}


	return 0;
}