#include "player.h"
#include  <Windows.h>
#include "Types.h"
#include "Constants.h"
#include <iostream>

void Player::movementPlayer(char **map, int COLUMS, int ROWS, int &playerDir)
{

	if (GetAsyncKeyState(VK_LEFT) && map[i][j - 1] != mapChar) { //Left movement

		map[i][j] = ' '; //Emptys the actual position (Same on all movements
		playerDir = 0; //saves player direction 

		if (map[i][j - 1] == '*') //Checks if points (Same on all movements)
			score++; //Update score if points (Same on all movements)

		if (j == 0) //Limit check (Same on all movements)
			j = ROWS - 1; //New position if is on the limit (Same on all movements)

		else
			j--; //If its not on the limit updates position (Same on all movements)
	}

	else if (GetAsyncKeyState(VK_RIGHT) && map[i][j + 1] != mapChar) //Right movement
	{
		map[i][j] = ' ';
		playerDir = 2;

		if (map[i][j + 1] == '*')
			score++;
		if (j + 1 == ROWS)
			j = 0;
		else
			j++;
	}

	else if (GetAsyncKeyState(VK_UP) && map[i - 1][j] != mapChar) //Up movement 
	{
		map[i][j] = ' ';
		playerDir = 3;

		if (map[i - 1][j] == '*')
		{
			score++;
			i--;
		}
		else if (i - 1 < 1)
			i = ROWS;
		else
			i--;
	}
	if (GetAsyncKeyState(VK_DOWN) && map[i + 1][j] != mapChar) //Down movement
	{
		map[i][j] = ' ';
		playerDir = 1;

		if (map[i + 1][j] == '*') {
			score++;
			i++;
		}
		else if (i > ROWS - 1)
			i = 1;
		else
			i++;
	}


	map[i][j] = '>'; //Puts player on a update position
}

void Player::printLifes()
{

	std::cout << "LIVES";

	for (int i = 0; i < lifes; i++) {
		std::cout << mapChar << " ";
	}

}