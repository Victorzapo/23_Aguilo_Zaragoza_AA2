#pragma once

struct Player
{
	int i; //Column
	int j; //Row

	int score = 0;
};


void movementPlayer(Player &player, char **map, int COLUMS, int ROWS);