#include <raylib.h>
#include "grid.h"

int main()
{
    Color darkBlue = {38, 70, 129, 255};

    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.grid[0][0] = 1;
    grid.grid[6][7] = 5;
    grid.grid[16][12] = 4;
    grid.Print();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}