#include <conio.h>
#include <chrono>
#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
#include <vector>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int y = 14 / 2, x = 40 / 2, score = 0;
int fruitY = (rand() % 12) + 1, fruitX = (rand() % 38) + 1;
int num = 10;
int times = 0;
int random = rand() % 6;
int numMoves = 600;
int endGame = 0;

vector<int> xpos;
vector<int> ypos;

void Build() {
	
	system("cls");

	for (int i = 0; i < xpos.size(); i++) {
		if (y == xpos.at(i) && x == ypos.at(i)) {
			++endGame;
		}
	}

	while (x == fruitX && y == fruitY) {
		ypos.clear();
		xpos.clear();
		++score;
		numMoves = numMoves + 10;
		if (times < 7) {
			--num;
		}
		else {
			++num;
		}
		fruitY = ((rand() % 12) + 1);
		fruitX = ((rand() % 38) + 1);
	}

	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 40; j++) {
			if (i == 0 || i == 13) {
				cout << "#";
			}
			else if (j == 0 || j == 39) {
				cout << "#";
			}
			else if (i == y && j == x) {
				cout << "o";
			}
			else if (i == fruitY && j == fruitX) {
				cout << "F";
			}
			else if ((i^2) - num == sqrt((j - 2)) || ((i ^ random) - num == sqrt((j - random))) || (i ^ 1) - num == sqrt((j - 4)) || ((i ^ random - 3) - num == sqrt((j - random - 1)))) {
				cout << "X";
				xpos.push_back(i);
				ypos.push_back(j);
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

}

void Play() {
	cout << "SCORE: " << score;
	cout << "     Gas (gallons): " << numMoves << endl << endl;
	cout << "One F = 10 gallons Gas";

	int c;

		switch (c = _getch())
		{
		case KEY_RIGHT:
			++x;
			break;
		case KEY_LEFT:
			--x;
			break;
		case KEY_UP:
			--y;
			break;
		case KEY_DOWN:
			++y;
			break;
		}

		--numMoves;
}




int main()
{
	//char map[14][40] = { "======================================",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "|                                    |",
	//					   "======================================"
	//};

	

	//for (int i = 0; i < 14; i++) {
	//	cout << map[i] << endl;
	//}

	HANDLE hStdOut = NULL;										// This code on the left is super cool!
	CONSOLE_CURSOR_INFO curInfo;								// It will remove the cursor from the terminal.
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);					// Make sure you include the header #include <Windows.h>
	GetConsoleCursorInfo(hStdOut, &curInfo);
	curInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &curInfo);

	int key = 1;

	while (key == 1) {
		
		Build();
		Play();

		if ((x == 0 || x == 39 || y == 0 || y == 13) || endGame >= 1) {
			string userInput;
			system("cls");
			cout << "YOU LOSE!";
			cout << endl << endl;
			cout << "Woud you like to play again? (yes/no)";
			cin >> userInput;
			if (userInput == "no") {
				key = 0;
			}
			else {
				y = 14 / 2, x = 40 / 2, score = 0;
				endGame = 0;
				numMoves = 600;
				ypos.clear();
				xpos.clear();
				times = 0;
				
			}
		}
	}

	cout << endl << "GOODBYE!";
	return 0;

}