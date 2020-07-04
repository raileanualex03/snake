#pragma once
#include <vector>
# define pair std::pair<int, int>
# define LEFT 1
# define RIGHT 2
# define UP 3
# define DOWN 4
class Snake
{
private:
	int size;
	std::vector<pair> coordinates;
public:
	Snake(int size, std::vector<pair> c) : size{ size }, coordinates{ c }{};
	void move(int direction);
	void eatPoint(pair p, int direction);

	bool isFinished();
	std::vector<pair> getCoordinates();
};

