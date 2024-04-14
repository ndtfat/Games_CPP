#include "food.h"
#include "snakeboard.h"
#include "snakemove.h"
#include "snake.h"
#include "defines.h"
#include <deque>
#include <raymath.h>
#include<raylib.h>
#include <iostream>
#include "functs.h"
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
    DrawText(TextFormat("Score ""%i", score), Offset + 610, Offset + cellCount * cellSize-570, 40, BLACK);
}
void Snake::Update()
{ 
    
}
void Snake::HandleInput() {
    if (EventTriggered(0.5))
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
    if (snakemove.body[0].x == cellCount || snakemove.body[0].x == -1)
    {
        GameOver();
    }
    if (snakemove.body[0].y == cellCount || snakemove.body[0].y == -1)
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
