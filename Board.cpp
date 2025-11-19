#include "Board.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

Board::Board(int _width, int _height) : position(_width * _height, '.') {}
Board::Board(const std::string &pos) : position(pos) {}
Board::Board(const Board &other) : position(other.position) {}

Board &Board::operator=(const Board &other)
{
    if (this != &other)
    {
        position = other.position;
    }
    return *this;
}

bool Board::operator==(const Board &other) const
{
    return position == other.position;
}

bool Board::PlaceSymbol(int x, int y, const std::string &symbol)
{
    if (IsFree(x, y))
    {
        position[y * GetWidth() + x] = symbol[0];
        return true;
    }

    return false;
}

bool Board::IsValidMove(int x, int y) const
{
    return x >= 0 && x < GetWidth() && y >= 0 && y < GetHeight() && IsFree(x, y);
}

bool Board::IsFree(int x, int y) const
{
    return position[y * GetWidth() + x] == ' ';
}

void Board::Reset()
{
    std::fill(position.begin(), position.end(), ' ');
}

bool Board::CheckWin(const std::string &symbol) const
{
    if (symbol.empty())
        return false;
    char s = symbol[0];
    int n = GetWidth();

    for (int y = 0; y < n; ++y)
    {
        bool rowWin = true;
        for (int x = 0; x < n; ++x)
        {
            if (position[y * n + x] != s)
            {
                rowWin = false;
                break;
            }
        }
        if (rowWin)
            return true;
    }

    for (int x = 0; x < n; ++x)
    {
        bool colWin = true;
        for (int y = 0; y < n; ++y)
        {
            if (position[y * n + x] != s)
            {
                colWin = false;
                break;
            }
        }
        if (colWin)
            return true;
    }

    bool diag1Win = true;
    for (int i = 0; i < n; ++i)
    {
        if (position[i * n + i] != s)
        {
            diag1Win = false;
            break;
        }
    }
    if (diag1Win)
        return true;

    bool diag2Win = true;
    for (int i = 0; i < n; ++i)
    {
        if (position[i * n + (n - 1 - i)] != s)
        {
            diag2Win = false;
            break;
        }
    }
    return diag2Win;
}

bool Board::CheckDraw() const
{

    for (char c : position)
    {
        if (c == ' ')
            return false;
    }

    return true;
}

int Board::GetWidth() const { return static_cast<int>(sqrt(position.size())); }
int Board::GetHeight() const { return static_cast<int>(sqrt(position.size())); }

std::string Board::ToString() const
{
    return position;
}

std::istream &operator>>(std::istream &in, Board &board)
{
    std::string str;
    in >> str;
    board = Board(str);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Board &board)
{
    out << board.ToString();
    return out;
}
