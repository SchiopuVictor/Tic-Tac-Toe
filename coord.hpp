#pragma once

#include <iostream>

struct Coord
{
    int x;
    int y;

    Coord(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

std::istream &operator>>(std::istream &in, Coord &coord);
std::ostream &operator<<(std::ostream &out, const Coord &coord);
