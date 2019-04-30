#include "Enemy.h"
#include <cstdlib>
#include<time.h>
#include "Constants.h"
#include <iostream>
#include  <Windows.h>

Enemy::Enemy() {

}

Enemy::Enemy(int i, int j, char **map, int type) {
	if (type == 1) { //blinky
		map[i][j] = '#';
	}
	else if (type == 2) { //Inky
		map[i][j] = '&';
	}
	else if (type == 3) { //Clyde
		map[i][j] = '$';
	}

}

void Enemy::BlinkyMov(char **map, int COLUMNS, int ROWS, int &direction, bool &nextAst) {
	srand(time(NULL));
	bool changeDirection = false;
	int Prevdirection = direction; //direccion anterior 
	//std::cout << i << ' ' << j << std::endl;


	if (
		//2 lados libres no alineados
		(map[i][j + 1] != mapChar && map[i - 1][j] != mapChar) ||
		(map[i][j + 1] != mapChar && map[i + 1][j] != mapChar) ||
		(map[i - 1][j] != mapChar && map[i][j - 1] != mapChar) ||
		(map[i][j - 1] != mapChar && map[i + 1][j] != mapChar) ||

		//4 lados libres
		((map[i][j + 1] != mapChar && map[i - 1][j] != mapChar) && (map[i][j - 1] != mapChar && map[i + 1][j] != mapChar)) ||

		//3 lados libres
		((map[i - 1][j] != mapChar) && (map[i][j - 1] != mapChar && map[i + 1][j] != mapChar)) ||
		((map[i][j + 1] != mapChar) && (map[i][j - 1] != mapChar && map[i + 1][j] != mapChar)) ||
		((map[i][j + 1] != mapChar && map[i - 1][j] != mapChar) && (map[i + 1][j] != mapChar)) ||
		((map[i][j + 1] != mapChar && map[i - 1][j] != mapChar) && (map[i][j - 1] != mapChar))
		) {

		changeDirection = true;
	}

	if (changeDirection) { //si ha entrado en un caso especial de los de arriba  cambiamos la direccion a un random entre 0 y 3
		do {
			direction = rand() % 3;
		} while (direction == Prevdirection);//mientras la direccion que salga no sea igual a la anterior
	}
	//direction: 0-left 1-down 2-right 3-up

	//left
	if ((direction == 0)) {
		//IMPORTANTE:lo de mirar la direccion anterior deberia estar entre el if de direccion y este
		if (map[i][j - 1] != mapChar && Prevdirection != 2) { //mira si la siguiente posicion no es un muro && mira que la dirección anterior no sea contraria a esta
			if (nextAst == true) {//si la anterior interaccion habia un * en esta posicion lo vuelve a printear
				map[i][j] = '*';
			}
			else {
				map[i][j] = ' ';
			}
			if (j == 0) {//si esta en la primera posicion de la j lo pone el la ultima (teletransporte)
				if (map[i][ROWS - 1] == '*') {//mira si en el sitio donde se pondra hay un *
					nextAst = true;
				}
				else {
					nextAst = false;
				}
				j = ROWS - 1;
			}
			else {//si no es el caso especial del teletransporte decrementa una posicion en la j
				if (map[i + 1][j] == '*') {////mira si en el sitio donde se pondra hay un *
					nextAst = true;
				}
				else {
					nextAst = false;
				}
				j--;
			}
		}
		else {
			direction = 1;//si no cumple el If importante cambia la direccion que tendra para ver si es factible
			if (direction == Prevdirection) {//en el caso de que esta nueva direccion sea igual a la de la anterior interaccion se le da otra distinta
				direction = 2;
			}
		}
	}

	//down
	if ((direction == 1)) {
		if (map[i + 1][j] != mapChar && Prevdirection != 3) {
			if (nextAst == true) {
				map[i][j] = '*';
			}
			else {
				map[i][j] = ' ';
			}
			if (i > COLUMNS - 1) {
				if (map[1][j] == '*') {
					nextAst = true;
				}
				else {
					nextAst = false;
				}
				i = 1;
			}
			else {
				if (map[i + 1][j] == '*') {
					nextAst = true;
				}
				else {
					nextAst = false;
				}
				i++;
			}
		}
		else {
			direction = 2;
			if (direction == Prevdirection) {
				direction = 3;
			}
		}
	}

	//right
	if ((direction == 2)) {
		if (map[i][j + 1] != mapChar && Prevdirection != 0) {
			if (nextAst == true) {
				map[i][j] = '*';
			}
			else {
				map[i][j] = ' ';
			}
			if (j + 1 == ROWS) {
				if (map[i][0] == '*') {
					nextAst = true;
				}
				else {
					nextAst = false;
				}
				j = 0;
			}
			else {
				if (map[i + 1][j] == '*') {
					nextAst = true;
				}
				else {
					nextAst = false;
				}
				j++;
			}
		}
		else {
			direction = 3;
			if (direction == Prevdirection) {
				direction = 0;
			}
		}
	}

	//up
	if ((direction == 3)) {
		if (map[i - 1][j] != mapChar && Prevdirection != 1) {
			if (nextAst == true) {
				map[i][j] = '*';
			}
			else {
				map[i][j] = ' ';
			}
			if (i - 1 < 1) {
				if (map[COLUMNS][j] == '*') {
					nextAst = true;
				}
				else {
					nextAst = false;
				}
				i = COLUMNS;
			}
			else {
				if (map[i + 1][j] == '*') {
					nextAst = true;
				}
				else {
					nextAst = false;
				}
				i--;
			}
		}
		else {
			direction = 0;
			if (direction == Prevdirection) {
				direction = 1;
			}
		}
	}

	map[i][j] = '#';
}

void Enemy::InkyMov(char **map, int COLUMNS, int ROWS, int &direction, bool &nextAst, int & playerDir) {

	//left 
	if (GetAsyncKeyState(VK_LEFT) && map[i][j - 1] != mapChar) {
		if (nextAst == true) {
			map[i][j] = '*';
		}
		else {
			map[i][j] = ' ';
		}
		j--;
	}

	//down
	if (GetAsyncKeyState(VK_DOWN) && map[i + 1][j] != mapChar) {
		if (nextAst == true) {
			map[i][j] = '*';
		}
		else {
			map[i][j] = ' ';
		}
		i++;
	}

	//right
	if (GetAsyncKeyState(VK_RIGHT) && map[i][j + 1] != mapChar) {
		if (nextAst == true) {
			map[i][j] = '*';
		}
		else {
			map[i][j] = ' ';
		}
		j++;
	}

	//up
	if (GetAsyncKeyState(VK_UP) && map[i - 1][j] != mapChar) {
		if (nextAst == true) {
			map[i][j] = '*';
		}
		else {
			map[i][j] = ' ';
		}
		i--;
	}


	map[i][j] = '&';
}

void Enemy::ClydeMov(char **map, int COLUMNS, int ROWS, int &direction, bool &nextAst, int & playerDir) {
	//podemos qiter direction y playerDir de todo menos de Blinky

	//left 
	if (GetAsyncKeyState(VK_RIGHT) && map[i][j - 1] != mapChar) {
		if (nextAst == true) {
			map[i][j] = '*';
		}
		else {
			map[i][j] = ' ';
		}
		j--;
	}

	//down
	if (GetAsyncKeyState(VK_UP) && map[i + 1][j] != mapChar) {
		if (nextAst == true) {
			map[i][j] = '*';
		}
		else {
			map[i][j] = ' ';
		}
		i++;
	}

	//right
	if (GetAsyncKeyState(VK_LEFT) && map[i][j + 1] != mapChar) {
		if (nextAst == true) {
			map[i][j] = '*';
		}
		else {
			map[i][j] = ' ';
		}
		j++;
	}

	//up
	if (GetAsyncKeyState(VK_DOWN) && map[i - 1][j] != mapChar) {
		if (nextAst == true) {
			map[i][j] = '*';
		}
		else {
			map[i][j] = ' ';
		}
		i--;
	}


	map[i][j] = '$';
}

void Enemy::InitialPosition(Enemy Blinky, Enemy Inky, Enemy Clyde, char **map, int COLUMNS, int ROWS) {

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (map[i][j] == '#') {
				Blinky.i = i;
				Blinky.j = j;
			}
			if (map[i][j] == '&') {
				Inky.i = i;
				Inky.j = j;
			}
			if (map[i][j] == '$') {
				Clyde.i = i;
				Clyde.j = j;
			}
		}
	}

}

void Enemy::BlinkyInitialPosition(Enemy Blinky, char **map, int COLUMNS, int ROWS) {
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (map[i][j] == '#') {
				Blinky.i = i;
				Blinky.j = j;
			}
		}
	}
}
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








