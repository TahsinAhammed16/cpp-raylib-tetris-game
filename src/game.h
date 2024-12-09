#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <iostream>
using namespace std;

class Game
{
private:
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
     void UpdateScore(int linesCleared, int moveDownPoints);

public:
    Game();
    Block GetRandomBlock();
    vector<Block> GetAllBlocks();
    void Draw();
    Grid grid;
    bool gameOver;
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    int score;
};
