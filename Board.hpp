#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <vector>

class Board
{
    std::string position;
public:

    Board(int _width = 3, int _height = 3);
    Board(const std::string &pos);
    Board(const Board &other);

    Board &operator=(const Board &other);
    bool operator==(const Board &other) const;

    bool PlaceSymbol(int x, int y, const std::string &symbol);
    bool IsValidMove(int x, int y) const;
    bool IsFree(int x, int y) const;
    void Reset();
    bool CheckWin(const std::string &symbol) const;
    bool CheckDraw() const;

    int GetWidth() const;
    int GetHeight() const;

    std::string ToString() const;
};

std::istream &operator>>(std::istream &in, Board &board);
std::ostream &operator<<(std::ostream &out, const Board &board);
