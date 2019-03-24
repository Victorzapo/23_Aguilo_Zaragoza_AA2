#include "Map.h"
#include <iostream>
#include <stdlib.h>

void initMap(char * map[], int ROWS, int COLUMNS)
{
	//Loads all map empty
	for (int i = 0; i < ROWS ; i++)
		for (int j = 0; j < COLUMNS ; j++) 
				map[i][j] = ' ';

	char mapChar = 219; // Character we use for walls (Hay que ponerlo en Constants.h)

	system("COLOR 1"); //Change color to blue


	//Laterals
	for (int i = 4; i < COLUMNS; i++) // |
		map[i][0] = mapChar;

	for (int i = 4; i < COLUMNS; i++) //        |
		map[i][ROWS - 1] = mapChar;

	//Verticals

	for (int j = 4; j < ROWS; j++) // ________
		map[0][j] = mapChar;
	
	for (int j = 4; j < ROWS - 1; j++) // --------
		map[COLUMNS - 1][j] = mapChar;
	
	//Test wall
	map[5][2] = mapChar;
	map[5][3] = mapChar;
	map[5][4] = mapChar;
	
	//Points where not wall
	for (int i = 1; i < ROWS - 1; i++) {
		for (int j = 1; j < COLUMNS - 1; j++) {
			if(map[i][j] != mapChar)
			map[i][j] = '*';
		}
	}


}

void printMap(char * map[], int ROWS, int COLUMNS)
{
	for (int i = 0; i < ROWS; i++) {
		std::cout << "\n";
		for (int j = 0; j < COLUMNS; j++)
			std::cout << map[i][j];
	}
}


