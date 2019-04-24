#pragma once

struct Map {

	char **map;

	int ROWS;
	int COLUMNS;

	Map();
	
	void PrintMap();
	int MaxPoints();
};

