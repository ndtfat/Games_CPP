#include "defines.h"
#include "block.h"

Block::Block() {
	offset = { 0, 0 };
	rotationState = 0;
}

void Block::Draw(int offsetX, int offsetY) {
	std::vector<Position> tiles = GetCellPositions();
	for (Position item : tiles) {
		DrawRectangle(item.col * CELL_SIZE + offsetX, item.row * CELL_SIZE + offsetY, CELL_SIZE - 1, CELL_SIZE - 1, GRAY);
	}
}

void Block::Move(int rowStep, int colStep) {
	offset.x += rowStep;
	offset.y += colStep;
}

void Block::Rotate() {
	rotationState++;
	if (rotationState == cells.size()) {
		rotationState = 0;
	}
}

void Block::UndoRotate() {
	rotationState--;
	if (rotationState == -1) {
		rotationState = cells.size() - 1;
	}
}

std::vector<Position> Block::GetCellPositions() {
	std::vector<Position> prevTiles = cells[rotationState];
	std::vector<Position> updatedTiles;

	for (Position item : prevTiles) {
		item.row += offset.x;
		item.col += offset.y;
		updatedTiles.push_back(item);
	}

	return updatedTiles;
}