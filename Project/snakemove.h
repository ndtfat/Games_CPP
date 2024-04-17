#pragma once
#include <raylib.h>
#include <deque>
#include "defines.h"
using namespace std;
class Snakemove {
public:
	deque<Vector2>body = { Vector2{6,9},Vector2{5,9}, Vector2{4,9} };
	Vector2 direction{ 1,0 };
	void Draw();
	Snakemove();
	void Update();
	void Loop();
	void Reset();
	bool addSegment = false;
private:
	int stepCount = 0;
	int cellsMoved = 0;
};