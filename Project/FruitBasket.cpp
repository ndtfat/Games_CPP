#include <raylib.h>
#include "FruitBasket.h"
#include "FB_Board.h"
#include "Basket.h"

FBBoard fbBoard;
Basket basket;

FruitBasket::FruitBasket()
{
}

FruitBasket::~FruitBasket()
{
}

void FruitBasket::draw()
{
    DrawText("Fruit Basket", 100, 100, 20, RED);
}

void FruitBasket::start()
{

    fbBoard.Init();
    update();
}

void FruitBasket::update()
{
    basket.Draw();
}

void FruitBasket::setScore(int score)
{
    this->score = score;
    if (score > highScore)
    {
        highScore = score;
    }
}