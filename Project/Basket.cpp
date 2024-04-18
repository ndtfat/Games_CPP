#include "Basket.h"
#include "raylib.h"
#include "defines.h"



Basket::Basket(/* args */)
{
    size = {150, 30};
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
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
        position.x -= 8;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        position.x += 8;
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

Rectangle Basket::getCollisionRec()
{
    return Rectangle{position.x, position.y, size.x, size.y};
}
