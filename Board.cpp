#include "Board.hpp"
#include <iostream>

Board::Board() : width(3), height(3) {}

bool Board::PlaceSymbol(int x, int y, char symbol) {
    std::cout << "Placing " << symbol << " at (" << x << "," << y << ")\n";
    return true; 
}

bool Board::IsFree(int x, int y) {
    return true; 
}

void Board::Reset() {
    std::cout << "Board reset.\n";
}

void Board::Display() {
    std::cout << "Displaying board...\n";
}

bool Board::CheckWin(char symbol) {
    return false; 
}

bool Board::CheckDraw() {
    return false;
}
