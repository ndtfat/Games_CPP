#pragma once

#include <raylib.h>

class Paddle {
public:
    float x, y;
    float width, height;
    int speed;

    Paddle();
    void Draw();
    void Update();
};

