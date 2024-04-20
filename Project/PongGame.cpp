#include "PongGame.h"
#include <iostream>


PongGame::PongGame() {
    bool isGameRunning = true;
    std::cout << "Starting the game" << std::endl;

    InitWindow(screen_width, screen_height, "Pong Game :D");
    SetTargetFPS(60);
    ball.radius = 20;
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.speed_x = 8;
    ball.speed_y = 8;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 6;

    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 6;
  
}

void PongGame::start() {
    if (isGameRunning) {
        // Drawing
        //ClearBackground(Dark_Green);
        DrawRectangle(0, 0, screen_width, screen_height, Green);
        //DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
        DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
        ball.Draw();
        cpu.Draw();
        player.Draw();
        DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, BLACK);
        DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80, BLACK);

        // Updating
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        // Checking for collisions
        if (CheckCollisionCircleRec({ ball.x, ball.y }, ball.radius, { player.x, player.y, player.width, player.height })) {
            ball.speed_x *= -1;
        }

        if (CheckCollisionCircleRec({ ball.x, ball.y }, ball.radius, { cpu.x, cpu.y, cpu.width, cpu.height })) {
            ball.speed_x *= -1;
        }
        if (cpu_score == 10) {
            isGameRunning = false;
            winner = "CPU";
        }
        if (player_score == 10) {
            isGameRunning = false;
            winner = "PLAYER";
        }
            
    }
    else {
        DrawRectangle(0, 0, screen_width, screen_height, Light_Green);
        DrawText(("Game Over - " + winner + " wins!").c_str(), GetScreenWidth() / 2 - MeasureText(("Game Over - " + winner + " wins!").c_str(), 60) / 2, GetScreenHeight() / 2 - 50, 60, BLACK);
        DrawText("Press Space to continue", GetScreenWidth() / 2 - MeasureText("Press Space to continue", 30) / 2, GetScreenHeight() / 2 + 50, 30, DARKGRAY);
        // Chờ người chơi nhấn nút Space để tiếp tục trò chơi sau khi kết thúc
        if (IsKeyPressed(KEY_SPACE)) {
            // Đặt lại điểm số và khởi tạo lại trò chơi
            player_score = 0;
            cpu_score = 0;
            ball.ResetBall();
            isGameRunning = true;  // Bật lại trạng thái trò chơi
        }
    }
}
