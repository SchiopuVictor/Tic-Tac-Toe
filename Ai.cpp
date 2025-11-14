#include "AI.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>

AI::AI() : symbol("O") {
    LoadKnowledgeBase();
}

AI::AI(const std::string &symbol) : symbol(symbol) {
    LoadKnowledgeBase();
}

AI::AI(const AI &other) : symbol(other.symbol) {
    LoadKnowledgeBase();
}

AI &AI::operator=(const AI &other)
{
    if (this != &other)
    {
        symbol = other.symbol;
    }
    return *this;
}

bool AI::operator==(const AI &other) const
{
    return symbol == other.symbol;
}

Coord AI::MakeMove(const Board& board) const
{
    if(knowledgeBase.find(board.ToString()) != knowledgeBase.end())
    {
        return knowledgeBase.at(board.ToString());
    }
    int x, y;
    do {
        x = rand() % board.GetWidth();
        y = rand() % board.GetHeight();
    } while (! board.IsFree(x, y));
    return Coord(x, y);
}

std::string AI::GetName() const
{
    return "AI Player";
}

std::string AI::GetSymbol() const
{
    return symbol;
}

std::istream &operator>>(std::istream &in, AI &ai)
{
    std::string dummy;
    in >> dummy;
    ai = AI(dummy);
    return in;
}

std::ostream &operator<<(std::ostream &out, const AI &ai)
{
    out << ai.GetSymbol();
    return out;
}

void AI::LoadKnowledgeBase()
{
    std::cout << "Loading AI knowledge base from database.txt..." << std::endl;
    std::ifstream file("database.txt");
    if (file.is_open())
    {
        std::string position;
        Coord move;
        while (file >> position >> move)
        {
            knowledgeBase[position] = move;
        }
        file.close();
    }
}
