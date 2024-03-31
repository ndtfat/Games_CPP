#include <iostream>
#include <string>
#include "raylib.h"
#include "defines.h"
#include "tetris.h"

typedef enum Game {TETRIS, SNAKE, FRUIT_BASKET, INVADOR, MENU};

int main() {
	InitWindow(SCREEN_W, SCREEN_H, "Games");
	SetTargetFPS(60);

	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
	std::string title = "GAMES";

	Game playedGame = TETRIS;
	Tetris tetris = Tetris();

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// draw title
		Vector2 titleOffset = {SCREEN_W / 2 - MeasureText(title.c_str(), TITLE_SIZE)/2, 10};
		DrawTextEx(font, title.c_str(), titleOffset, TITLE_SIZE, 10, GRAY);
		// start game
		switch (playedGame) {
			case MENU:
				title = "GAMES";
				break;
			case TETRIS:
				title = "TETRIS";
				tetris.Start(font);
				break;
			case SNAKE:
				title = "SNAKE";
				//snake.start
				break;
			case FRUIT_BASKET:
				title = "FRUIT BASKET";
				//fruitBasket.start
				break;
			case INVADOR:
				title = "INVADOR";
				//invador.start
				break;
			default:
				title = "GAMES";
				break;
		}

		// 
		EndDrawing();
	}

	CloseWindow();
}