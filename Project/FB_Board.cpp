#include "FB_Board.h"
#include <raylib.h>
#include "defines.h"

Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

FBBoard::FBBoard()
{
}


void FBBoard::Draw(int score, int highScore, int lives)
{
    Color textColor;
    if (score == highScore)
    {
        textColor = GREEN;
    }
    else
    {
        textColor = RED;
    }
    DrawTextEx(font, TextFormat("Score: %i", score), {10, 10}, 20, 2, textColor);
    DrawTextEx(font, TextFormat("High Score: %i", highScore), { 10, 40 }, 20, 2, textColor);
    DrawTextEx(font, TextFormat("Lives: %i", lives), { 10, 70 }, 20, 2, textColor);
    DrawTextEx(font, TextFormat("[X] - Exit"), { 10, 100 }, 20, 2, textColor);
}


void FBBoard::Init()
{
}

void FBBoard::GameOver(int score, int highScore)
{
    DrawTextEx(font, TextFormat("Game Over"), { 300, 250 }, 40, 2, RED);
    DrawTextEx(font, TextFormat("Score: %i", score), { 300, 270 }, 20, 2, RED);
    DrawTextEx(font, TextFormat("High Score: %i", highScore), { 400, 270 }, 20, 2, RED);
}
