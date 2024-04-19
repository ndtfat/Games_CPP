#include "FB_Board.h"
#include <raylib.h>
#include "defines.h"

Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

FBBoard::FBBoard()
{
}


void FBBoard::Draw(int score, int highScore)
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
    DrawTextEx(font, TextFormat("High Score: %i", highScore), {10, 40}, 20, 2, textColor);
}


void FBBoard::Init()
{
}

