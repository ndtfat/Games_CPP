#include "snakemove.h"
#include "defines.h"
#include <raymath.h>
#include <deque>
Snakemove::Snakemove(){

}
void Snakemove::Draw() {
	for (unsigned int i = 0; i < body.size(); ++i)
	{
		float x = body[i].x;
		float y = body[i].y;
		Rectangle segment = Rectangle{ SNAKE_Offset+260 + x * SNAKE_cellSize,SNAKE_Offset- 10 + y * SNAKE_cellSize, (float)SNAKE_cellSize, (float)SNAKE_cellSize };
		DrawRectangleRounded(segment, 0.5, 6, DARKGREEN);	
	}
}


void Snakemove::Update() {
	body.push_front(Vector2Add(body[0], direction));
	if (addSegment == true){
		addSegment = false;
	}
	else {
		body.pop_back();		
	}
}
void Snakemove::Reset() {
	body = { Vector2{6,9},Vector2{5,9}, Vector2{4,9} };
}