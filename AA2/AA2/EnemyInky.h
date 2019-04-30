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
	//void BlinkyMov(Map map, Player &player);

	//void InkyMov(char **map, int COLUMNS, int ROWS, int &direction, bool &nextAst, int &playerDir);
	//void ClydeMov(char **map, int COLUMNS, int ROWS, int &direction, bool &nextAst, int & playerDir);


	//void InkyInitialPosition(Enemy Blinky, char **map, int COLUMNS, int ROWS);
	//void ClydeInitialPosition(Enemy Blinky, char **map, int COLUMNS, int ROWS);

};