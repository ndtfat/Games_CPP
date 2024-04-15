#pragma once
#include <vector>
#include "defines.h"
#include "block.h"

class Menu {
public:
	Menu(Font font);
	Font font;
	Game gameOpen;
	void Draw();
	void HandleExitGame();

private:
	Block currTTBlock;
	Block nextTTBlock;
	std::vector<Block> tetrisBlocks;
	void DrawGameBox(int x, int y, Game name);
	bool IsMouseHover(Vector2 offset, Vector2 size);
	Block GetTetrisBlocksLoop();
	void DrawTetris();
	void DrawSnake();
	void DrawFuitBasket();
	void DrawInvador();
};