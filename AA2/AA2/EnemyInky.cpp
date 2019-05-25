#include "EnemyInky.h"
#include "Constants.h"
#include "Map.h"
#include "player.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <Windows.h>

EnemyInky::EnemyInky() {

}

EnemyInky::EnemyInky(int i, int j, char **map) {
	map[i][j] = '&';
}

void EnemyInky::InkyMov(Map map, Player &player, bool keyboard[]) {
	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);

	if (lastPoint) //if the last position was a point it prints it
		map.map[i][j] = '*';
	else
		map.map[i][j] = ' ';

	hit = false;
	//left 
	if (keyboard[(int)InputKey::K_LEFT] && map.map[i][j - 1] != mapChar) {

		j--;

		if (j < 0)
			j = map.COLUMNS - 1;

		if (map.map[i][j] == '>' || map.map[i][j - 1] == '>')
			hit = true;


	}

	//down
	if (keyboard[(int)InputKey::K_DOWN] && map.map[i + 1][j] != mapChar) {

		i++;

		if (i + 1 > map.ROWS - 1)
			i = 1;
		else if (map.map[i][j] == '>' || map.map[i + 1][j] == '>')
			hit = true;

	}

	//right
	if (keyboard[(int)InputKey::K_RIGHT] && map.map[i][j + 1] != mapChar) {


		j++;


		if (map.map[i][j] == '>' || map.map[i - 1][j] == '>')
			hit = true;


		if (j == map.COLUMNS)
			j = 0;


	}

	//up
	if (keyboard[(int)InputKey::K_UP] && map.map[i - 1][j] != mapChar) {


		i--;


		if (map.map[i][j] == '>' || map.map[i - 1][j] == '>')
			hit = true;

		if (i - 1 < 0)
			i = map.ROWS - 2;
	}



	if (map.map[i][j] == '*') // Checks if last posicion was a point
		lastPoint = true;
	else
		lastPoint = false;

	if (hit) { //Checks enemy hit
		player.lifes--;
		map.PrintMap();
		map.map[player.i][player.j] = ' ';
		player.i = 5;
		player.j = 5;
		SetConsoleTextAttribute(consolehwnd, 15);
		std::cout << "Hit!";
		Sleep(2000);
		system("CLS");
	}


	map.map[i][j] = '&';
}



