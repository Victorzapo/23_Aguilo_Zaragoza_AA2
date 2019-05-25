#pragma once
#include "Map.h"

struct Player
{
	int i; //Column
	int j; //Row

	int lifes = 3;
	int score = 0;

	void movementPlayer(Map map, bool key[]);
	void printLifes();
};





