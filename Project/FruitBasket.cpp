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
    if(lives==0)
    {
        score = 0;
        lives = 3;
        penalty = true;
    }
    if (score > 20 && penalty)
    {
    penalty = false;
    }
    fbBoard.Init();
    update();
    draw();
}

void FruitBasket::update()
{

    addScore(greenFruit.Collision(basket.getCollisionRec()));
    minusScore(redFruit.Collision(basket.getCollisionRec()));
    greenFruit.Update();
    redFruit.Update();
    basket.Update();
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
}