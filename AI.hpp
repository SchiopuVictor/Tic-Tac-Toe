#pragma once
#include "Board.hpp"

class AI {
public:
    char symbol;
    AI(char symbol);
    void MakeMove(Board& board);
    void MakeOptimalMove(Board& board);
};
