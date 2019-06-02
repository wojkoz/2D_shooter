#include "Game.h"
#include "Menu/Menu.h"
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML WORK!");
	window.setFramerateLimit(60);
	string playerName = "";

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
									std::cout << "Option button has been pressed" << std::endl;
									break;
								case 2:
									window.close();
									break;
							}
						case sf::Keyboard::BackSpace:
							playerName = playerName.substr(0, playerName.length() - 1);
							break;

							break;
					}

					break;
				case sf::Event::TextEntered:
					playerName += static_cast<char>(event.text.unicode);
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