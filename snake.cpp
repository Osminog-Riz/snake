
// #include "pch.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, frux, fruy, sc;
enum edir { STOP=0,LEFT,RIGHT,UP,DOWN};
edir dir;

void Setup()
{
	srand(time(NULL));
	gameover = 0;
	dir = STOP;//ururur
	x = width / 2;
	y = height / 2;
	frux = rand() % width;
	fruy = rand() % height;
	sc= 0;
}
void Draw()
{
	system("cls");
	for (int i = 0; i <= width; i++)
		cout << "0";
	cout << endl;
	for(int i=0;i<=height;i++)
	{
		for (int j = 0;j<=width;j++)
		{
			if (j == 0 || j == width) cout << "0";
			if (i == y && j == x) cout << "Z";
			else if (i == fruy && j == frux) cout << "*";
			else cout << " ";
		}cout << endl;
	}
	for (int i = 0; i <= width; i++)
		cout << "0"; cout << endl;
	cout <<"Your score = "<< sc << endl;
}
void Input()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a': dir = LEFT; break;
		case 'd': dir = RIGHT; break;
		case 's':dir = DOWN; break;
		case 'w': dir = UP; break;
		case 'x': gameover = true; break;
		}

	}
}
void Large()
{
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
	if (x < 0 || x>width || y<0 || y>height) gameover = true;
	if (x == frux && y == fruy)
	{ sc++;
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
	}
	return 0;
}
