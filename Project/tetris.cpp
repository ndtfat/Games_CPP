#include <iostream>
#include <random>
#include "tetris.h"
#include "blocks.cpp"
#include "defines.h"
#include "util.h"

Tetris::Tetris() {
	score = 0;
	level = 2;
	pause = true;
	gameOver = false;
	board = TetrisBoard();
	blocks = { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
	currBlock = GetRandomBlock(); 
	nextBlock = GetRandomBlock();
}

void Tetris::Start(Font font) {
	DrawSidbar(font);
	board.Draw();
	currBlock.Draw(TT_CELL_X, TT_Y);
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
		TT_BOARD_X,
		TT_Y,
		TT_BOARD_WIDTH,
		TT_BOARD_HEIGHT,
		OVERLAY_COLOR
	);
	DrawTextEx(
		font, 
		text, 
		{ 
			TT_BOARD_X + (TT_BOARD_WIDTH + TT_PADDING) / 2 - textSize.x / 2, 
			TT_Y + TT_CELL_SIZE * 8
		},
		fontSize, 
		spacing, 
		DARKGRAY
	);
}

void Tetris::DrawSidbar(Font font) {
	DrawTextEx(font, "Next", { TT_SIDEBAR_X, TT_Y }, 30, 5, GRAY);
	nextBlock.Draw(
		TT_SIDEBAR_X - (nextBlock.offset.y * TT_CELL_SIZE),
		TT_Y + TT_CELL_SIZE + 30
	);
	DrawTextEx(font, "Level", { TT_SIDEBAR_X, TT_NEXT_BLOCK_Y + TT_CELL_SIZE * 4 }, 20, 5, GRAY);
	DrawTextEx(font, "Score", { TT_SIDEBAR_X, TT_NEXT_BLOCK_Y + TT_CELL_SIZE * 5 }, 20, 5, GRAY);
	char levelText[3];
	char scoreText[10];
	sprintf_s(levelText, "%d", level);
	sprintf_s(scoreText, "%d", score);
	DrawTextEx(font, levelText, { TT_SIDEBAR_X + TT_CELL_SIZE * 3, TT_NEXT_BLOCK_Y + TT_CELL_SIZE * 4 }, 20, 5, GRAY);
	DrawTextEx(font, scoreText, { TT_SIDEBAR_X + TT_CELL_SIZE * 3, TT_NEXT_BLOCK_Y + TT_CELL_SIZE * 5 }, 20, 5, GRAY);

	DrawTextEx(font, "[P]\t Pause game", {TT_SIDEBAR_X, TT_NEXT_BLOCK_Y + TT_CELL_SIZE * 7}, 20, 5, GRAY);
	DrawTextEx(font, "[R]\t Reset game", { TT_SIDEBAR_X, TT_NEXT_BLOCK_Y + TT_CELL_SIZE * 8 }, 20, 5, GRAY);
	DrawTextEx(font, "[X]\t Exit game", { TT_SIDEBAR_X, TT_NEXT_BLOCK_Y + TT_CELL_SIZE * 9 }, 20, 5, GRAY);
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
		case KEY_P:
			pause = !pause;
			break;
		case KEY_R:
			Reset();
			break;
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
	if (!pause) {
		currBlock.Move(1, 0);
		if (IsBlockOutside() || !BlockFits()) {
			currBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

void Tetris::MoveBlockLeft() {
	if (!gameOver && !pause) {
		currBlock.Move(0, -1);
		if (IsBlockOutside() || !BlockFits()) {
			currBlock.Move(0, 1);
		}
	}
}

void Tetris::MoveBlockRight() {
	if (!gameOver && !pause) {
		currBlock.Move(0, 1);
		if (IsBlockOutside() || !BlockFits()) {
			currBlock.Move(0, -1);
		}
	}
}

void Tetris::RotateBlock() {
	if (!gameOver && !pause) {
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