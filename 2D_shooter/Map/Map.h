#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>
//TODO:
//przerobic loadMap() i makeShapes() ¿eby rozmiar tablic sie zmienia³ + dodaj funkcje do zmieniania rozmiaru dla map
class Map
{
public:
	Map();
	sf::RectangleShape **shapes;
	int getMapX();
	int getMapY();
	~Map();
private:
	void loadMap();
	void makeShapes();

	template <class T> T** makeArray(int n, int m);	//creates basic array 20x20
	template <class T> void deleteArray(T array, int n);//destroys array

	std::fstream file;
	sf::Vector2i **map;
	sf::Vector2i counter;

	
};

template<class T>
inline T ** Map::makeArray(int n, int m)
{
	T ** array = new T  *[n];
	for (int i = 0; i < n; i++) {
		array[i] = new T[m];
	}

	return array;
}

template<class T>
inline void Map::deleteArray(T array, int n)
{
	for (int i = 0; i < n; ++i) {
		delete[] array[i];
	}
	delete[] array;

}
