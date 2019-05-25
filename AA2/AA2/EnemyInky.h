#pragma once
#include "Map.h"
#include"player.h"

class EnemyInky {

public:

	bool lastPoint = false;
	bool hit = false;

	int i; //Column
	int j; //Row

	EnemyInky();

	EnemyInky(int i, int j, char **map);

	void InkyMov(Map map, Player &player, bool keyboard[]);
};