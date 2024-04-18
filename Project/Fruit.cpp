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
    DrawCircleV(position, size, RED);
}

void Fruit::Update()
{
    position.y += gravity;
    gravity += 0.1;
    if (position.y > GetScreenHeight())
    {
        Respawn();
    }
}

void Fruit::Respawn()
{
    position = {static_cast<float>(GetRandomValue(100, SCREEN_W - 100)), 0};
    score = GetRandomValue(1, 10);
    size = score + 10;
    gravity = score*0.5;
}