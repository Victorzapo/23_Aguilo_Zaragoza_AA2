#pragma once

struct Player
{
	int i = 5; //Column
	int j = 5; //Row

	int score = 0;
};


void movementPlayer(Player &player, char **map, int COLUMS, int ROWS);


#pragma once
