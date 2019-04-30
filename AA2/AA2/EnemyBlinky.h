#pragma once
#include "Map.h"
#include"player.h"

class EnemyBlinky {

public:

	enum direction { UP, DOWN, LEFT, RIGHT };

	bool lastPoint = true;

	int i; //Column
	int j; //Row

	direction actDirection = DOWN;
	direction prevDirection;

	EnemyBlinky();

	EnemyBlinky(int i, int j, char **map);

	void BlinkyMov(Map map, Player &player);

	//void InkyMov(char **map, int COLUMNS, int ROWS, int &direction, bool &nextAst, int &playerDir);
	//void ClydeMov(char **map, int COLUMNS, int ROWS, int &direction, bool &nextAst, int & playerDir);


	//void InkyInitialPosition(Enemy Blinky, char **map, int COLUMNS, int ROWS);
	//void ClydeInitialPosition(Enemy Blinky, char **map, int COLUMNS, int ROWS);






};

