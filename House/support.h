#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

void clear_screen(char fill = ' ') {
	/*******************/
	/*** Taken from ****/
	/*StackOverflow.com*/
	/*******************/

	COORD tl = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}