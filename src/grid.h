#pragma once //ensures the header file is included only once during compilation
#include <iostream>
#include <raylib.h>
#include <vector>
using namespace std;

class Grid
{
private:
    int numRows;
    int numCols;
    int cellSize;
    vector<Color> colors;

public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    int grid[20][10];
};