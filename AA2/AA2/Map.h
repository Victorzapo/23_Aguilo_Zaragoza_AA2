#pragma once

struct Map {

	char **map;

	int ROWS;
	int COLUMNS;

	//Player Initial pos

	int playerIposi;
	int playerIposj;
	bool playerPw = false;

	//Blinky Initial pos

	int BlinkyIposi;
	int BlinkyIposj;

	//Inky Initial pos

	int InkyIposi;
	int InkyIposj;

	//Cyde Initial pos

	int ClydeIposi;
	int ClydeIposj;



	Map();

	void PrintMap(); //Prints the map on screen

	int MaxPoints(); //Checks the number of points you can collect

};

