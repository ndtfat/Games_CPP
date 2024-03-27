#include "raylib.h"
#include "tetris.h"
#include <iostream>

#define PADDING 5
#define CELL_SIZE 30
#define WIDTH (CELL_SIZE * 10) + (PADDING * 2) + 9
#define HEIGHT (CELL_SIZE * 20)

Tetris::Tetris(int screenWidth) {
	screenW = screenWidth;
	numCols = 10;
	numRows = 20;
	cellSize = 10;

	level = 1;
	score = 0;
	gameOver = false;


	Initialize();
}

void Tetris::Initialize() {
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			grid[r][c] = 0;
			std::cout << grid[r][c] << " ";
		}
		std::cout << std::endl;
	}
}

void Tetris::Draw() {
	Vector2 tetrisOffset = { screenW / 2 - WIDTH / 2, 80 };
	DrawRectangle(tetrisOffset.x, tetrisOffset.y, WIDTH, HEIGHT, LIGHTGRAY);

	for (int r = 0; r < numRows; r++)
		for (int c = 0; c < numCols; c++) {
			Color cellColor = grid[r][c] == 1 ? LIGHTGRAY : WHITE;
			Vector2 cell = { 
				(tetrisOffset.x + PADDING) + (c * CELL_SIZE),
				tetrisOffset.y + (r * CELL_SIZE)
			};

			DrawRectangle(cell.x, cell.y, CELL_SIZE - 1, CELL_SIZE - 1, cellColor);
		}

}