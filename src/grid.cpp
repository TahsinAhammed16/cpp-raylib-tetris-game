#include <iostream>
#include "grid.h"
#include "colors.h"
using namespace std;

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    Initialize();
    cellSize = 30;
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

// function to draw the grid with colored cells
void Grid::Draw()
{
    int cellSize = 30;

    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];

            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]); // draw a grid cell with a 1-pixel border for visual separation
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}