#include "snakeboard.h"
#include "defines.h"

Rectangle innerRect = { (float)SNAKE_Offset + 260, (float)SNAKE_Offset - 10, (float)SNAKE_cellSize * SNAKE_cellCount + 10, (float)SNAKE_cellCount * SNAKE_cellSize + 10 };
snakeBoard::snakeBoard() {
}
void snakeBoard::Init() {
	DrawRectangleRec(innerRect, WHITE);
}
void snakeBoard::Paused() {
	DrawRectangleRec(innerRect, Fade(WHITE, 0.5f));
}
void snakeBoard::Draw() {
	//draw title
	DrawText(TextFormat("[x]:Exit  [r]:Reset"), SNAKE_Offset + 260, SNAKE_Offset + SNAKE_cellCount * SNAKE_cellSize - 530, 20, BLACK);
	//
	DrawRectangleLinesEx(Rectangle{ (float)SNAKE_Offset + 260, (float)SNAKE_Offset -10, (float)SNAKE_cellSize * SNAKE_cellCount + 10, (float)SNAKE_cellCount * SNAKE_cellSize + 10
		}, 5, BLACK);
}
