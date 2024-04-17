#include "Basket.h"
#include "raylib.h"
#include "defines.h"



Basket::Basket(/* args */)
{
    basket = LoadTexture("./FB Assets/basket.png");
    position = {static_cast<float>(SCREEN_W) / 2 - basket.width / 2, static_cast<float>(SCREEN_H) - basket.height};
    score = 0;
}

Basket::~Basket()
{
    UnloadTexture(basket);
}

void Basket::Draw()
{
    DrawTexture(basket, position.x, position.y, WHITE);
}