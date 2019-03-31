#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Map.h"
#include "player.h"
#include "Constants.h"




int main() {
	/////////////////////////////////// initializations ///////////////////////////

	//initialize the map with config.txt information
	int ROWS;
	int COLUMNS;

	Map map(ROWS, COLUMNS);

	//Player start
	Player player;

	player.i = 5;
	player.j = 5;

	/////////////////////////////// GAMELOOP /////////////////////////

	while (GetAsyncKeyState(VK_ESCAPE) == false) {

		HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 15);

		std::cout << player.score << std::endl;
		movementPlayer(player, map.map, ROWS, COLUMNS);
		printMap(ROWS, COLUMNS, map.map, mapChar);
		Sleep(75);

		system("CLS"); //Cleans screen
	}
	return 0;

}