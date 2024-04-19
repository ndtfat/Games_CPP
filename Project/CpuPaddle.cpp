#include "CpuPaddle.h"

void CpuPaddle::Update(int ball_y) {
    if (y + height / 2 > ball_y) {
        y -= speed;
    }
    if (y + height / 2 <= ball_y) {
        y += speed;
    }
    // Limit movement within screen boundaries
    if (y <= 0) {
        y = 0;
    }
    if (y + height >= GetScreenHeight()) {
        y = GetScreenHeight() - height;
    }
}
