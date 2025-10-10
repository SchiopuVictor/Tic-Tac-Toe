#pragma once
#include "Board.hpp"
#include <iostream>

class AI
{
public:
    char symbol;

    AI();
    AI(char symbol);

    AI(const AI &other);

    AI &operator=(const AI &other);

    bool operator==(const AI &other) const;

    void MakeMove(Board board);
};
std::istream &operator>>(std::istream &in, AI &ai);

std::ostream &operator<<(std::ostream &out, const AI &ai);
