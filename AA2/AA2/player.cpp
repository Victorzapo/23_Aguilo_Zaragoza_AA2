#include "player.h"
#include  <Windows.h>
#include "Types.h"

void movementPlayer(Player &player, char **map, int COLUMS, int ROWS)
{
	char mapChar = 219; //(Hay que ponerlo en Constants.h)

	if (GetAsyncKeyState(VK_LEFT) && map[player.i][player.j - 1] != mapChar) //Left movement
	{
		map[player.i][player.j] = ' '; //Emptys the actual position (Same on all movements)

		if (map[player.i][player.j - 1] == '*') //Checks if points (Same on all movements)
			player.score++; //Update score if points (Same on all movements)


		if (player.j - 1 < 0) //Limit check (Same on all movements)
			player.j = COLUMS - 1; //New position if is on the limit (Same on all movements)
		else
			player.j--; //If its not on the limit updates position (Same on all movements)
	}

	else if (GetAsyncKeyState(VK_RIGHT) && map[player.i][player.j + 1] != mapChar) //Right movement
	{
		map[player.i][player.j] = ' ';

		if (map[player.i][player.j + 1] == '*')
			player.score++;

		if (player.j + 1 == COLUMS)
			player.j = 0;
		else
			player.j++;
	}

	//Limites verticales hay que pulirlos, dan algunos errores

	else if (GetAsyncKeyState(VK_UP) && map[player.i - 1][player.j] != mapChar) //Up movement 
	{
		map[player.i][player.j] = ' ';

		if (map[player.i - 1][player.j] == '*')
			player.score++;

		if (player.i - 1 < 1)
			player.i = ROWS - 1;
		else
			player.i--;
	}

	else if (GetAsyncKeyState(VK_DOWN) && map[player.i + 1][player.j] != mapChar) //Down movement
	{
		map[player.i][player.j] = ' ';

		if (map[player.i + 1][player.j] == '*')
			player.score++;

		if (player.i + 1 == ROWS - 1)
			player.i = 0;
		else
			player.i++;
	}

	map[player.i][player.j] = '>'; //Puts player on a update position
}
