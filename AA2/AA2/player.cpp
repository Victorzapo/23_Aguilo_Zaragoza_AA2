#include "player.h"
#include "Constants.h"
#include <iostream>


void Player::movementPlayer(Map map, bool keyboard[])
{

	if (keyboard[(int)InputKey::K_LEFT] && map.map[i][j - 1] != mapChar) { //Left movement

		map.map[i][j] = ' '; //Emptys the actual position (Same on all movements

		if (map.map[i][j - 1] == '*') //Checks if points (Same on all movements)
			score++; //Update score if points (Same on all movements)

		if (j == 0) //Limit check (Same on all movements)
			j = map.COLUMNS - 1; //New position if is on the limit (Same on all movements)

		else
			j--; //If its not on the limit updates position (Same on all movements)
	}

	else if (keyboard[(int)InputKey::K_RIGHT] && map.map[i][j + 1] != mapChar) //Right movement
	{
		map.map[i][j] = ' ';
	
		if (map.map[i][j + 1] == '*')
			score++;
		if (j + 1 == map.COLUMNS)
			j = 0;
		else
			j++;
	}

	else if (keyboard[(int)InputKey::K_UP] && map.map[i - 1][j] != mapChar) //Up movement 
	{
		map.map[i][j] = ' ';
	

		if (map.map[i - 1][j] == '*')
		{
			score++;
			i--;
		}
		else if (i - 1 < 1)
			i = map.ROWS - 2;
		else
			i--;
	}

	else if (keyboard[(int)InputKey::K_DOWN] && map.map[i + 1][j] != mapChar) //Down movement
	{
		map.map[i][j] = ' ';
		

		if (map.map[i + 1][j] == '*') {
			score++;
			i++;
		}
		else if (i + 1 > map.ROWS - 2)
			i = 1;
		else
			i++;
	}
	
	

	map.map[i][j] = '>'; //Puts player on a update position
}

void Player::printLifes()
{

	std::cout << "LIVES";

	for (int i = 0; i < lifes; i++) {
		std::cout << mapChar << " ";
	}

}