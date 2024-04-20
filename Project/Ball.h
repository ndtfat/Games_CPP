#pragma once

#include <raylib.h>
#include "Score.h"

class Ball {
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    Ball();
    void Draw();
    void Update();
    void ResetBall();
};
