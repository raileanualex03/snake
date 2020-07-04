#include "Game.h"
#include <iostream>
# include <conio.h>

# include <Windows.h>

void Game::run()
{

	printf("Hi, %s !", name.c_str());
	printf(" \n Let's have a fun time!\n");


	system("pause");
	generateRandomPoint();
	while (isFinished() == false) {
		Sleep(500);
		if (_kbhit()) {
			switch (_getch()) {
			case 'a':
				currentDirection = LEFT;
				break;
			case 'w':
				currentDirection = UP;
				break;
			case 's':
				currentDirection = DOWN;
				break;
			case 'd':
				currentDirection = RIGHT;
				break;
			}
		}
		
		snake.move(currentDirection);

		if (eatenPoint() == true) {
			snake.eatPoint(point, currentDirection);
			generateRandomPoint();
		}

		system("cls");

		if (isFinished() == true)
			break;
		putSnakeInTable();
		showTable();
		restoreTable();
		
	}
	
	printf("Congratulations! \n     Your score was: %d  :) \n", score);
	system("pause");
}

void Game::showTable()
{
	printf("___________________\n");

	for (int i = 0; i < length;i++) {
		printf("|");
		for (int j = 0; j < width;j++) {
			if (table[i][j] == 0)
				std::cout << "  ";
			else
				std::cout << table[i][j]<<" ";
		}
		printf("|");
		std::cout << "\n";
	}printf("____________________\n");

	printf("SCORE=%d\n", score);
}

void Game::generateRandomPoint()
{
	int line = rand() % (length-2)+1;
	int column = rand() % (width-2)+1;
	pair pointt = pair{ line, column };
	point = pointt;
}

bool Game::isFinished()
{
	if (snake.isFinished() == true)
		return true;
	if (snake.getCoordinates()[0].first < 0 || snake.getCoordinates()[0].second < 0)
		return true;
	if (snake.getCoordinates()[0].first >= length || snake.getCoordinates()[0].second >= width)
		return true;
	
	return false;
}

void Game::putSnakeInTable()
{
	for (pair p : snake.getCoordinates()) {
		table[p.first][p.second] = 7;
	}
	table[snake.getCoordinates()[0].first][snake.getCoordinates()[0].second] = 4;
	// putting also the point here

	table[point.first][point.second] = 9;
}

void Game::restoreTable()
{
	std::vector<std::vector<int>> newTable;
	for (int i = 0; i < length; i++) {
		std::vector<int> line;
		for (int j = 0; j < width; j++) {
			line.push_back(0);
		}
		newTable.push_back(line);
	}
	
	table = newTable;
}

bool Game::eatenPoint()
{
	if (snake.getCoordinates()[0].first == point.first && snake.getCoordinates()[0].second == point.second)
	{
		score += 15;
		return true;
	}
	else {
		return false;
	}
}
