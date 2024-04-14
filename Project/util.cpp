#include "util.h"
#include "raylib.h"

double lastUpdateTime = 0;

// Function to check if a timeout has occurred
bool TimeOut(double interval) {
    double currentTime = GetTime(); // Assuming GetTime() is defined somewhere
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

const char* getGameName(Game game) {
	switch (game) {
	case TETRIS:
		return "TETRIS";
	case SNAKE:
		return "SNAKE";
	case FRUIT_BASKET:
		return "FRUIT BASKET";
	case INVADOR:
		return "INVADOR";
	default:
		return "GAME_NAME";
	}
}

const char* getAuthorName(Game game) {
	switch (game) {
	case TETRIS:
		return "[Phat Nguyen]";
	case SNAKE:
		return "[Hung Thai]";
	case FRUIT_BASKET:
		return "[Thang Ho]";
	case INVADOR:
		return "[Thai Ngo]";
	default:
		return "Phat Nguyen";
	}
}