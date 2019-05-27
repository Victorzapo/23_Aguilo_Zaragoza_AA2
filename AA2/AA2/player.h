#pragma once
#include <iostream>
#include "Map.h"
#include "Constants.h"



struct Player
{
	int i; //Column
	int j; //Row

	int lifes = 3;
	int score = 0;
	int RecPoints = 0;

	void movementPlayer(Map &map, bool keyboard[]);
	void printLifes();
};





