#pragma once
#include "raylib.h"

class Basket
{
private:
    /* data */
public:
    Vector2 size;
    Vector2 position;
    Basket(/* args */);
    ~Basket();

    void Draw();
    void Update();
    Rectangle getCollisionRec();

};

