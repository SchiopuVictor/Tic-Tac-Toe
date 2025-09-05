#pragma once
#include <array>
#include <string>

class Board {
    int width;
    int height;

public:
    Board();

    bool PlaceSymbol(int x, int y, char symbol);
    bool IsFree(int x, int y) const;
    void Reset();
    void Display() const; 
    bool CheckWin(char symbol) const;
    bool CheckDraw() const;
};
