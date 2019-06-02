#pragma once
#include <SFML/Graphics.hpp>
class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();
		

private:
	int selectedItem;
	const short MAX_NUMBER_OF_ITEMS = 2;
	sf::Font font;
	sf::Text menu[2];
	

};

