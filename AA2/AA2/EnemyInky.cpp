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

void EnemyInky::InkyMov(Map map, Player &player) {

	//left 
	if (GetAsyncKeyState(VK_LEFT) && map.map[i][j - 1] != mapChar) {
		if (j == 0) {
			if (lastPoint)
				map.map[i][j] = '*';
			else
				map.map[i][j] = ' ';

			if (map.map[i][j] == '*')
				lastPoint = true;
			else
				lastPoint = false;

			j = map.ROWS - 1;
		}
		else {
			if (lastPoint)
				map.map[i][j] = '*';
			else
				map.map[i][j] = ' ';

			if (map.map[i][j] == '*')
				lastPoint = true;
			else
				lastPoint = false;
			j--;
		}
	}

	//down
	if (GetAsyncKeyState(VK_DOWN) && map.map[i + 1][j] != mapChar) {

		if (lastPoint)
			map.map[i][j] = '*';
		else
			map.map[i][j] = ' ';

		if (map.map[i][j] == '*')
			lastPoint = true;
		else
			lastPoint = false;

		i++;
	}

	//right
	if (GetAsyncKeyState(VK_RIGHT) && map.map[i][j + 1] != mapChar) {
		if (j + 1 == map.ROWS) {
			if (lastPoint)
				map.map[i][j] = '*';
			else
				map.map[i][j] = ' ';

			if (map.map[i][j] == '*')
				lastPoint = true;
			else
				lastPoint = false;
			j = 0;
		}
		else {
			j++;
		}
	}

	//up
	if (GetAsyncKeyState(VK_UP) && map.map[i - 1][j] != mapChar) {
		if (lastPoint)
			map.map[i][j] = '*';
		else
			map.map[i][j] = ' ';

		if (map.map[i][j] == '*')
			lastPoint = true;
		else
			lastPoint = false;
		i--;
	}


	map.map[i][j] = '&';
}



