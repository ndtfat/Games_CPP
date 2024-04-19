#pragma once
#include <raylib.h>
#include "Paddle.h"

class CpuPaddle : public Paddle {
public:
    void Update(int ball_y);
};
