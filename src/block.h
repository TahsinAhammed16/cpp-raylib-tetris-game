#pragma once
#include <map>
#include <vector>
#include "position.h"
#include "colors.h"
#include <iostream>
using namespace std;

class Block
{
private:
    int cellSize;
    int rotationState;
    vector<Color> colors;

public:
    Block();
    int id;
    map<int, vector<Position>> cells; // map to store rotation states and their corresponding cells
    void Draw();
};