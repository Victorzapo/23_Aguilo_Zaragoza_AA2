#pragma once

struct Player
{
	int i; //Column
	int j; //Row

	int lifes = 3;
	int score = 0;

	void movementPlayer(char **map, int COLUMS, int ROWS, int &playerDir);
	void printLifes();
};





