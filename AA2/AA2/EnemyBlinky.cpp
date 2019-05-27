#include "EnemyBlinky.h"


EnemyBlinky::EnemyBlinky() {

}

EnemyBlinky::EnemyBlinky(int i, int j, char **map) {
		map[i][j] = '#';
}

void EnemyBlinky::BlinkyMov(Map map, Player &player) {
	HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	int aux;
	
	bool hit = false;

	if (lastPointPoint) //if the last position was a point it prints it
		map.map[i][j] = '*';
	else if (lastPointPower)
		map.map[i][j] = '0';
	else
		map.map[i][j] = ' ';


	

	

	bool canMove = false;
	do {
		aux = rand() % 4 + 1;
		if (aux == 1 && lastDirection != 3 && map.map[i - 1][j] != mapChar) canMove = true;
		else if (aux == 2 && lastDirection != 4 && map.map[i][j + 1] != mapChar) canMove = true;
		else if (aux == 3 && lastDirection != 1 && map.map[i + 1][j] != mapChar) canMove = true;
		else if (aux == 4 && lastDirection != 2 && map.map[i][j - 1] != mapChar) canMove = true;
		else canMove = false;

	} while (!canMove);


	
	switch (aux)
	{
	case 1: //UP
		lastDirection = 1;
		i--;
		

		if (map.map[i][j] == '>' || map.map[i - 1][j] == '>') {
			if (map.playerPw) {

				i = map.BlinkyIposi;
				j = map.BlinkyIposj;   

				player.score += 15;

			}
			else
				hit = true;
	
		}

		if (i - 1 < 0)
			i = map.ROWS - 2;

		

		break;
	case 2: //RIGHT
		lastDirection = 2;
		j++; 


		if (j == map.COLUMNS)
			j = 0;
		
		if (map.map[i][j] == '>' || map.map[i][j + 1] == '>') {
			if (map.playerPw) {

				i = map.BlinkyIposi;
				j = map.BlinkyIposj;
				player.score += 15;
			}
			else
				hit = true;

		}

		break;
	case 3: //DOWN
		lastDirection = 3;
		i++;
		
		
		if (i + 1 > map.ROWS - 1)
			i = 1;
		else if (map.map[i][j] == '>' || map.map[i + 1][j] == '>') {
			if (map.playerPw) {

				i = map.BlinkyIposi;
				j = map.BlinkyIposj;
				player.score += 15;
			}
			else
				hit = true;

		}
		
		

		

		break;
	case 4: //LEFT
		lastDirection = 4;
		j--;
		
		if (j == 0)
			j = map.COLUMNS - 1;

		if (map.map[i][j] == '>' || map.map[i][j - 1] == '>') {
			if (map.playerPw) {

				i = map.BlinkyIposi;
				j = map.BlinkyIposj;
				player.score += 15;
			}
			else
				hit = true;

		}

		break;

	default:
		break;
	}
	
	if (map.map[i][j] == '*') { // Checks if last posicion was a point
		lastPointPoint = true;
		lastPointPower = false;
	}
	else if (map.map[i][j] == '0') {
		lastPointPower = true;
		lastPointPoint = false;
	}
	else {
		lastPointPoint = false;
		lastPointPower = false;

	}

	if (hit) { //Checks enemy hit
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

	map.map[i][j] = '#';
}




















