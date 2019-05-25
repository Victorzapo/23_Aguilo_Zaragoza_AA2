#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Map.h"
#include "player.h"
#include "Constants.h"
#include "EnemyBlinky.h"
#include "EnemyInky.h"
#include "EnemyClyde.h"
#include "Keyboard.h"

int main() {
	srand(time(NULL));
	/////////////////////////////////// initializations ///////////////////////////
	int direction = 4; 
	bool nextAstBlinky = true;


	//States
	bool keyboard[(int)InputKey::COUNT] = {false};

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

	
	

	/////////////////////////////// GAMELOOP /////////////////////////
	while (!keyboard[(int)InputKey::K_ESC]) {
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

			keyBoardControl(keyboard);

			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "PLAYING" << std::endl;
			std::cout << "SCORE: " << player.score << std::endl;
			player.movementPlayer(map, keyboard);
			Clyde.ClydeMov(map, player, keyboard);

			Blinky.BlinkyMov(map, player);
			Inky.InkyMov(map, player, keyboard);
			

			if (keyboard[(int)InputKey::K_PAUSE]) //Checks if "P" is presed
				pause = true;

			if (player.lifes == 0) { //Checks lifes of the player 
				init = false;
				gameOver = true;
			}
			

			map.PrintMap();
			SetConsoleTextAttribute(consolehwnd, 15);
			player.printLifes();

			


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