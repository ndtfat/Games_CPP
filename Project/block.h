#pragma once
#include <map>
#include <vector>
#include <raylib.h>
#include "position.h"

class Block {
public:
	int id;
	Vector2 offset;
	std::map<int, std::vector<Position>> cells;

	Block();
	void Draw(int offsetX, int offsetY);
	void Move(int rowStep, int colStep);
	void Rotate();
	void UndoRotate();
	std::vector<Position> GetCellPositions();


private:
	int rotationState;
};