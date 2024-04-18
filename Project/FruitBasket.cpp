#include <raylib.h>
#include "FruitBasket.h"
#include "FB_Board.h"
#include "Basket.h"
#include "Fruit.h"


FBBoard fbBoard;
Basket basket;
Fruit fruit;

FruitBasket::FruitBasket()
{
}

FruitBasket::~FruitBasket()
{
}

void FruitBasket::draw()
{
    fbBoard.Draw();
    basket.Draw();
    fruit.Draw();
}

void FruitBasket::start()
{

    fbBoard.Init();
    update();
    draw();
}

void FruitBasket::update()
{
    fruit.Update();
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