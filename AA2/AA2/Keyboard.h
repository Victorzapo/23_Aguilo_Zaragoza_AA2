#pragma once
#include <Windows.h>

void keyBoardControl(bool keyboard[]) {


	keyboard[(int)InputKey::K_ESC] = GetAsyncKeyState(VK_ESCAPE);
	keyboard[(int)InputKey::K_PAUSE] = GetAsyncKeyState(0x50); //P
	keyboard[(int)InputKey::K_SPACEBAR] = GetAsyncKeyState(VK_SPACE); //Spacebar

	keyboard[(int)InputKey::K_UP] = GetAsyncKeyState(VK_UP);
	keyboard[(int)InputKey::K_DOWN] = GetAsyncKeyState(VK_DOWN);
	keyboard[(int)InputKey::K_RIGHT] = GetAsyncKeyState(VK_RIGHT);
	keyboard[(int)InputKey::K_LEFT] = GetAsyncKeyState(VK_LEFT);




}