#include<raylib.h>
#include "Food.h"
#include "snakemove.h"
#include "snakeboard.h"
class Snake {
public:
	int score = 0;
	Sound eatSound;
	Sound wallSound;
	Snakemove snakemove = Snakemove();
	Food food = Food(snakemove.body);	
	snakeBoard snakeboard = snakeBoard();
	void Draw();
	void start();
	Snake();
	~Snake();
	void Update();
	void HandleInput();
	void CheckCollisionWithFood();
	void CheckCollisionWithEdges();
	void CheckCollisionWithTail();
	void GameOver();
	void HandleKeyPressed();
	bool running = true;
};