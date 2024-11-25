#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    Initialize();
    cellSize = 0;
    colors = GetCellColors();
}

// function to initialize the grid
void Grid::Initialize()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0; // set each grid cell to 0 (empty)
        }
    }
}

void Grid::Print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            cout << grid[row][column] << " ";
        }
        cout << endl;
    }
}

vector<Color> Grid::GetCellColors()
{
    Color darkGrey = {33, 37, 43, 255};
    Color green = {0, 200, 83, 255};
    Color red = {255, 59, 48, 255};
    Color orange = {255, 149, 0, 255};
    Color yellow = {255, 214, 10, 255};
    Color purple = {175, 82, 222, 255};
    Color cyan = {0, 180, 240, 255};
    Color blue = {10, 132, 255, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

// function to draw the grid with colored cells
void Grid::Draw()
{
    int cellSize = 30;

    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];

            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}
