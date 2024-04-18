#pragma once
#include "raylib.h"

class Basket
{
private:
    /* data */
    Vector2 size;
    Vector2 position;
public:
    Basket(/* args */);
    ~Basket();

    void Draw();
    void Update();

};

