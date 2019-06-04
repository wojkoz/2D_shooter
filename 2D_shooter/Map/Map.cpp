#include "Map.h"



Map::Map()
{
	//map = makeArray<sf::Vector2i>(100, 250);
	//shapes = makeArray<sf::Sprite>(100, 250);
	Collision::CreateTextureAndBitmask(texture, "res/sprite/background.png");

	sf::Vector2i counter = sf::Vector2i(0, 0);
	loadMap();
	makeShapes();
}

int Map::getMapX()
{
	return map.at(0).size() * 100;
}

int Map::getMapY()
{
	return map.size() * 100;
}

int Map::getShapeRows()
{
	return map.at(0).size();
}

int Map::getShapeCols()
{
	return map.size();//map.size();
}

void Map::loadMap() {
	
	file.open("Map1.txt");		//file with map structure
	if (file.is_open()) {

		std::vector<sf::Vector2i> *tmp = new std::vector<sf::Vector2i>;

		while (!file.eof()) {

			std::string str;
			file >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) && !isdigit(y)) {
				//map[counter.x][counter.y] = sf::Vector2i(-1, -1);	//draw background when x,x in file
				tmp->push_back(sf::Vector2i(-1, -1));
			}
			else {
				//map[counter.x][counter.y] = sf::Vector2i(x - '0', y - '0');	//ASCI 0 == 48, 1 == 49, 1-48 == 1
				tmp->push_back(sf::Vector2i(x - '0', y - '0'));
			}
				

			if (file.peek() == '\n') {
				map.push_back(*tmp);
				counter.y++;
				delete(tmp);
				tmp = new std::vector<sf::Vector2i>;
				counter.x = 0;
				
			}
			else {
				counter.x++;		
			}	
		}
		counter.y++;
		file.close();
		delete(tmp);
	}
	else {			//when can't load file with map structure
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				map[i][j] = sf::Vector2i(1, 1);
	}
}

void Map::makeShapes() {
	std::cout << map.size() << "\t" << map.at(0).size();
	for (int i = 0; i < map.size(); i++) {
		std::vector<sf::Sprite> *tmp = new std::vector<sf::Sprite>;
		for (int j = 0; j < map.at(0).size()-1; j++) {
			if (map.at(i).at(j).x != -1 && map.at(i).at(j).y != -1) {
				
				sf::Sprite t;
				t.setPosition(sf::Vector2f(i*100.f, j*100.f));
				t.scale(4.f, 4.f);
				t.setTexture(texture);
				t.setColor(sf::Color(0, 0, 255));
				
				tmp->push_back(t);

			}
		}
		shapes.push_back(*tmp);
		delete(tmp);
	}
}


Map::~Map()
{
	
}
