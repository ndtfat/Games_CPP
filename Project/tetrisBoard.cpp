#include "tetrisBoard.h"
#include "blocks.cpp"
#include "defines.h"

TetrisBoard::TetrisBoard() {
	Initialize();
}

void TetrisBoard::Initialize() {
	for (int r = 0; r < TT_NUM_ROWS; r++)
		for (int c = 0; c < TT_NUM_COLS; c++)
			grid[r][c] = 0;
}

void TetrisBoard::Draw() {
	DrawRectangle(TT_BOARD_X, TT_Y, TT_BOARD_WIDTH, TT_BOARD_HEIGHT, LIGHTGRAY);

	for (int r = 0; r < TT_NUM_ROWS; r++)
		for (int c = 0; c < TT_NUM_COLS; c++) {
			Color cellColor = grid[r][c] == 1 ? LIGHTGRAY : WHITE;
			Vector2 cell = {
				TT_CELL_X + (c * TT_CELL_SIZE),
				TT_Y + (r * TT_CELL_SIZE)
			};

			DrawRectangle(cell.x, cell.y, TT_CELL_SIZE - 1, TT_CELL_SIZE - 1, cellColor);
		}

}

bool TetrisBoard::IsCellOutside(int row, int col) {
	if (row >= 0 && row < TT_NUM_ROWS && col >= 0 && col < TT_NUM_COLS) {
		return false;
	}
	return true;
}

bool TetrisBoard::IsCellEmpty(int row, int col) {
	return grid[row][col] == 0;
}

bool TetrisBoard::IsRowFull(int row) {
	for (int col = 0; col < TT_NUM_COLS; col++) {
		if (grid[row][col] == 0)
			return false;
	}
	return true;
}

void TetrisBoard::ClearRow(int row) {
	for (int col = 0; col < TT_NUM_COLS; col++) {
		grid[row][col] = 0;
	}
}

void TetrisBoard::MoveRowDown(int row, int numRow) {
	for (int col = 0; col < TT_NUM_COLS; col++) {
		grid[row + numRow][col] = grid[row][col];
		grid[row][col] = 0;
	}
}

int TetrisBoard::ClearRowsFull() {
	int numClearedRows = 0;
	for (int row = TT_NUM_ROWS - 1; row >= 0; row--) {
		if (IsRowFull(row)) {
			numClearedRows++;
			ClearRow(row);
		} else	if (numClearedRows > 0) {
			MoveRowDown(row, numClearedRows);
		}
	}
	return numClearedRows;
}