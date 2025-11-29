#pragma once
#include "coord.hpp"
#include "Board.hpp"

class IListener
{
public:
    virtual ~IListener() = default;
    virtual Coord OnCellClicked(const Board& board) = 0;
    virtual bool OnExitRequested() = 0;
};