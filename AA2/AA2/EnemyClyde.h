#pragma once
#include "Map.h"
#include "player.h"
#include "Constants.h"
#include <Windows.h>
#include <iostream>


class EnemyClyde {

public:

	bool lastPointPoint = false;
	bool lastPointPower = false;
	bool hit = false;

	int i; //Column
	int j; //Row

	EnemyClyde();

	EnemyClyde(int i, int j, char **map); //inserts the enemy on the map

	void ClydeMov(Map map, Player &player, bool keyboard[]); //Updates the position of the enemy
};