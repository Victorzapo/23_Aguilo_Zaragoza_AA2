#include "Map.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Constants.h"



Map::Map(int &ROWS, int &COLUMNS) {


	//Reads infortmation and fills the Dynarray
	std::ifstream inFile;
	inFile.open("config.txt");

	char aux1, aux2;

	inFile >> ROWS >> aux1 >> COLUMNS >> aux2;

	map = new char*[ROWS];

	for (int i = -1; i < ROWS; i++) {
		map[i] = new char[COLUMNS];
		inFile.getline(map[i], 200);
	}
	inFile.close();

	//Changes all 'X' for walls
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (map[i][j] == 'X')
				map[i][j] = mapChar;
		}
	}


	




}


void printMap(int ROWS, int COLUMNS, char **map) {

	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	//system("color 1"); //Changes color to blue
	//SetConsoleTextAttribute(consolehwnd, FOREGROUND_BLUE);

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (map[i][j] == mapChar) {
				SetConsoleTextAttribute(consolehwnd, FOREGROUND_BLUE);
			}
			else {
				SetConsoleTextAttribute(consolehwnd, 15);
			}
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

int maxPoints(int ROWS, int COLUMNS, char ** map)
{
	int pointsCounter = 0;
	
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (map[i][j] == '*')
				pointsCounter++;
		}
	}
	return pointsCounter;
}

