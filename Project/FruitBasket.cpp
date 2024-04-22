#include <raylib.h>
#include "FruitBasket.h"
#include "FB_Board.h"
#include "Basket.h"
#include "Fruit.h"
#include <iostream>


FBBoard fbBoard;
Basket basket;
GreenFruit greenFruit;
RedFruit redFruit;

int score = 0;
int highScore = 0;
int lives = 3;
bool penalty = true;
bool gameOver = false;
FruitBasket::FruitBasket()
{
}

FruitBasket::~FruitBasket()
{
}

void FruitBasket::draw()
{
    fbBoard.Draw(score, highScore, lives);
    basket.Draw();
    greenFruit.Draw();
    redFruit.Draw();
}

void FruitBasket::start()
{
    if(gameOver)
    {
        fbBoard.GameOver(score, highScore);
        if (IsKeyPressed(KEY_R))
        {
            restart();
        }
        return;
    }
    if (score > 20 && penalty)
    {
    penalty = false;
    }
    update();
    draw();
}

void FruitBasket::update()
{

    greenFruit.Update();
    redFruit.Update();
    basket.Update();
    addScore(greenFruit.Collision(basket.getCollisionRec()));
    minusScore(redFruit.Collision(basket.getCollisionRec()));
}

void FruitBasket::setScore(int score)
{
    this->score = score;
    if (score > highScore)
    {
        highScore = score;
    }
}

void FruitBasket::addScore(int score)
{
    this->score += score;
    if (this->score > highScore)
    {
        highScore = this->score;
    }
}

void FruitBasket::minusScore(int score)
{
    this->score -= score;
    if (score != 0 && !penalty) 
    {
    lives--;
    }    
    if (this->score < 0)
    {
        this->score = 0;
    }
    if (lives == 0)
    {
        gameOver = true;
    }
}

void FruitBasket::restart()
{
    score = 0;
    lives = 3;
    gameOver = false;
    penalty = true;
    greenFruit.Respawn();
    redFruit.Respawn();
}