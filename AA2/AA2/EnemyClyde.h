#pragma once
#include "Map.h"
#include"player.h"

class EnemyClyde {

public:

	enum direction { UP, DOWN, LEFT, RIGHT };

	bool lastPoint = false;

	int i; //Column
	int j; //Row

	direction actDirection = DOWN;
	direction prevDirection;

	EnemyClyde();

	EnemyClyde(int i, int j, char **map);

	void ClydeMov(Map map, Player &player);
};