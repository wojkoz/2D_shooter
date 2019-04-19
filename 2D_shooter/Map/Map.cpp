#include "Map.h"



Map::Map()
{
	map = makeArray<sf::Vector2i>(20, 20);
	shapes = makeArray<sf::RectangleShape>(20, 20);

	sf::Vector2i counter = sf::Vector2i(0, 0);
	loadMap();
	makeShapes();
}

int Map::getMapX()
{
	return counter.x * 100;
}

int Map::getMapY()
{
	return counter.y * 100;
}

int Map::getShapeRows()
{
	return counter.y;
}

int Map::getShapeCols()
{
	return counter.x;
}

void Map::loadMap() {
	file.open("Map1.txt");		//file with map structure
	if (file.is_open()) {

		while (!file.eof()) {
			std::string str;
			file >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y)) {
				map[counter.x][counter.y] = sf::Vector2i(-1, -1);	//draw background when x,x in file
			}
			else {
				map[counter.x][counter.y] = sf::Vector2i(x - '0', y - '0');	//ASCI 0 == 48, 1 == 49, 1-48 == 1
			}
				

			if (file.peek() == '\n') {
				counter.x = 0;
				counter.y++;
			}
			else {
				counter.x++;
			}	
		}
		counter.y++;
		file.close();
	}
	else {			//when can't load file with map structure
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				map[i][j] = sf::Vector2i(-1, -1);
	}
}

void Map::makeShapes() {

	for(int i = 0; i<counter.x; i++)
		for (int j = 0; j < counter.y; j++) {
			if (map[i][j].x != -1 && map[i][j].y != -1) {

				shapes[i][j] = sf::RectangleShape();
				shapes[i][j].setPosition(sf::Vector2f(i*100.f, j*100.f));
				//temporary coloring
				if(j%2==0)
					shapes[i][j].setFillColor(sf::Color::Green);
				else
					shapes[i][j].setFillColor(sf::Color::Blue);

				shapes[i][j].setSize(sf::Vector2f(100.f, 100.f));				
			}
			
		}
}


Map::~Map()
{
	
}
