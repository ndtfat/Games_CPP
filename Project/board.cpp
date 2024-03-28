#include "board.h"
#include "blocks.cpp"
#include "defines.h"

Board::Board() {
	Initialize();
}

void Board::Initialize() {
	for (int r = 0; r < NUM_ROWS; r++)
		for (int c = 0; c < NUM_COLS; c++)
			grid[r][c] = 0;
}

void Board::Draw() {
	DrawRectangle(BOARD_OFFSET_X, BOARD_OFFSET_Y, BOARD_WIDTH, BOARD_HEIGHT, LIGHTGRAY);

	for (int r = 0; r < NUM_ROWS; r++)
		for (int c = 0; c < NUM_COLS; c++) {
			Color cellColor = grid[r][c] == 1 ? LIGHTGRAY : WHITE;
			Vector2 cell = {
				CELL_OFFSET_X + (c * CELL_SIZE),
				CELL_OFFSET_Y + (r * CELL_SIZE)
			};

			DrawRectangle(cell.x, cell.y, CELL_SIZE - 1, CELL_SIZE - 1, cellColor);
		}

}

bool Board::IsCellOutside(int row, int col) {
	if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS) {
		return false;
	}
	return true;
}

bool Board::IsCellEmpty(int row, int col) {
	return grid[row][col] == 0;
}

bool Board::IsRowFull(int row) {
	for (int col = 0; col < NUM_COLS; col++) {
		if (grid[row][col] == 0)
			return false;
	}
	return true;
}

void Board::ClearRow(int row) {
	for (int col = 0; col < NUM_COLS; col++) {
		grid[row][col] = 0;
	}
}

void Board::MoveRowDown(int row, int numRow) {
	for (int col = 0; col < NUM_COLS; col++) {
		grid[row + numRow][col] = grid[row][col];
		grid[row][col] = 0;
	}
}

int Board::ClearRowsFull() {
	int numClearedRows = 0;
	for (int row = NUM_ROWS - 1; row >= 0; row--) {
		if (IsRowFull(row)) {
			numClearedRows++;
			ClearRow(row);
		} else	if (numClearedRows > 0) {
			MoveRowDown(row, numClearedRows);
		}
	}
	return numClearedRows;
}