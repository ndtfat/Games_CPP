#include "snakeboard.h"
#include "defines.h"

Rectangle innerRect = { (float)SNAKE_Offset + 260, (float)SNAKE_Offset - 30, (float)SNAKE_cellSize * SNAKE_cellCount + 10, (float)SNAKE_cellCount * SNAKE_cellSize + 10 };
snakeBoard::snakeBoard() {
}
void snakeBoard::Init() {
	DrawRectangleRec(innerRect, LIGHTGRAY);
}
void snakeBoard::Draw() {
	DrawRectangleLinesEx(Rectangle{ (float)SNAKE_Offset + 260, (float)SNAKE_Offset - 30, (float)SNAKE_cellSize * SNAKE_cellCount + 10, (float)SNAKE_cellCount * SNAKE_cellSize + 10
		}, 5, BLACK);
}
