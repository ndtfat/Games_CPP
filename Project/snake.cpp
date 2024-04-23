#include "food.h"
#include "snakeboard.h"
#include "snakemove.h"
#include "snake.h"
#include "defines.h"
#include <deque>
#include <raymath.h>
#include<raylib.h>
#include <iostream>
#include "util.h"
using namespace std;

void Snake::Start() {
    snakeboard.Init();
    Draw();
    HandleInput();
    CheckCollisionWithFood();
    CheckCollisionWithEdges();
    CheckCollisionWithTail();
}
void Snake::Draw() {
 
    snakemove.Draw();
    food.Draw();
    snakeboard.Draw();
    // draw score
    DrawText(TextFormat("Score:"" %i", score), SNAKE_Offset + 660, SNAKE_Offset + SNAKE_cellCount * SNAKE_cellSize - 530, 20, BLACK);
    if (paused)
    {
        snakeboard.Paused();
        DrawText(TextFormat("Pause"), SNAKE_Offset + 370, SNAKE_Offset + SNAKE_cellCount * SNAKE_cellSize - 330, 100, BROWN);
    }
}

void Snake::HandleInput() {
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_R:
        GameOver();
        break;
    case KEY_P:
        paused = !paused;
        break;
    default:
        break;
    }
    if (!paused) {
        if (TimeOut(0.4))
        {
            snakemove.Update();
        }
        if (IsKeyPressed(KEY_UP) && snakemove.direction.y != 1)
        {
            snakemove.direction = { 0,-1 };
            running = true;
        }
        if (IsKeyPressed(KEY_DOWN) && snakemove.direction.y != -1)
        {
            snakemove.direction = { 0,1 };
            running = true;
        }
        if (IsKeyPressed(KEY_RIGHT) && snakemove.direction.x != -1)
        {
            snakemove.direction = { 1,0 };
            running = true;
        }
        if (IsKeyPressed(KEY_LEFT) && snakemove.direction.x != 1)
        {
            snakemove.direction = { -1,0 };
            running = true;
        }
    }
}
void Snake::CheckCollisionWithFood() {
    {
        if (Vector2Equals(snakemove.body[0], food.position))
        {
            food.position = food.GenerateRandomPos(snakemove.body);
            snakemove.addSegment = true;
            score++;
        }
    }
}
void Snake::CheckCollisionWithEdges() {
    if (snakemove.body[0].x == SNAKE_cellCount || snakemove.body[0].x == -1)
    {
        GameOver();
    }
    if (snakemove.body[0].y == SNAKE_cellCount || snakemove.body[0].y == -1)
    {
        GameOver();
    }
}

void Snake::CheckCollisionWithTail()
{
    deque<Vector2> headlessBody = snakemove.body;
    if (headlessBody.size() > 3) {
        headlessBody.pop_front();
        if (ElementInDeque(snakemove.body[0], headlessBody))
        {
            GameOver();
        }
    }
}

void Snake::GameOver()
{
    snakemove.Reset();
    food.position = food.GenerateRandomPos(snakemove.body);
    running = false;
    score = 0;
}