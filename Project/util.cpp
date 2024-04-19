#include "util.h"
#include "raylib.h"
#include <raymath.h>

bool ElementInDeque(Vector2 element, std::deque<Vector2> deque) {
	for (unsigned int i = 0; i < deque.size(); ++i) {
		if (Vector2Equals(deque[i], element)) {
			return true;
		}
	}
	return false;
}


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
	case PONG:
		return "PONG";
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
	case PONG:
		return "[Thai Ngo]";
	default:
		return "Phat Nguyen";
	}
}