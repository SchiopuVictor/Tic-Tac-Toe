#include "Board.hpp"
#include <iostream>

Board::Board(int _height, int _width) : width(_width), height(_height) {}
Board::Board(const Board &other) : width(other.width), height(other.height)
{
}

const Board &Board::operator=(const Board &other)
{
    if (this != &other)
    {
        width = other.width;
        height = other.height;
    }
    return *this;
}

bool Board::operator==(const Board &other) const
{
    return width == other.width && height == other.height;
}

bool Board::PlaceSymbol(int x, int y, char symbol)
{
    std::cout << "Placing " << symbol << " at (" << x << "," << y << ")\n";
    return true;
}

bool Board::IsFree(int x, int y)
{
    return true;
}

void Board::Reset()
{
    std::cout << "Board reset.\n";
}

void Board::Display()
{
    std::cout << "Displaying board...\n";
}

bool Board::CheckWin(char symbol)
{
    return false;
}

bool Board::CheckDraw()
{
    return false;
}

std::istream &operator>>(std::istream &in, Board &board)
{
    int w, h;
    in >> w >> h;
    board = Board(w, h);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Board &board)
{
    out << board.get_width() << " " << board.get_height();
    return out;
}
