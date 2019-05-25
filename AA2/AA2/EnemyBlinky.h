#pragma once
#include "Map.h"
#include"player.h"

class EnemyBlinky {

public:

	enum directonMov {COUNT, UP, RIGHT, DOWN, LEFT};
	
	bool lastPoint = true;
	bool changeDirection = false;
	int lastDirection = 0;
	int directionMovement = 1;



	int aux;

	int i; //Column
	int j; //Row

	EnemyBlinky();

	EnemyBlinky(int i, int j, char **map);

	void BlinkyMov(Map map, Player &player);







};

