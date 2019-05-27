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
#include "Ranking.h"

int main() {
	srand(time(NULL));
	/////////////////////////////////// initializations ///////////////////////////
	int direction = 4; 
	bool nextAstBlinky = true;

	//Ranking
	
	Ranking ranking;


	//PowerUp
	clock_t startTime;
	bool timerUp = false;
	double secondsPassed;

	//States
	bool keyboard[(int)InputKey::COUNT] = {false};
	GameState gameState = GameState::SPLASH_SCREEN;

	

	bool pause = false;
	bool init = false;
	bool gameOver = false; 
	//initialize the map with config.txt information
	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);

	Map map;


	int points = map.MaxPoints();

	//Player and enemys initialization
	Player player;

	player.i = map.playerIposi;
	player.j = map.playerIposj;

	EnemyBlinky Blinky(map.BlinkyIposi, map.BlinkyIposj, map.map);
	Blinky.i = map.BlinkyIposi;
	Blinky.j = map.BlinkyIposj;

	EnemyInky Inky(map.InkyIposi, map.InkyIposj, map.map);
	Inky.i = map.InkyIposi;
	Inky.j = map.InkyIposj;

	EnemyClyde Clyde(map.ClydeIposi, map.ClydeIposj, map.map);
	Clyde.i = map.ClydeIposi;
	Clyde.j = map.ClydeIposj;

	
	

	/////////////////////////////// GAMELOOP /////////////////////////
	while (gameState != GameState::EXIT) {

		switch (gameState)
		{
		case GameState::SPLASH_SCREEN:

			
			SetConsoleTextAttribute(consolehwnd, 96);
			std::cout << "*-*-*-PAC-MAN-*-*-*" << std::endl;
			std::cout << "By: Victor Zaragoza " << std::endl;

			Sleep(3000);

			gameState = GameState::MAIN_MENU;

			SetConsoleTextAttribute(consolehwnd, 1);
			system("CLS");

			break;

		case GameState::MAIN_MENU:

			keyBoardControl(keyboard);
			
			SetConsoleTextAttribute(consolehwnd, 96);
			std::cout << "*-*-*-MAIN MENU-*-*-*" << std::endl;

			SetConsoleTextAttribute(consolehwnd, 10);
			std::cout << "1 - Play" << std::endl;

			SetConsoleTextAttribute(consolehwnd, 3);
			std::cout << "2 - Ranking" << std::endl;

			SetConsoleTextAttribute(consolehwnd, 4);
			std::cout << "0 - Exit" << std::endl;

			if (keyboard[(int)InputKey::K_GAME_START])
				gameState = GameState::GAME;
			else if (keyboard[(int)InputKey::K_RANKING])
				gameState = GameState::RANKING;
			else if (keyboard[(int)InputKey::K_EXIT] || keyboard[(int)InputKey::K_ESC])
				gameState = GameState::EXIT;

			Sleep(75);
			system("CLS");



			break;

		case GameState::GAME:

			keyBoardControl(keyboard);

			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "PLAYING" << std::endl;
			std::cout << "SCORE: " << player.score << std::endl;
			
			player.movementPlayer(map, keyboard);

			Blinky.BlinkyMov(map, player);
			Inky.InkyMov(map, player, keyboard);
			Clyde.ClydeMov(map, player, keyboard);

			if (map.playerPw == true && timerUp == false) {
				startTime = clock();
				timerUp = true;
			}
	
			if (timerUp) {
				secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;
				if (secondsPassed == 7) {
					map.playerPw = false;
					timerUp = false;
				}
			}
			


			if (keyboard[(int)InputKey::K_PAUSE]) //Checks if "P" is presed
				gameState = GameState::PAUSE;
			else if (keyboard[(int)InputKey::K_ESC])
				gameState = GameState::MAIN_MENU;

			if (player.lifes == 0) //Checks lifes of the player 
				gameState = GameState::GAME_OVER;

			else if (player.RecPoints == points)
				gameState = GameState::GAME_OVER;


			map.PrintMap();
			SetConsoleTextAttribute(consolehwnd, 15);
			player.printLifes();




			Sleep(75);
			system("CLS"); //Cleans screen

			break;

		case GameState::RANKING:
			keyBoardControl(keyboard);

			SetConsoleTextAttribute(consolehwnd, 96);
			std::cout << "*-*-*-RANKING-*-*-*" << std::endl;


			SetConsoleTextAttribute(consolehwnd, 0);
			ranking.printRanking();
			
			

			if (keyboard[(int)InputKey::K_ESC])
				gameState = GameState::MAIN_MENU;
			keyboard[(int)InputKey::K_ESC] = false;

			Sleep(75);
			system("CLS");
			break;

		case GameState::GAME_OVER:

			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "GAME OVER" << std::endl;

			map.PrintMap();

			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "Your Score was " << player.score << "! There were " << points << "!" << std::endl;
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
			Sleep(3000);


			ranking.addPS(player.score);

			gameState = GameState::RANKING;
			system("CLS");

			break;

		case GameState::PAUSE:

			keyBoardControl(keyboard);


			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "PAUSED" << std::endl;
			std::cout << "SCORE: " << player.score << std::endl;
			map.PrintMap();

			if (keyboard[(int)InputKey::K_PAUSE]) //Checks if "P" is presed
				gameState = GameState::GAME;

			SetConsoleTextAttribute(consolehwnd, 15);
			std::cout << "Press P to continue..." << std::endl;
			Sleep(75);
			system("CLS");

			break;

		default:
			break;
		}

	}


	return 0;

}