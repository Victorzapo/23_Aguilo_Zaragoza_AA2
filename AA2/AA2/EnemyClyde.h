#pragma once
#include "Map.h"
#include"player.h"

class EnemyClyde {

public:

	bool lastPoint = false;
	bool hit = false;

	int i; //Column
	int j; //Row

	EnemyClyde();

	EnemyClyde(int i, int j, char **map);

	void ClydeMov(Map map, Player &player, bool key[]);
};