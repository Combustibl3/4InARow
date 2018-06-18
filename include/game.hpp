#pragma once

#include <iostream>

class game
{
public:
    game();
    ~game();
    int createfield();
    int check(int playerID, int y, int x);
    int placechip(int playerID, int x);
    int emptyfield();
    int getValue(int row, int column);

private:
    int field[42];
};

