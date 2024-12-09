#pragma once // ensures the header file is included only once during compilation
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
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);

public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int grid[20][10];
    int ClearFullRows();
};