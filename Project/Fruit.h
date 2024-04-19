#pragma once
#include <raylib.h>
#include <cstdlib>

using namespace std;
class Fruit
{
protected:
    int score;
    float gravity;
    Color fruitColor = RED; // Fix: Changed variable name from "color" to "fruitColor"
public:
    float size;
    Vector2 position;
    Fruit();
    ~Fruit();

    void Draw();
    void Update();
    void Respawn();
    int getScore();
    int Collision(Rectangle basket);
};

class RedFruit : public Fruit
{
public:
    RedFruit();
    ~RedFruit();
};

class GreenFruit : public Fruit
{
public:
    GreenFruit();
    ~GreenFruit();
};

