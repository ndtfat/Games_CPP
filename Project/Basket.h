#pragma once
#include "raylib.h"

class Basket
{
private:
    /* data */
    Texture2D basket;
    Vector2 position;
    int score;
public:
    Basket(/* args */);
    ~Basket();

    void Draw();
};

