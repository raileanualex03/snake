// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Snake.h"


void Snake::move(int direction)
{
    for (int i = coordinates.size()-1; i >= 1; i--)
        coordinates[i] = coordinates[i-1];
    
    if (direction == RIGHT) {
        coordinates[0].second++;
    }
    else if (direction == LEFT)
        coordinates[0].second--;
    else if (direction == UP)
        coordinates[0].first--;
    else if (direction == DOWN)
        coordinates[0].first++;

    
}

void Snake::eatPoint(pair p, int direction)
{
    this->size++; 
    this->coordinates.insert(coordinates.begin(), p);
    if (direction == RIGHT) {
        coordinates[0].second++;
    }
    else if (direction == LEFT)
        coordinates[0].second--;
    else if (direction == UP)
        coordinates[0].first--;
    else if (direction == DOWN)
        coordinates[0].first++;

}

bool Snake::isFinished()
{
    for (auto i = 1; i < coordinates.size(); i++) {
        if (coordinates[0].first == coordinates[i].first && coordinates[0].second == coordinates[i].second)
            return true;
    }

    return false;
}

std::vector<pair> Snake::getCoordinates()
{
    return coordinates;
}
