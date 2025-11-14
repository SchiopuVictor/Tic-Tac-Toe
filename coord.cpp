#include "coord.hpp"

std::istream &operator>>(std::istream &in, Coord &coord)
{
    in >> coord.x >> coord.y;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Coord &coord)
{
    out << coord.x << " " << coord.y;
    return out;
}