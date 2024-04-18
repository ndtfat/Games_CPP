#pragma once
#include <raylib.h>
#include <cstdlib>

using namespace std;
class Fruit
{
private:
    int score;
    float size;
    float gravity;
    Vector2 position;
public:
    Fruit();
    ~Fruit();

    void Draw();
    void Update();
    void Respawn();
};


