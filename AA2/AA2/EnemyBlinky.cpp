#include "EnemyBlinky.h"
#include "Constants.h"
#include "Map.h"
#include "player.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <Windows.h>

EnemyBlinky::EnemyBlinky() {

}

EnemyBlinky::EnemyBlinky(int i, int j, char **map) {
		map[i][j] = '#';
}

void EnemyBlinky::BlinkyMov(Map map, Player &player) {
	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	
	bool changeDirection = false;

	int aux;
	
	//Random position depending on the last one
	aux = rand() % 4;
	switch (aux)
		{
		case 0:
			if (prevDirection == DOWN) // Cant do a 180º turn on all movements 
				actDirection = DOWN;
			else
				actDirection = UP;

			break;
		case 1:
			if (prevDirection == UP)
				actDirection = UP;
			else
				actDirection = DOWN;

			break;
		case 2:
			if (prevDirection == RIGHT)
				actDirection = RIGHT;
			else
				actDirection = LEFT;

			break;
		case 3:
			if (prevDirection == LEFT)
				actDirection = LEFT;
			else
				actDirection = RIGHT;

			break;
		}
	

	//If the last position was a point it redraws it
	if (lastPoint)
		map.map[i][j] = '*';
	else
		map.map[i][j] = ' ';

	if (actDirection == UP) {

		if (map.map[i - 1][j] != mapChar) {
			i--;
			prevDirection = actDirection;
		}
		
		if (i < 1)
			i = map.COLUMNS + 1;
	}

	else if(actDirection == DOWN) {

		if (map.map[i + 1][j] != mapChar) {
			i++;
			prevDirection = actDirection;
		}

		if (i + 1 > map.COLUMNS + 1)
			i = 1;
	}

	else if(actDirection == LEFT){

		if (map.map[i][j - 1] != mapChar) {
			j--;
			prevDirection = actDirection;
		}
		
		if (j == 0) 
			j = map.ROWS - 1;
	}

	else if(actDirection == RIGHT){

		if (map.map[i][j + 1] != mapChar) {
			j++;
			prevDirection = actDirection;
		}

		if (j + 1 == map.ROWS)
			j = 0;
	}
	
	//Checks if the position is a point
	if (map.map[i][j] == '*')
		lastPoint = true;
	else
		lastPoint = false;


	if (i == player.i && j == player.j) { //Checks enemy hit
		player.lifes--;
		player.i = 5;
		player.j = 5;
		map.PrintMap();
		SetConsoleTextAttribute(consolehwnd, 15);
		std::cout << "Hit!";
		Sleep(2000);
		system("CLS");
	}

	map.map[i][j] = '#';
	
}

/*

void Enemy::InkyInitialPosition(Enemy Inky, char **map, int COLUMNS, int ROWS) {
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (map[i][j] == '&') {
				Inky.i = i;
				Inky.j = j;
			}
		}
	}
}
void Enemy::ClydeInitialPosition(Enemy Clyde, char **map, int COLUMNS, int ROWS) {
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (map[i][j] == '$') {
				Clyde.i = i;
				Clyde.j = j;
			}
		}
	}
}


*/





