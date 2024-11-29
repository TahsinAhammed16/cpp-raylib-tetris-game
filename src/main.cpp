#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main()
{
    Color darkBlue = {38, 70, 129, 255};

    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    // test cases
    // grid.grid[0][0] = 1;
    grid.Print();

    TBlock block = TBlock();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}