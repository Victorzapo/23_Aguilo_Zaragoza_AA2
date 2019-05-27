#include "Map.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Constants.h"




Map::Map() {


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
			if (map[i][j] == '#') {
				BlinkyIposi = i;
				BlinkyIposj = j;
			}
			if (map[i][j] == '&') {
				InkyIposi = i;
				InkyIposj = j;
			}
			if (map[i][j] == '$') {
				ClydeIposi = i;
				ClydeIposj = j;
			}
			if (map[i][j] == '>') {
				playerIposi = i;
				playerIposj = j;
			}

		}
	}

}

void Map::PrintMap() {

	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	//system("color 1"); //Changes color to blue
	//SetConsoleTextAttribute(consolehwnd, FOREGROUND_BLUE);

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (map[i][j] == mapChar) {
				SetConsoleTextAttribute(consolehwnd, FOREGROUND_BLUE);
			}
			else if (map[i][j] == '#') {

				SetConsoleTextAttribute(consolehwnd, 4);

			}
			else if (map[i][j] == '&') {

				SetConsoleTextAttribute(consolehwnd, 3);

			}
			else if (playerPw && map[i][j] == '>') {

				SetConsoleTextAttribute(consolehwnd, 5);

			}
			else if (map[i][j] == '$') {

				SetConsoleTextAttribute(consolehwnd, 10);

			}
			else if (map[i][j] == '0') {

				SetConsoleTextAttribute(consolehwnd, 96);

			}
			else {
				SetConsoleTextAttribute(consolehwnd, 15);
			}
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

int Map::MaxPoints()
{
	int pointsCounter = 0;

	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
			if (map[i][j] == '*')
				pointsCounter++;
		
	return pointsCounter;
}

