#include "raylib.h"
#include <iostream>
#include <string>
#include "tetris.h"

#define TITLE_SIZE 50

// screen size (with - height)
#define SCREEN_W 1300
#define SCREEN_H 700

int main() {
	InitWindow(SCREEN_W, SCREEN_H, "Games");
	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

	std::string title = "GAMES";
	Vector2 titleOffset = {SCREEN_W / 2 - MeasureText(title.c_str(), TITLE_SIZE)/2, 10};

	Tetris tetris = Tetris(SCREEN_W);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// draw title
		DrawTextEx(font, title.c_str(), titleOffset, TITLE_SIZE, 10, GRAY);

		//
		//tetris.Draw();

		EndDrawing();
	}

	CloseWindow();
}