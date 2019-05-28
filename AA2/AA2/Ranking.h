#pragma once
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <Windows.h>

class Ranking
{
public:
	Ranking();

	
	std::map<std::string, int> ranking;

	

	void addPS(int score); //Add a player to the map and save it on .txt
	
	void printRanking(); //Prints a ordered ranking 
};

