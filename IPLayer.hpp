#pragma once
#include <string>

#include "Coord.hpp"
#include "Board.hpp"

struct IPLayer
{
    virtual std::string GetName() const = 0;
    virtual std::string GetSymbol() const = 0;
    virtual Coord MakeMove(const Board& board) const = 0;
    virtual ~IPLayer() = default;
};