#pragma once

#include <iostream>

using namespace std;

class game
{
public:
    game();
    ~game();
    int createfield();
    int check(int playerID, int y, string x);
    int placechip(int playerID, string column);
    void emptyfield();
    int getValue(int row, int column);

private:
    int field[42];
    int colToInt(string column);
    int rowToInt(string row);
};

