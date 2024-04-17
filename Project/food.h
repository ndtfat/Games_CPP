#pragma once 
#include<raylib.h>
#include<deque>
using namespace std;
class Food {
public:
	Vector2 position = { 5,6 };
	void Draw();
	Food(deque<Vector2> snakeBody);
	~Food();
	Vector2 GenerateRandomPos(deque<Vector2> snakeBody);
	
private:
	Vector2 GenerateRandomCell();
	Texture2D texture;
};