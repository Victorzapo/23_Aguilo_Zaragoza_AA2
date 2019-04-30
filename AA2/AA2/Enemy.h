#pragma once
class Enemy {

public:
	int i; //Column
	int j; //Row

	Enemy();

	Enemy(int i, int j, char **map, int type);

	void BlinkyMov(char **map, int COLUMNS, int ROWS, int &direction, bool &nextAst);

	void InkyMov(char **map, int COLUMNS, int ROWS, int &direction, bool &nextAst, int &playerDir);

	void ClydeMov(char **map, int COLUMNS, int ROWS, int &direction, bool &nextAst, int & playerDir);


	void InitialPosition(Enemy Blinky, Enemy Inky, Enemy Clyde, char **map, int COLUMNS, int ROWS);

	void BlinkyInitialPosition(Enemy Blinky, char **map, int COLUMNS, int ROWS);
	void InkyInitialPosition(Enemy Blinky, char **map, int COLUMNS, int ROWS);
	void ClydeInitialPosition(Enemy Blinky, char **map, int COLUMNS, int ROWS);






};
#pragma once
