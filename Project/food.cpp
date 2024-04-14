#include "food.h"
#include <raylib.h>
#include "defines.h"
#include <deque>
#include <raymath.h>
#include "functs.h"
using namespace std;
Food::Food(deque<Vector2> snakebody) {
	Image image = LoadImage("C:/Users/ADMIN/Desktop/OPP Project/SnakeGame/Games_CPP/Graphics/food.png");
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	position = GenerateRandomPos(snakebody);
}

void Food::Draw() {
	DrawTexture(texture, Offset+260+position.x * cellSize, Offset-30+position.y * cellSize, WHITE);
} 
Vector2 Food::GenerateRandomCell() {
	float x = GetRandomValue(0, cellCount - 1);
	float y = GetRandomValue(0, cellCount - 1);
	return Vector2{ x,y };
}
Vector2 Food::GenerateRandomPos(deque<Vector2> snakeBody) {
	Vector2 position = GenerateRandomCell();
	while (ElementInDeque(position, snakeBody)) {
		position = GenerateRandomCell();
	}
	return position;
}
Food::~Food() {
	UnloadTexture(texture);
}