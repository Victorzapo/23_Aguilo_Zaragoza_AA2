#pragma once

struct Map {

	char **map;

	Map(int &ROWS, int &COLUMNS);
	

};

void printMap(int ROWS, int COLUMNS, char **map);

int maxPoints(int ROWS, int COLUMNS, char **map);