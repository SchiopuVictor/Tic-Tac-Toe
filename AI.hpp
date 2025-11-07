#pragma once
#include "Board.hpp"
#include "Coord.hpp"
#include "IPLayer.hpp"

#include <iostream>
#include <map>
#include <string>

class AI: public IPLayer
{
    std::string symbol;
    std::map<std::string, Coord> knowledgeBase;

    void LoadKnowledgeBase();
public:

    AI();
    explicit AI(const std::string &symbol);

    AI(const AI &other);

    AI &operator=(const AI &other);
    bool operator==(const AI &other) const;

    std::string GetName() const override;
    std::string GetSymbol() const override;
    Coord MakeMove(const Board& board) const override;
};

std::istream &operator>>(std::istream &in, AI &ai);
std::ostream &operator<<(std::ostream &out, const AI &ai);
