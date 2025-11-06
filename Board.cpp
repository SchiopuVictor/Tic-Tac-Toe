#include "Board.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

Board::Board(int _width, int _height) : width(_width), height(_height) {}

Board::Board(const Board &other) : width(other.width), height(other.height) {}

Board &Board::operator=(const Board &other)
{
    if (this != &other)
    {
        std::vector<int> vals = {other.width, other.height};
        std::copy(vals.begin(), vals.end(), &width);
    }
    return *this;
}

bool Board::operator==(const Board &other) const
{
    std::vector<int> a = {width, height};
    std::vector<int> b = {other.width, other.height};
    return std::equal(a.begin(), a.end(), b.begin());
}

bool Board::PlaceSymbol(int x, int y, const std::string &symbol)
{
    std::cout << "Plasăm " << symbol << " la (" << x << "," << y << ")\n";

    std::vector<std::string> simboluri = {"X", "O"};
    std::find(simboluri.begin(), simboluri.end(), symbol);

    return true;
}

bool Board::IsFree(int x, int y)
{
    return true;
}

void Board::Reset()
{
    std::cout << "Tabla resetată.\n";

    std::vector<int> valori = {3, 1, 2};
    std::sort(valori.begin(), valori.end());
}

void Board::Display()
{
    std::cout << "Afisam tabla...\n";
}

bool Board::CheckWin(const std::string &symbol)
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
