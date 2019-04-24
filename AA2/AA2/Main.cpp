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

	Map map;

	
	int points = map.MaxPoints();

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
			map.PrintMap();
			
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
			player.movementPlayer(map.map, map.COLUMNS, map.ROWS);
			map.PrintMap();
			SetConsoleTextAttribute(consolehwnd, 15);
			player.printLifes();
			
			if (GetAsyncKeyState(0x50)) //Checks if "P" is presed
				pause = true;

			if (player.score == points || GetAsyncKeyState(VK_SPACE)) {
				player.lifes--;
				if (player.lifes == 0) {
					init = false;
					gameOver = true;
				}
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
			if(player.score <= 25% points && player.score >= 0)
				std::cout << "That was embarrassing... " << std::endl;

			else if (player.score <= 50% points && player.score > 25 % points)
				std::cout << "Close of being good... " << std::endl;

			else if(player.score <= 75 % points && player.score > 50 % points)
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