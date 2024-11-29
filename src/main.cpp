#include <raylib.h>
#include "game.h"

int main()
{
    Color darkBlue = {38, 70, 129, 255};
    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while(!WindowShouldClose())
    {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}