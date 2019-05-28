#include "EnemyInky.h"


EnemyInky::EnemyInky() {

}

EnemyInky::EnemyInky(int i, int j, char **map) {
	map[i][j] = '&';
}

void EnemyInky::InkyMov(Map map, Player &player, bool keyboard[]) {
	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);

	if (lastPointPoint) //if the last position was a point prints it
		map.map[i][j] = '*';
	else if(lastPointPower) //if the last position was a powerUp prints it
		map.map[i][j] = '0';
	else
		map.map[i][j] = ' ';

	hit = false;
	//left 
	if (keyboard[(int)InputKey::K_LEFT] && map.map[i][j - 1] != mapChar) {

		//Update Position (Same all movements)
		j--;

		//Tp (Same all movements)
		if (j < 0)
			j = map.COLUMNS - 1;

		//Colision (Same all movements)
		if (map.map[i][j] == '>' || map.map[i][j - 1] == '>' ){
			if (map.playerPw) {
				i = map.InkyIposi;
				j = map.InkyIposj;
				player.score += 15;
			}
			else
				hit = true;

		}


	}

	//down
	if (keyboard[(int)InputKey::K_DOWN] && map.map[i + 1][j] != mapChar) {

		i++;

		if (i + 1 > map.ROWS - 1)
			i = 1;

		else if (map.map[i][j] == '>' || map.map[i + 1][j] == '>') {
			if (map.playerPw) {

				i = map.InkyIposi;
				j = map.InkyIposj;
				player.score += 15;
			}
			else
				hit = true;

		}

	}

	//right
	if (keyboard[(int)InputKey::K_RIGHT] && map.map[i][j + 1] != mapChar) {


		j++;


		if (j == map.COLUMNS)
			j = 0;


		if (map.map[i][j] == '>' || map.map[i - 1][j] == '>') {
			if (map.playerPw) {

				i = map.InkyIposi;
				j = map.InkyIposj;
				player.score += 15;
			}
			else
				hit = true;

		}



		

	}

	//up
	if (keyboard[(int)InputKey::K_UP] && map.map[i - 1][j] != mapChar) {


		i--;


		if (i - 1 < 0)
			i = map.ROWS - 2;

		if (map.map[i][j] == '>' || map.map[i - 1][j] == '>') {
			if (map.playerPw) {

				i = map.InkyIposi;
				j = map.InkyIposj;
				player.score += 15;
			}
			else
				hit = true;

		}


		
	}


	if (player.i == i && player.j == j) { //If enemy is iddle
		if (map.playerPw) {

			i = map.InkyIposi;
			j = map.InkyIposj;
			player.score += 15;
		}
		else
			hit = true;

	}



	if (map.map[i][j] == '*') { // Checks if last posicion was a point
		lastPointPoint = true;
		lastPointPower = false;
	}
	else if (map.map[i][j] == '0') { // Checks if last posicion was a powerUp
		lastPointPower = true;
		lastPointPoint = false;
	}
	else {
		lastPointPoint = false;
		lastPointPower = false;

	}


	if (hit) { //Checks hit
		player.lifes--;
		map.PrintMap();
		map.map[player.i][player.j] = ' ';
		player.i = map.playerIposi;
		player.j = map.playerIposj;
		SetConsoleTextAttribute(consolehwnd, 15);
		std::cout << "Hit!";
		Sleep(2000);
		system("CLS");
	}


	map.map[i][j] = '&';
}



