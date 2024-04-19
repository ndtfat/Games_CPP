#include  "raylib.h"
#include "Fruit.h"
#include <cstdlib>
#include "defines.h"


Fruit::Fruit()
{
    Respawn();
}

Fruit::~Fruit()
{
}

void Fruit::Draw()
{
    DrawCircleV(position, size, fruitColor);
}

void Fruit::Update()
{
    position.y += gravity;
    gravity += 0.3;
    if (position.y > GetScreenHeight())
    {
        Respawn();
    }

}

int Fruit::Collision(Rectangle basket)
{
    if (CheckCollisionCircleRec(Vector2{position.x, position.y}, size, basket))
    {
        Respawn();
        return score;
    }
    return 0;
}

void Fruit::Respawn()
{
    position = {static_cast<float>(GetRandomValue(300, SCREEN_W - 300)), 0};
    score = GetRandomValue(5, 15);
    size = score * 1.5;
    gravity = size*0.2;
}



GreenFruit::GreenFruit()
{
    fruitColor = GREEN;
}

GreenFruit::~GreenFruit()
{
}

RedFruit::RedFruit()
{
    fruitColor = RED;
}

RedFruit::~RedFruit()
{
}

