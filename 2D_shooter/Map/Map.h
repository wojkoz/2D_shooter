#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>
#include "../Collisions/Collision.h"
//TODO:
//przerobic loadMap() i makeShapes() �eby rozmiar tablic sie zmienia� + dodaj funkcje do zmieniania rozmiaru dla map
class Map
{
public:
	Map();
	std::vector<std::vector<sf::Sprite>> shapes;
	int getMapX();
	int getMapY();
	int getShapeRows();		//rows
	int getShapeCols();		//cols
	~Map();
private:
	void loadMap();
	void makeShapes();

	template <class T> T** makeArray(int n, int m);	//creates basic array 20x20
	template <class T> void deleteArray(T array, int n);//destroys array

	std::fstream file;
	//sf::Vector2i **map;
	std::vector<std::vector<sf::Vector2i>> map;
	sf::Vector2i counter;
	sf::Texture texture;

	
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
