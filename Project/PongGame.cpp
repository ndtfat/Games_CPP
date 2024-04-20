#include "PongGame.h"
#include <iostream>


PongGame::PongGame() {
    
    std::cout << "Starting the game" << std::endl;

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
        // Drawing
        //ClearBackground(Dark_Green);
        DrawRectangle(0, 0, screen_width , screen_height, Green);
        //DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
        DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
        ball.Draw();
        cpu.Draw();
        player.Draw();
        DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, BLACK);
        DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80, BLACK);

}