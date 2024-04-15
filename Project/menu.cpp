#include "raylib.h"
#include "menu.h"
#include "defines.h"
#include "util.h"
#include "tetris.h"	
#include "blocks.cpp"

Menu::Menu(Font font) {
	this->font = font;
	gameOpen = MENU;
	tetrisBlocks = { JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
	currTTBlock = GetTetrisBlocksLoop();
	nextTTBlock = GetTetrisBlocksLoop();
}

void Menu::Draw() {
	DrawGameBox(GAME_BOX_1_X, GAME_BOX_1_Y, TETRIS);
	DrawGameBox(GAME_BOX_2_X, GAME_BOX_1_Y, SNAKE);
	DrawGameBox(GAME_BOX_1_X, GAME_BOX_2_Y, FRUIT_BASKET);
	DrawGameBox(GAME_BOX_2_X, GAME_BOX_2_Y, INVADOR);
}

void Menu::DrawGameBox(int x, int y, Game game) {
	bool isHover = IsMouseHover(
		{ (float)x, (float)y },
		{ GAME_BOX_W + MN_PADDING * 2, GAME_BOX_H + MN_PADDING * 2, }
	);
	Color padColor = isHover ? DARKBROWN : GRAY;
	Color boxColor = LIGHTGRAY;

	DrawRectangle(x, y, GAME_BOX_W + MN_PADDING * 2, GAME_BOX_H + MN_PADDING * 2, padColor);
	DrawRectangle(x + MN_PADDING, y + MN_PADDING, GAME_BOX_W, GAME_BOX_H, boxColor);

	// Show game name when not hover
	// Show game window when hover
	if (!isHover) {
		const char* gameName = getGameName(game);
		const char* authorName = getAuthorName(game);
		Vector2 gameNameTextSize = MeasureTextEx(font, gameName, 40, 5);
		Vector2 authorNameTextSize = MeasureTextEx(font, authorName, 20, 5);
		Vector2 gameNameTextOffset = {
				(float)x + GAME_BOX_W / 2 + MN_PADDING - gameNameTextSize.x / 2,
				(float)y + GAME_BOX_H / 2 + MN_PADDING - gameNameTextSize.y / 2 - authorNameTextSize.y - 5
		};
		Vector2 authorNameTextOffset = {
				(float)x + GAME_BOX_W / 2 + MN_PADDING - authorNameTextSize.x / 2,
				gameNameTextOffset.y + gameNameTextSize.y + 5
		};
		DrawTextEx(font, authorName, authorNameTextOffset, 20, 5, GRAY);
		DrawTextEx(font, gameName, gameNameTextOffset, 40, 5, GRAY);
	} else {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			gameOpen = game;
		}

		switch (game) {
			case TETRIS:
				DrawTetris();
				break;
		}
	}
}

bool Menu::IsMouseHover(Vector2 offset, Vector2 size) {
	Vector2 mouse = GetMousePosition();
	bool isMouseInsideVerticle = (mouse.x > offset.x) && (mouse.x <= offset.x + size.x);
	bool isMouseInsideHorizone = (mouse.y > offset.y) && (mouse.y <= offset.y + size.y);

	return isMouseInsideVerticle && isMouseInsideHorizone;
}

Block Menu::GetTetrisBlocksLoop() {
	if (tetrisBlocks.empty())
	{
		tetrisBlocks = { JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
	}
	int randomIndex = rand() % tetrisBlocks.size();
	Block block = tetrisBlocks[randomIndex];
	tetrisBlocks.erase(tetrisBlocks.begin() + randomIndex);
	return block;
}

void Menu::DrawTetris() {
	if (TimeOut(0.5)) {
		currTTBlock = nextTTBlock;
		nextTTBlock = GetTetrisBlocksLoop();
	}
	currTTBlock.Draw(
		GAME_BOX_1_X - currTTBlock.offset.y * TT_CELL_SIZE + GAME_BOX_W / 2 - TT_CELL_SIZE, 
		GAME_BOX_1_Y + GAME_BOX_H / 2 - TT_CELL_SIZE
	);
}

void Menu::HandleExitGame() {
	if (IsKeyPressed(KEY_X)) {
		gameOpen = MENU;
	}
}


//
