#pragma once

#include "IPLayer.hpp"
#include "Board.hpp"
#include "Coord.hpp"

#include <iostream>
#include <string>

class Player: public IPLayer
{
    std::string symbol;
    std::string name;
public:
    Player(const std::string &symbol, const std::string &name);

    bool operator==(const Player &other) const;

    std::string GetSymbol() const override;
    std::string GetName() const override;
    Coord MakeMove(const Board& board) const override;
};
std::ostream &operator<<(std::ostream &out, const Player &player);
