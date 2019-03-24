#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Map.h"
#include "player.h"


Player player;


int main() {


	
	
	/////////////////////////////////// MAP ////////////////////////
	//Variables of the map

	// Falta implementar la lectura del fichero config.txt
	const int ROWS = 20;  //Row test
	const int COLUMNS = 20; //Colum test
	
	//Map declaration
	char **map;
	map = new char*[ROWS];
	for (int i = 0; i < ROWS; i++)
		map[i] = new char[COLUMNS];

	initMap(map, ROWS, COLUMNS);


	/////////////////////////////// GAMELOOP ////////////////////////

	while (GetAsyncKeyState(VK_ESCAPE) == false) {
		
		std::cout << player.score;
		movementPlayer(player, map, ROWS, COLUMNS);
		printMap(map, ROWS, COLUMNS);
		Sleep(500);
		
		system("CLS"); //Cleans screen
	}
	return 0;
	
}