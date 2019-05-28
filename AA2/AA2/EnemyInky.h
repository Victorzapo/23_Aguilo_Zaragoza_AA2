#pragma once
#include "Map.h"
#include"player.h"
#include "Constants.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <Windows.h>

class EnemyInky {

public:

	bool lastPointPoint = false;
	bool lastPointPower = false;
	bool hit = false;

	int i; //Column
	int j; //Row

	EnemyInky();

	EnemyInky(int i, int j, char **map); //inserts the enemy on the map

	void InkyMov(Map map, Player &player, bool keyboard[]); //Update the position of the enemy
};