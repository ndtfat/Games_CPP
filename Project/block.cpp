#include "defines.h"
#include "block.h"

Block::Block() {
	id = 1;
	offset = { 0, 0 };
	rotationState = 0;
}

void Block::Draw(int offsetX, int offsetY) {
	std::vector<Position> tiles = GetCellPositions();
	for (Position item : tiles) {
		DrawRectangle(item.col * TT_CELL_SIZE + offsetX, item.row * TT_CELL_SIZE + offsetY, TT_CELL_SIZE - 1, TT_CELL_SIZE - 1, GRAY);
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