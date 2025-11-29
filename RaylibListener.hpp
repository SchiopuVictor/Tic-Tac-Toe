#pragma once

#include "ilistener.hpp"
#include "defines.hpp"

class RaylibListener : public IListener
{
public:
    virtual Coord OnCellClicked(const Board& board) override;
    virtual bool OnExitRequested() override;
};