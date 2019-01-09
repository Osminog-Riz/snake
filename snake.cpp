
// #include "pch.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <ctime>

#include <windows.h>

#include <cstdlib>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, frux, fruy, sc;
enum edir { STOP=0,LEFT,RIGHT,UP,DOWN};
edir dir;

void printTo(int x, int y, string text) {
    printf("\033[%d;%dH%s\n", x, y, text.c_str());
		printf("\033[1;1H");
}

void Setup()
{
	srand(time(NULL));
	gameover = 0;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	frux = rand() % width;
	fruy = rand() % height;
	sc = 0;
}

void Draw()
{
	system("cls");
	string display = "";
	for (int i = 0; i < width + 2; i++) {
		// cout << "0";
		display += "0";
	}
	// cout << endl;
	display += "\n";
	for(int i=0;i<=height;i++)
	{
		for (int j = 0;j<=width;j++)
		{
			if (j == 0 || j == width) {
					display += "0";
					// cout << "0";
				}
			if (i == y && j == x) {
					display += "Z";
			// cout << "Z";
		}
			else if (i == fruy && j == frux) {
				// cout << "*";
					display += "*";
				}
			else 	display += " ";
			// cout << " ";
		}
			display += "\n";
		// cout << endl;
	}
	for (int i = 0; i < width + 2; i++) {
		// cout << "0";
		display += "0";
		// cout << endl;
	}
	display += "\nYour score = ";
	display += sc;
	// cout<<endl;
	display += "\r\n";
	cout << display;

	// printf("gfdg");
	// for (int i = 20; i > 0; i--) {
	// 	printTo(i, i, "Z");
	// 	Sleep(30);
	// }
}

void Input()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a': dir = LEFT; break;
		case 'd': dir = RIGHT; break;
		case 's': dir = DOWN; break;
		case 'w': dir = UP; break;
		case 'x': gameover = true; break;
		}

	}
}

void Large() {
	switch (dir)
	{

	case LEFT:x--;
		break;
	case RIGHT:x++;
		break;
	case UP:y--;
		break;
	case DOWN:y++;
		break;
	}
	if (x < 0 || x>width || y<0 || y>height)
		gameover = true;

	if (x == frux && y == fruy)	{
		sc++;
		frux = rand() % width;
		fruy = rand() % height;
	}
}

int main()
{
	setlocale(0, "rus");
	Setup();
	while (!gameover)
	{
		Draw();
		Input();
		Large();
    // usleep(50000);
    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
    Sleep(30);
	}
	return 0;
}
