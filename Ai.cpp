#include "AI.hpp"
#include <iostream>

AI::AI(char symbol) : symbol(symbol) {}

void AI::MakeMove(Board board) {
    std::cout << "AI makes a move with symbol " << symbol << "\n";
}
