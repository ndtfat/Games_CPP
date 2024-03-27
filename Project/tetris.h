#pragma once
#include <vector>
#include "raylib.h"
using namespace std;

class Tetris {
private:
    int grid[20][10];
    int screenW;
    int numRows;
    int numCols;
    int cellSize;
    vector<Color> blockColors;
    vector<Color> getBlocksColors();

    int level;
    int score;
    bool gameOver;

public:
    Tetris(int screeW);
    void Initialize();
    void Draw();
};