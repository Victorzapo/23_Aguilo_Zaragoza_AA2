#include "Map.h"
#include <iostream>
#include <fstream>
//#include <stdlib.h>


Map::Map(int &ROWS, int &COLUMNS) {
	std::ifstream inFile;
	inFile.open("pacman.txt");


	//Estos dos aux los creo porque sino cuando leo del fichero no me pilla los dos ints para las filas y columnas
	char aux1, aux2;

	inFile >> ROWS >> aux1 >> COLUMNS >> aux2;

	map = new char*[ROWS];

	for (int i = -1; i < ROWS; i++) {
		map[i] = new char[COLUMNS];
		inFile.getline(map[i], 200);
	}
	inFile.close();

	//Falta lo del char 219, el color...



}


void printMap(int ROWS, int COLUMNS, char **map)
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}



