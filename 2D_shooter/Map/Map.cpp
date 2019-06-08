#include "Map.h"

Map::Map()
{
	map = makeArray<sf::Vector2i>(20, 20);
	shapes = makeArray<sf::Sprite>(20, 20);
	Collision::CreateTextureAndBitmask(texture, "res/sprite/background.png");

	sf::Vector2i counter = sf::Vector2i(0, 0);
	loadMap();
	makeShapes();
}

int Map::getMapX()
{
	return counter.x * 100 ;
}

int Map::getMapY()
{
	return counter.y * 100 ;
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
		std::vector<std::vector<std::string>> s;
		std::string tmp;
		
		std::vector<std::string>* a = new std::vector<std::string>;
		
		while (file >> tmp) {

			if (file.peek() == '\n') {
				s.push_back(*a);
				a->clear();
				counter.y++;
				counter.x = 0;
			}
			else {
				a->push_back(tmp);
				counter.x++;				
			}

		}
		counter.x--;
		file.close();
		
		//deleteArray(map,counter.y);		
		//deleteArray(shapes, counter.y);

		map = makeArray<sf::Vector2i>(counter.y, counter.x);
		shapes = makeArray<sf::Sprite>(counter.y, counter.x);

		for (auto i = 0; i < counter.y; i++) {
			for (auto j = 0; j < counter.x; j++) {
				if ( isdigit(s[i][j].at(0)) && isdigit(s[i][j].at(2)) ) {
					map[i][j] = sf::Vector2i(s[i][j].at(0) - '0', s[i][j].at(2) - '0');//ASCI 0 == 48, 1 == 49, 1-48 == 1
				}
				else {
					map[i][j] = sf::Vector2i(-1, -1);//draw background when x,x in file
				}
			}
		}


	}
	else {			//when can't open file with map structure
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++) {
				map[i][j] = sf::Vector2i(-1, -1);
			}
		counter.x = 20;
		counter.y = 20;
				
	}
}

void Map::makeShapes() {

	for (int i = 0; i < counter.y; i++)
		for (int j = 0; j < counter.x; j++) {
			if (map[i][j].x != -1 && map[i][j].y != -1) {

				shapes[i][j] = sf::Sprite();
				shapes[i][j].setPosition(sf::Vector2f(i*100.f, j*100.f));
				shapes[i][j].scale(4.f, 4.f);
				shapes[i][j].setTexture(texture);
				shapes[i][j].setColor(sf::Color(0, 0, 255));

			}

		}
}


Map::~Map()
{
	deleteArray(map, counter.y);
	deleteArray(shapes, counter.y);
}

//std::string str;
//file >> str;
//char x = str[0], y = str[2];
//if (!isdigit(x) || !isdigit(y)) {
//	map[counter.x][counter.y] = sf::Vector2i(-1, -1);	//draw background when x,x in file
//}
//else {
//	map[counter.x][counter.y] = sf::Vector2i(x - '0', y - '0');	//ASCI 0 == 48, 1 == 49, 1-48 == 1
//}


//if (file.peek() == '\n') {
//	counter.x = 0;
//	counter.y++;
//}
//else {
//	counter.x++;
//}
