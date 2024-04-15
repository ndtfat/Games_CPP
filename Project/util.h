#pragma once
#include "defines.h"
#include <deque>

bool TimeOut(double interval);
const char* getGameName(Game game); 
const char* getAuthorName(Game game);
bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);