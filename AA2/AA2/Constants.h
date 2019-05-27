#pragma once


const char mapChar = 219; // Walls char

enum class InputKey { K_ESC, K_LEFT, K_RIGHT, K_UP, K_DOWN, K_SPACEBAR, K_PAUSE, K_GAME_START, K_EXIT, K_RANKING, COUNT };

enum class GameState { SPLASH_SCREEN, MAIN_MENU, GAME, RANKING, GAME_OVER, PAUSE, EXIT};