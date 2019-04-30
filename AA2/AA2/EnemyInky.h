#pragma once
#include "Map.h"
#include"player.h"

class EnemyInky {

public:

	enum direction { UP, DOWN, LEFT, RIGHT };

	bool lastPoint = false;

	int i; //Column
	int j; //Row

	direction actDirection = DOWN;
	direction prevDirection;

	EnemyInky();

	EnemyInky(int i, int j, char **map);

	void InkyMov(Map map, Player &player);
};