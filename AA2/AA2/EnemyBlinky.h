#pragma once
#include "Map.h"
#include"player.h"
#include "Constants.h"
#include <iostream>
#include <Windows.h>

class EnemyBlinky {

public:

	enum directonMov {COUNT, UP, RIGHT, DOWN, LEFT};
	
	bool lastPointPoint = false;
	bool lastPointPower = false;
	bool changeDirection = false;
	int lastDirection = 0;
	int directionMovement = 1;



	int aux;

	int i; //Column
	int j; //Row

	EnemyBlinky();

	EnemyBlinky(int i, int j, char **map); //inserts the enemy on the map

	void BlinkyMov(Map map, Player &player); //Updates the position of the enemys







};

