#pragma once
#include <vector>
#include "raylib.h"
using namespace std;

class Board {
public:
    int grid[20][10];
    Board();
    void Initialize();
    void Draw();
    bool IsCellOutside(int row, int col);
    bool IsCellEmpty(int row, int col);
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRow);  // Move when have rows is cleared (move down numRow times)
    int ClearRowsFull();
};