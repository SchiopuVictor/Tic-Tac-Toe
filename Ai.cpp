#include "AI.hpp"
#include <iostream>

AI::AI() : symbol(' ') {}

AI::AI(char symbol) : symbol(symbol) {}

AI::AI(const AI& other) : symbol(other.symbol) {}

AI& AI::operator=(const AI& other) {
    if (this != &other) {
        symbol = other.symbol;
    }
    return *this;
}

bool AI::operator==(const AI& other) const {
    return symbol == other.symbol;
}

std::istream& operator>>(std::istream& in, AI& ai) {
    std::cout << "Introdu simbolul AI: ";
    in >> ai.symbol;
    return in;
}

std::ostream& operator<<(std::ostream& out, const AI& ai) {
    out << "AI cu simbolul: " << ai.symbol;
    return out;
}

void AI::MakeMove(Board board) {
    std::cout << "AI face o mutare cu simbolul " << symbol << "\n";
}
