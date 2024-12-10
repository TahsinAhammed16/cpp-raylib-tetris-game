#include <raylib.h>
#include "game.h"
#include "colors.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    Color darkBlue = {38, 70, 129, 255};
    Color lightBlue = {59, 85, 162, 255};     
    Color borderColor = {255, 255, 255, 200}; 

    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("fonts/monogram.ttf", 64, 0, 0);
    Game game = Game();
    bool gameStarted = false;

    while (!WindowShouldClose())
    {
        if (gameStarted)
        {
            UpdateMusicStream(game.music);
            game.HandleInput();

            if (EventTriggered(0.3))
            {
                game.MoveBlockDown();
            }

            BeginDrawing();
            ClearBackground(darkBlue);

            DrawRectangle(320, 55, 170, 60, lightBlue);        
            DrawRectangleLines(320, 55, 170, 60, borderColor); 
            DrawTextEx(font, "Score", (Vector2){365, 15}, 38, 2, WHITE);

            char scoreText[10];
            sprintf(scoreText, "%d", game.score);
            float scoreTextWidth = MeasureTextEx(font, scoreText, 38, 2).x;
            DrawTextEx(font, scoreText, (Vector2){320 + (170 - scoreTextWidth) / 2, 65}, 38, 2, WHITE);

            // Next Section with Border
            DrawRectangle(320, 215, 170, 180, lightBlue);        
            DrawRectangleLines(320, 215, 170, 180, borderColor); 
            DrawTextEx(font, "Next", (Vector2){370, 175}, 38, 2, WHITE);

            // Display the game grid and blocks
            game.Draw();

            if (game.gameOver)
            {
                DrawRectangle(150, 450, 200, 60, lightBlue);                       
                DrawRectangleLines(150, 450, 200, 60, borderColor);                
                DrawTextEx(font, "GAME OVER!", (Vector2){180, 465}, 28, 2, WHITE); 
            }

            EndDrawing();
        }
        else // Show the home screen if the game hasn't started
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                gameStarted = true;
            }

            BeginDrawing();
            ClearBackground(darkBlue);

            const char gameName[] = "TETRIS";
            int gameNameWidth = MeasureText(gameName, 64);
            int gameNameX = (500 - gameNameWidth) / 2;
            DrawText(gameName, gameNameX, 180, 64, WHITE);

            const char startText[] = "Press ENTER to start";
            int startTextWidth = MeasureText(startText, 28);
            int startTextX = (500 - startTextWidth) / 2;
            DrawText(startText, startTextX, 300, 28, WHITE);

            const char controls[] = "Controls:\n< Move Left\n> Move Right\nv Move Down\n^  Rotate";
            int controlsWidth = MeasureText(controls, 22);
            int controlsX = (500 - controlsWidth) / 2;
            int controlsY = 360;
            DrawText(controls, controlsX, controlsY, 22, WHITE);

            const char credits[] = "Developed by: Alvi, Baized, Jisan & Dipto";
            int creditsWidth = MeasureText(credits, 18);
            int creditsX = (500 - creditsWidth) / 2;
            int creditsY = 520;
            DrawText(credits, creditsX, creditsY, 18, WHITE);

            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}
