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

void Setup() { // начальные данные
	srand(time(NULL));
	gameover = 0;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	frux = rand() % width;
	fruy = rand() % height;
	sc = 0;
}

void Draw() { //что то с экраном
	system("cls");
	string display = "";
	for (int i = 0; i < width + 2; i++) {
		display += "0";
	}
	display += "\n";
	for(int i=0;i<=height;i++) {
		for (int j = 0;j<=width;j++) {
			if (j == 0 || j == width) {
					display += "0";
				  }
			if (i == y && j == x) {
					display += "Z";
		      }
			else if (i == fruy && j == frux) {
					display += "*";
				}
			else 	display += " ";
		}
			display += "\n";
	}
	for (int i = 0; i < width + 2; i++) {
		display += "0";
	}
	cout << display;
  cout<< "\nYour score = "<<sc<<endl;

	// for (int i = 20; i > 0; i--) {
	// 	printTo(i, i, "Z");
	// 	Sleep(30);
	// }
}

void Input() //ввод с клавы выбором
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a': dir = LEFT; break;
		case 'd': dir = RIGHT; break;
		case 's': dir = DOWN; break;
		case 'w': dir = UP; break;
		case 'x': gameover = true; break;
    case 'A': dir = LEFT; break;
    case 'D': dir = RIGHT; break;
    case 'S': dir = DOWN; break;
    case 'W': dir = UP; break;
    case 'X': gameover = true; break;
		}

	}
}

void Large() { //движение
	switch (dir) {
	case LEFT:x--;
		break;
	case RIGHT:x++;
		break;
	case UP:y--;
		break;
	case DOWN:y++;
		break;
	}
	if (x < 0 || x>width || y<0 || y>height){
		gameover = true;
    }
	if (x == frux && y == fruy)	{
		sc++;
		frux = rand() % width;
		fruy = rand() % height;
	   }
}

int main() {
	setlocale(0, "rus");
	Setup();
	while (!gameover) {
		Draw();
		Input();
		Large();
    Sleep(30);
	}
	return 0;
}
