#pragma once
#include <iostream>
#include <memory>
#include <string>

class Board
{
public:
    int width;
    int height;

    Board(int _width = 3, int _height = 3);
    Board(const Board &other);

    Board &operator=(const Board &other);
    bool operator==(const Board &other) const;

    bool PlaceSymbol(int x, int y, const std::string &symbol);
    bool IsFree(int x, int y);
    void Reset();
    void Display();
    bool CheckWin(const std::string &symbol);
    bool CheckDraw();

    int get_width() const { return width; }
    int get_height() const { return height; }
};

std::istream &operator>>(std::istream &in, Board &board);
std::ostream &operator<<(std::ostream &out, const Board &board);
