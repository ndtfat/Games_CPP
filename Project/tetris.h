#pragma once
#include <vector>
#include "tetrisBoard.h"
#include "block.h"

class Tetris {
public:
	int level;
	int score;
	bool pause;
	bool gameOver;
	TetrisBoard board;
	
	Tetris();
	void Start(Font font);
	void DrawOverLay(Font font, const char* text);
	void DrawSidbar(Font font);
	void HandleKeyPress();
	Block GetRandomBlock();

private:
	std::vector<Block> blocks;
	Block currBlock;
	Block nextBlock;
	void Reset();
	void UpdateLevel();
	bool IsBlockOutside();
	bool BlockFits(); // check block can move? if fit -> can move
	void MoveBlockDown();
	void MoveBlockLeft();
	void MoveBlockRight();
	void RotateBlock();
	void LockBlock();
};