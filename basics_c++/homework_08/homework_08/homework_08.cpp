#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>

using namespace std;

enum Cell : char {
	CROSS = 'X',
	ZERO = 'O',
	SPACE = ' '
};
enum GameProgress {
	IN_PROGRESS,
	WON_HUMAN,
	WON_AI,
	DRAW
};
struct Coord {
	size_t y;
	size_t x;
};
struct Game {
	Cell** ppField = nullptr;
	const size_t SIZE = 3;
	Cell human;
	Cell ai;
	size_t turn{ 0 };
	GameProgress progress;
};

void clearScr();
int16_t getRandomNumber(int16_t min, int16_t max);

void initGame(Game& g);
void deinitGame(Game& g);
void printGame(const Game& g);
void congratulations(const Game& g);

GameProgress getWon(const Game& g);
Coord getAICoord(Game& g);
Coord getHumanCoord(const Game& g);


int main()
{
	Game g;
	initGame(g);
	clearScr();
	printGame(g);

	do {
		if (g.turn % 2 == 0) {
			// human
			Coord c = getHumanCoord(g);
			g.ppField[c.y][c.x] = g.human;
		}
		else {
			// PC
			Coord c = getAICoord(g);
			g.ppField[c.y][c.x] = g.ai;
		}
		clearScr();
		printGame(g);
		g.turn++;
		g.progress = getWon(g);

	} while (g.progress == IN_PROGRESS);

	congratulations(g);
	deinitGame(g);
	return 0;

}

void clearScr() {
	system("cls");
}

int16_t getRandomNumber(int16_t min, int16_t max) {
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	std::uniform_int_distribution<int16_t> dist1(min, max);
	return dist1(generator);
}

void initGame(Game& g) {
	g.ppField = new Cell*[g.SIZE];
	for (size_t i = 0; i < g.SIZE; i++) {
		g.ppField[i] = new Cell[g.SIZE];
	}

	for (size_t y = 0; y < g.SIZE; y++) {
		for (rsize_t x = 0; x < g.SIZE; x++) {
			g.ppField[y][x] = SPACE;
		}
	}

	if (getRandomNumber(0, 100) > 50) {
		g.human = CROSS;
		g.ai = ZERO;
		g.turn = 0;
	}
	else {
		g.human = ZERO;
		g.ai = CROSS;
		g.turn = 1;
	}
}

void deinitGame(Game& g) {
	for (size_t i = 0; i < g.SIZE; i++) {
		delete[] g.ppField[i];
	}
	delete[] g.ppField;
	g.ppField = nullptr;
}

void printGame(const Game& g) {
	cout << "=   = ";
	for (size_t x = 0; x < g.SIZE; x++) {
		cout << x + 1 << " = ";
	}
	cout << endl << "=================" << endl;

	for (size_t y = 0; y < g.SIZE; y++) {
		cout << "= " << y + 1 << " = ";
		for (size_t x = 0; x < g.SIZE; x++) {
			cout << static_cast<char> (g.ppField[y][x]) << " = ";  // по совершенно непонятной причине печатает коды символов если без ststic_cast
		}
		cout << endl << "=================" << endl;
	}
	cout << endl << " Human: " << static_cast<char> (g.human) << endl
		<< " Computer: " << static_cast<char> (g.ai) << endl;
}

void congratulations(const Game& g) {
	if (g.progress == WON_HUMAN) {
		cout << " YOU WIN! " << endl;
	}
	else if (g.progress == WON_AI) {
		cout << " Maybe next time you win. " << endl;
	}
	else if (g.progress == DRAW) {
		cout << " DRAW. Try again! " << endl;
	}
} 

GameProgress getWon(const Game& g) {
	// столбцы
	for (rsize_t y = 0; y < g.SIZE; y++) {
		if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2]) {
			if (g.ppField[y][0] == g.human) {
				return WON_HUMAN;
			}
			if (g.ppField[y][0] == g.ai) {
				return WON_AI;
			}
		}
	}
	// строки
	for (rsize_t x = 0; x < g.SIZE; x++) {
		if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x]) {
			if (g.ppField[0][x] == g.human) {
				return WON_HUMAN;
			}
			if (g.ppField[0][x] == g.ai) {
				return WON_AI;
			}
		}
	}
	// диагонали
	if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2]) {
		if (g.ppField[1][1] == g.human) {
			return WON_HUMAN;
		}
		if (g.ppField[1][1] == g.ai) {
			return WON_AI;
		}
	}
	if (g.ppField[0][2] == g.ppField[1][1] && g.ppField[0][2] == g.ppField[2][0]) {
		if (g.ppField[1][1] == g.human) {
			return WON_HUMAN;
		}
		if (g.ppField[1][1] == g.ai) {
			return WON_AI;
		}
	}
	// ничья
	bool draw = true;
	for (size_t y = 0; y < g.SIZE; y++) {
		for (size_t x = 0; x < g.SIZE; x++) {
			if (g.ppField[y][x] == SPACE) {
				draw = false;
				break;
			}
		}
		if (!draw) {
			break;
		}
	}
	if (draw) {
		return DRAW;
	}
	return IN_PROGRESS;
}

Coord getHumanCoord(const Game& g) {
	Coord c;
	do {
		cout << "Enter X (1..3): ";
		cin >> c.x;
		cout << "Enter Y (1..3): ";
		cin >> c.y;
		c.y--;
		c.x--;
		if (g.ppField[c.y][c.x] != SPACE) {
			cout << "Select empty cell!" << endl;
		}
	} while (c.y > 2 || c.x > 2 || g.ppField[c.y][c.x] != SPACE);
	return c;
}

Coord getAICoord(Game& g) {
	// забота в выигрыше
	for (size_t y = 0; y < g.SIZE; y++) {
		for (size_t x = 0; x < g.SIZE; x++) {
			if (g.ppField[y][x] == SPACE) {
				g.ppField[y][x] = g.ai;
				if (getWon(g) == WON_AI) {
					g.ppField[y][x] = SPACE;
					return { y,x };
				}
				g.ppField[y][x] = SPACE;
			}
		}
	}
	// Забота о непроигрыше
	for (size_t y = 0; y < g.SIZE; y++) {
		for (size_t x = 0; x < g.SIZE; x++) {
			if (g.ppField[y][x] == SPACE) {
				g.ppField[y][x] = g.human;
				if (getWon(g) == WON_HUMAN) {
					g.ppField[y][x] = SPACE;
					return { y,x };
				}
				g.ppField[y][x] = SPACE;
			}
		}
	}
	// выбор клетки для хода (случайно с приоритетом)
	// анализируем центр
	if (g.ppField[1][1] == SPACE) {
		return { 1,1 };
	}
	// анализируем углы
	Coord buf[4];
	size_t n = 0;
	if (g.ppField[0][0] == SPACE) {
		buf[n] = { 0,0 };
		n++;
	}
	if (g.ppField[2][0] == SPACE) {
		buf[n] = { 2,0 };
		n++;
	}
	if (g.ppField[0][2] == SPACE) {
		buf[n] = { 0,2 };
		n++;
	}
	if (g.ppField[2][2] == SPACE) {
		buf[n] = { 2,2 };
		n++;
	}
	if (n > 0) {
		const size_t index = getRandomNumber(0, 100) % n;
		return buf[index];
	}
	// анализируем не углы
	n = 0;
	if (g.ppField[1][0] == SPACE) {
		buf[n] = { 1,0 };
		n++;
	}
	if (g.ppField[2][1] == SPACE) {
		buf[n] = { 2,1 };
		n++;
	}
	if (g.ppField[1][2] == SPACE) {
		buf[n] = { 1,2 };
		n++;
	}
	if (g.ppField[0][1] == SPACE) {
		buf[n] = { 0,1 };
		n++;
	}
	if (n > 0) {
		const size_t index = getRandomNumber(0, 100) % n;
		return buf[index];
	}
}