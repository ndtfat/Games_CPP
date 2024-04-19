#pragma once
using namespace std;
#include <raylib.h>
#include <vector>
class FBBoard {
public:
	FBBoard();
	void Draw(int score, int highScore);
	void Init();
};