#include <iostream>
#include <random>
#include <ctime>
#include <cstdio>
#include "tetris.h"
#include "defines.h"

double lastUpdateTime = 0;
bool TimeOut(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

Tetris::Tetris() {
	score = 0;
	level = 10;
	pause = false;
	gameOver = false;
	board = Board();
	blocks = { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
	currBlock = GetRandomBlock(); 
	nextBlock = GetRandomBlock();
}

void Tetris::Start(Font font) {
	DrawSidbar(font);
	board.Draw();
	currBlock.Draw(CELL_OFFSET_X, BOARD_OFFSET_Y);
	HandleKeyPress();

	if (!pause && !gameOver) {
		UpdateLevel();
		// auto move down
		if (TimeOut(1 - level * 0.3)) {
			MoveBlockDown();
		}
	}
	
	if (pause) {
		DrawOverLay(font, "Paused");
	}
	if (gameOver) {
		DrawOverLay(font, "Game Over");
	}
}

void Tetris::DrawOverLay(Font font,const char* text) {
	int fontSize = 40;
	int spacing = 10;
	Vector2 textSize = MeasureTextEx(font, text, fontSize, spacing);

	DrawRectangle(
		BOARD_OFFSET_X, 
		BOARD_OFFSET_Y, 
		BOARD_WIDTH, 
		BOARD_HEIGHT, 
		OVERLAY_COLOR
	);
	DrawTextEx(
		font, 
		text, 
		{ BOARD_OFFSET_X + (BOARD_WIDTH + PADDING) / 2 - textSize.x / 2, BOARD_OFFSET_Y + CELL_SIZE * 8 },
		fontSize, 
		spacing, 
		DARKGRAY
	);
}

void Tetris::DrawSidbar(Font font) {
	DrawTextEx(font, "Next", { TETRIS_SIDEBAR_OFFSET_X, TETRIS_SIDEBAR_OFFSET_Y }, 30, 5, GRAY);
	nextBlock.Draw(
		TETRIS_SIDEBAR_OFFSET_X - (nextBlock.offset.y * CELL_SIZE),
		NEXT_BLOCK_OFFSET_Y
	);
	DrawTextEx(font, "Level", { TETRIS_SIDEBAR_OFFSET_X, NEXT_BLOCK_OFFSET_Y + CELL_SIZE * 4 }, 20, 5, GRAY);
	DrawTextEx(font, "Score", { TETRIS_SIDEBAR_OFFSET_X, NEXT_BLOCK_OFFSET_Y + CELL_SIZE * 5 }, 20, 5, GRAY);
	char levelText[3];
	char scoreText[10];
	sprintf_s(levelText, "%d", level);
	sprintf_s(scoreText, "%d", score);
	DrawTextEx(font, levelText, { TETRIS_SIDEBAR_OFFSET_X + CELL_SIZE * 3, NEXT_BLOCK_OFFSET_Y + CELL_SIZE * 4 }, 20, 5, GRAY);
	DrawTextEx(font, scoreText, { TETRIS_SIDEBAR_OFFSET_X + CELL_SIZE * 3, NEXT_BLOCK_OFFSET_Y + CELL_SIZE * 5 }, 20, 5, GRAY);

	DrawTextEx(font, "(P)\t Pause game", {TETRIS_SIDEBAR_OFFSET_X, NEXT_BLOCK_OFFSET_Y + CELL_SIZE * 7}, 20, 5, GRAY);
	DrawTextEx(font, "(R)\t Reset game", { TETRIS_SIDEBAR_OFFSET_X, NEXT_BLOCK_OFFSET_Y + CELL_SIZE * 8 }, 20, 5, GRAY);
}

void Tetris::UpdateLevel() {
	if (score != 0 && level < 9) {
		int newLevel = score / 10; // Calculate the number of times score is divisible by 10
		if (newLevel > level)
			level = newLevel;
	}
}

Block Tetris::GetRandomBlock() {
	int randId = GetRandomValue(0, 6);
	return blocks[randId];
}

void Tetris::HandleKeyPress() {
	int keyPressed = GetKeyPressed();

	switch (keyPressed) {
		if (!pause) {
			case KEY_LEFT:
				MoveBlockLeft();
				break;
			case KEY_RIGHT:
				MoveBlockRight();
				break;
			case KEY_DOWN:
				MoveBlockDown();
				break;
			case KEY_UP:
				RotateBlock();
				break;
		} else {
			case KEY_P:
				pause = !pause;
				break;
			case KEY_R:
				Reset();
				break;
		}
		default:
			break;
	}
}

bool Tetris::IsBlockOutside() {
	std::vector<Position> tiles = currBlock.GetCellPositions();
	for (Position item : tiles) {
		if (board.IsCellOutside(item.row, item.col)) {
			return true;
		}
	}
	return false;
}

bool Tetris::BlockFits() {
	std::vector<Position> tiles = currBlock.GetCellPositions();
	for (Position item: tiles) {
		if (!board.IsCellEmpty(item.row, item.col)) {
			return false;
		}
	}
	return true;
}

void Tetris::Reset() {
	board.Initialize();
	score = 0;
	level = 0;
	gameOver = false; 
	currBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
}

void Tetris::MoveBlockDown() {
	currBlock.Move(1, 0);
	if (IsBlockOutside() || !BlockFits()) {
		currBlock.Move(-1, 0);
		LockBlock();
	}
}

void Tetris::MoveBlockLeft() {
	if (!gameOver) {
		currBlock.Move(0, -1);
		if (IsBlockOutside() || !BlockFits()) {
			currBlock.Move(0, 1);
		}
	}
}

void Tetris::MoveBlockRight() {
	if (!gameOver) {
		currBlock.Move(0, 1);
		if (IsBlockOutside() || !BlockFits()) {
			currBlock.Move(0, -1);
		}
	}
}

void Tetris::RotateBlock() {
	if (!gameOver) {
		currBlock.Rotate();
		if (IsBlockOutside() || !BlockFits()) {
			currBlock.UndoRotate();
		}
	}
}

void Tetris::LockBlock() {
	std::vector<Position> tiles = currBlock.GetCellPositions();
	for (Position item : tiles) {
		board.grid[item.row][item.col] = 1;
	}
	currBlock = nextBlock;
	if (!BlockFits()) {
		gameOver = true;
	}
	nextBlock = GetRandomBlock();
	int numClearedRows = board.ClearRowsFull();
	score += numClearedRows;
}