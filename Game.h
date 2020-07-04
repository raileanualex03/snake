#pragma once
#include "Snake.h"
# include <string>
class Game
{
private:
	std::vector<std::vector<int>> table;
	Snake& snake;
	int length, width;
	int currentDirection = UP;
	pair point;
	int score = 0;
public:

	std::string name{ " " };
public:
	Game(char* name, Snake& snake, int l, int w) : name{ name }, snake { snake }, length{ l }, width{ w }{

		for (int i = 0; i < length; i++) {
			std::vector<int> line;
			for (int j = 0; j < width; j++) {
				line.push_back(0);
			}
			table.push_back(line);
		}
	};
	void run();
	void showTable();

	void generateRandomPoint();
	bool isFinished();
	void putSnakeInTable();
	void restoreTable();
	bool eatenPoint();
};

