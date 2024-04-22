#pragma once
using namespace std;
#include <raylib.h>
#include <vector>
class FBBoard {
public:
	FBBoard();
	void Draw(int score, int highScore, int lives);
	void Init();
	void GameOver(int score, int highScore);
};