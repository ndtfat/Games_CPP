#include "raylib.h"

static const int screenWidth = 1300;
static const int screenHeight = 700;

int main() {
	InitWindow(screenWidth, screenHeight, "Games");
	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("HEHEHE", screenWidth/2 - 25, screenHeight/2 - 25, 50, GRAY);
		EndDrawing();
	}

	CloseWindow();
}