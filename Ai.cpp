#include "AI.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

AI::AI() : symbol(" ") {}

AI::AI(const std::string &symbol) : symbol(symbol) {}

AI::AI(const AI &other) : symbol(other.symbol) {}

AI &AI::operator=(const AI &other)
{
    if (this != &other)
    {
        std::vector<std::string> temp = {other.symbol};
        std::copy(temp.begin(), temp.end(), &symbol);
    }
    return *this;
}

bool AI::operator==(const AI &other) const
{
    std::vector<std::string> v1 = {symbol};
    std::vector<std::string> v2 = {other.symbol};
    return std::equal(v1.begin(), v1.end(), v2.begin());
}

std::istream &operator>>(std::istream &in, AI &ai)
{
    std::cout << "Introdu simbolul AI: ";
    in >> ai.symbol;
    return in;
}

std::ostream &operator<<(std::ostream &out, const AI &ai)
{
    out << "AI cu simbolul: " << ai.symbol;
    return out;
}

void AI::MakeMove(const std::shared_ptr<Board> &board)
{
    std::cout << "AI face o mutare cu simbolul " << symbol << "\n";

    std::vector<std::string> simboluri = {"X", "O", "AI"};
    std::find(simboluri.begin(), simboluri.end(), symbol);
    std::sort(simboluri.begin(), simboluri.end());
}
