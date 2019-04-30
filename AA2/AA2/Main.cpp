#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Map.h"
#include "player.h"
#include "Constants.h"
#include "EnemyBlinky.h"
#include "EnemyInky.h"
#include "EnemyClyde.h"




int main() {
	srand(time(NULL));
	/////////////////////////////////// initializations ///////////////////////////
	//States
	bool pause = false;
	bool init = false;
	bool gameOver = false;
	//initialize the map with config.txt information
	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);

	Map map;


	int points = map.MaxPoints();

	//Player start
	Player player;

	player.i = 5;
	player.j = 5;

	EnemyBlinky Blinky(1, 1, map.map);
	Blinky.i = 1;
	Blinky.j = 1;

	EnemyInky Inky(7, 8, map.map);
	Inky.i = 7;
	Inky.j = 8;

	EnemyClyde Clyde(12, 8, map.map);
	Clyde.i = 12;
	Clyde.j = 8;

	
	/*Enemy Inky(1, 10, map.map, 2);
	Inky.i = 1;
	Inky.j = 10;

	Enemy Clyde(7, 10, map.map, 3);
	Clyde.i = 7;
	Clyde.j = 10;
	*/

	/*Enemy Blinky;
	Enemy Clyde;
	Enemy Inky;
	bool nextAstBlinky = true;
	bool nextAstInky = true;
	bool nextAstClyde = true;
	//Blinky.InitialPosition(Blinky, Inky, Clyde, map.map, map.COLUMNS, map.ROWS);
	Blinky.BlinkyInitialPosition(Blinky,map.map, map.COLUMNS, map.ROWS);
	Inky.InkyInitialPosition(Inky, map.map, map.COLUMNS, map.ROWS);
	Clyde.ClydeInitialPosition(Clyde, map.map, map.COLUMNS, map.ROWS);*/
	
	int direction = 4; //Hay que hacer el Enum
	int playerDir = 4; //Hay que hacer el Enum

	/////////////////////////////// GAMELOOP /////////////////////////

	while (GetAsyncKeyState(VK_ESCAPE) == false) {

		if (pause) {

			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "PAUSED" << std::endl;
			std::cout << "SCORE: " << player.score << std::endl;
			map.PrintMap();

			if (GetAsyncKeyState(0x50)) //Checks if "P" is presed
				pause = false;

			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "Press P to continue..." << std::endl;
			Sleep(75);
			system("CLS");
		}

		else if (init) {


			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "PLAYING" << std::endl;
			std::cout << "SCORE: " << player.score << std::endl;
			player.movementPlayer(map.map, map.COLUMNS, map.ROWS, playerDir);

			Blinky.BlinkyMov(map, player);
			Inky.InkyMov(map, player);
			Clyde.ClydeMov(map, player);
			//Inky.InkyMov(map.map, map.COLUMNS, map.ROWS, direction, nextAstInky, playerDir);
			//Clyde.ClydeMov(map.map, map.COLUMNS, map.ROWS, direction, nextAstClyde, playerDir);

			map.PrintMap();
			SetConsoleTextAttribute(consolehwnd, 15);
			player.printLifes();

			if (GetAsyncKeyState(0x50)) //Checks if "P" is presed
				pause = true;

			if (player.lifes == 0) { //Checks lifes of the player 
				init = false;
				gameOver = true;
			}


			Sleep(75);
			system("CLS"); //Cleans screen
		}
		else if (gameOver) {
			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "GAME OVER" << std::endl;

			map.PrintMap();

			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "Your Score was " << player.score << " of " << points << "!" << std::endl;
			if (player.score <= 25 % points && player.score >= 0)
				std::cout << "That was embarrassing... " << std::endl;

			else if (player.score <= 50 % points && player.score > 25 % points)
				std::cout << "Close of being good... " << std::endl;

			else if (player.score <= 75 % points && player.score > 50 % points)
				std::cout << "Good one! Half of the way! " << std::endl;

			else if (player.score < points && player.score > 75 % points)
				std::cout << "That was close as truck!" << std::endl;

			else
				std::cout << "Awesome! You win the Game!" << std::endl;
			Sleep(75);
			system("CLS");
		}
		else {
			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "Press spacebar to start..." << std::endl;
			if (GetAsyncKeyState(VK_SPACE))
				init = true;
			map.PrintMap();
			Sleep(75);
			system("CLS");
		}
	}


	return 0;

}