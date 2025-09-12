#pragma once
#include <array>
#include <string>

class Board {
    int width;
    int height;

public:
    Board();

    bool PlaceSymbol(int x, int y, char symbol);
    bool IsFree(int x, int y);
    void Reset();
    void Display(); 
    bool CheckWin(char symbol);
    bool CheckDraw();
};
