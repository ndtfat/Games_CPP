#pragma once
#include<raylib.h>

class FruitBasket
{
private:
    int score;
    int highScore;

public:
    void update();
    void start();
    void draw();
    void setScore(int score);
    void addScore(int score);
    void minusScore(int score);
    void drawScore();

    FruitBasket(/* args */);
    ~FruitBasket();
};

