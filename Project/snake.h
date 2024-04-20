#include<raylib.h>
#include "Food.h"
#include "snakemove.h"
#include "snakeboard.h"
class Snake {
public:
	Snakemove snakemove = Snakemove();
	Food food = Food(snakemove.body);	
	snakeBoard snakeboard = snakeBoard();
	void Start();
private:
	void Draw();
	void HandleInput();
	void CheckCollisionWithFood();
	void CheckCollisionWithEdges();
	void CheckCollisionWithTail();
	void GameOver();
	int score = 0;
	bool running = true;
	bool paused = false;
};