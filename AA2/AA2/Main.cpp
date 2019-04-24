#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Map.h"
#include "player.h"
#include "Constants.h"




int main() {
	/////////////////////////////////// initializations ///////////////////////////
	//States
	bool pause = false;
	bool init = false;
	bool gameOver = false;
	//initialize the map with config.txt information
	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	int ROWS;
	int COLUMNS;

	Map map(ROWS, COLUMNS);

	//Player start
	Player player;

	player.i = 5;
	player.j = 5;

	/////////////////////////////// GAMELOOP /////////////////////////

	while (GetAsyncKeyState(VK_ESCAPE) == false) {

		if (pause) {
			
			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "PAUSED" << std::endl;
			std::cout <<"SCORE: " << player.score << std::endl;
			printMap(ROWS, COLUMNS, map.map);
			
			if (GetAsyncKeyState(0x50)) //Checks if "P" is presed
				pause = false;

			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "Press P to continue..." << std::endl;
			Sleep(75);
			system("CLS");
		}

		else if(init) {

			
			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "PLAYING" << std::endl;
			std::cout << "SCORE: " << player.score << std::endl;
			movementPlayer(player, map.map, ROWS, COLUMNS);
			printMap(ROWS, COLUMNS, map.map);
			
			if (GetAsyncKeyState(0x50)) //Checks if "P" is presed
				pause = true;

			Sleep(75);
			system("CLS"); //Cleans screen
		}
		else if (gameOver) {
			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "GAME OVER" << std::endl;

			printMap(ROWS, COLUMNS, map.map);
			
			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "Your Score was " << player.score << "!" << std::endl;
			std::cout << "Nice!! " << std::endl;
			Sleep(75);
			system("CLS");
		}
		else {
			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "Press spacebar to start..." << std::endl;
			if (GetAsyncKeyState(VK_SPACE))
				init = true;
			printMap(ROWS, COLUMNS, map.map);
			Sleep(75);
			system("CLS");
		}
	}
	return 0;

}