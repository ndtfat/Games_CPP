#include "Basket.h"
#include "raylib.h"
#include "defines.h"



Basket::Basket(/* args */)
{
    size = {100, 30};
    position = {SCREEN_W/2, SCREEN_H - 100};
}

Basket::~Basket()
{
}

void Basket::Draw()
{
    DrawRectangleV(position, size, GRAY);
}

void Basket::Update()
{
    if (IsKeyDown(KEY_LEFT))
    {
        position.x -= 5;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        position.x += 5;
    }
    if (position.x < 0)
    {
        position.x = 0;
    }
    if (position.x > SCREEN_W - size.x)
    {
        position.x = SCREEN_W - size.x;
    }
}
