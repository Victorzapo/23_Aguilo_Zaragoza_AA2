#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Map.h"
#include "player.h"


Player player;


int main() {


	/////////////////////////////////// MAP ///////////////////////////

	//inicializo las dos variables que determinan el tamaño del tablero 
	int ROWS;
	int COLUMNS;
	//No estoy muy seguro de esto pero supuestamente inicializa una variable Map con el constructor por defecto
	Map map(ROWS, COLUMNS);





	/////////////////////////////// GAMELOOP /////////////////////////

	while (GetAsyncKeyState(VK_ESCAPE) == false) {

		std::cout << player.score << std::endl;
		movementPlayer(player, map.map, ROWS, COLUMNS); //Supuestamente ese map deberia ser el puntero que creamos en la struct Map
		printMap(ROWS, COLUMNS, map.map);
		Sleep(75);

		system("CLS"); //Cleans screen
	}
	return 0;

}