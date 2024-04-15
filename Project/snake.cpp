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

Snake::Snake() {
    InitAudioDevice;
    eatSound = LoadSound("C:/Users/ADMIN/Desktop/OPP Project/SnakeGame/Games_CPP/Sound/eat.mp3");
    wallSound = LoadSound("C:/Users/ADMIN/Desktop/OPP Project/SnakeGame/Games_CPP/Sound/wall.mp3");
}
Snake::~Snake() {
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice;
}

void Snake::start() {
    snakeboard.Init();
    Draw();
    HandleInput();
    CheckCollisionWithFood();
    CheckCollisionWithEdges();
    CheckCollisionWithTail();
    HandleKeyPressed();
}
void Snake::Draw() {
    snakemove.Draw();
    food.Draw();
    snakeboard.Draw();
    // draw score
    DrawText(TextFormat("Score:"" %i", score), SNAKE_Offset + 660, SNAKE_Offset + SNAKE_cellCount * SNAKE_cellSize-530, 20, BLACK);
}
void Snake::Update()
{ 
    
}
void Snake::HandleInput() {
    if (TimeOut(0.5))
    {
        snakemove.Update();
    }
    if (IsKeyPressed(KEY_UP)&& snakemove.direction.y !=1)
    {
        snakemove.direction = { 0,-1 };
        running = true;
    }
    if (IsKeyPressed(KEY_DOWN)&& snakemove.direction.y != -1)
    {
        snakemove.direction = { 0,1 };
        running = true;
    }
    if (IsKeyPressed(KEY_RIGHT)&& snakemove.direction.x != -1)
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
void Snake::HandleKeyPressed() {
    int keyPressed = GetKeyPressed();
    if (keyPressed == KEY_R) {
        snakemove.Reset();
        food.position=food.GenerateRandomPos(snakemove.body);
    }
}
void Snake::CheckCollisionWithFood() {
    {
        if (Vector2Equals(snakemove.body[0], food.position))
        {
            food.position = food.GenerateRandomPos(snakemove.body);
            snakemove.addSegment = true;
            score++;
            PlaySound(eatSound);
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
void Snake::GameOver()
{
    snakemove.Reset();
    food.position = food.GenerateRandomPos(snakemove.body);
    running = false;
    score = 0;
    PlaySound(wallSound);

}

void Snake::CheckCollisionWithTail()
{
    deque<Vector2> headlessBody = snakemove.body;
    headlessBody.pop_front();
    if (ElementInDeque(snakemove.body[0], headlessBody))
    {
        GameOver();
    }
}
