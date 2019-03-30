#include "Map.h"
#include <iostream>
#include <fstream>
#include <windows.h>
//#include <stdlib.h>



Map::Map(int &ROWS, int &COLUMNS) {

	

	std::ifstream inFile;
	inFile.open("config.txt");


	//Estos dos aux los creo porque sino cuando leo del fichero no me pilla los dos ints para las filas y columnas
	char aux1, aux2;

	inFile >> ROWS >> aux1 >> COLUMNS >> aux2;

	map = new char*[ROWS];

	for (int i = -1; i < ROWS; i++) {
		map[i] = new char[COLUMNS];
		inFile.getline(map[i], 200);
	}
	inFile.close();

	for (int i = 0; i < ROWS; i++) { //Changes all 'X' for walls
		for (int j = 0; j < COLUMNS; j++) {
			if (map[i][j] == 'X')
				map[i][j] = 219;
		}
	}
}

	void printMap(int ROWS, int COLUMNS, char **map) {

		system("color 1"); //Changes color to blue

		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS; j++) 
				std::cout << map[i][j];
			std::cout << std::endl;
		}
	}



