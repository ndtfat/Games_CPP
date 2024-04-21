
#pragma once
#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h"
#include "Score.h"
#include <iostream>
using namespace std;
class PongGame {
public:
    PongGame();
    void start();
    Ball ball;
    Paddle player;
    CpuPaddle cpu;
    Color Green = Color{ 38, 185, 154, 255 };
    Color Dark_Green = Color{ 20, 160, 133, 255 };
    Color Light_Green = Color{ 100, 204, 184, 255 };
    Color Yellow = Color{ 243, 213, 91, 255 };
    const int screen_width = 1280;
    const int screen_height = 800;
    bool isGameRunning ;
    string winner;
};
