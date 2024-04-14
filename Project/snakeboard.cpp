#include "snakeboard.h"
#include "defines.h"
snakeBoard::snakeBoard() {
}
void snakeBoard::Draw() {
	DrawRectangleLinesEx(Rectangle{ (float)Offset + 260, (float)Offset - 30, (float)cellSize * cellCount + 10, (float)cellCount * cellSize + 10
		}, 5, DARKGREEN);
}
