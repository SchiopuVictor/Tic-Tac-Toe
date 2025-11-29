#pragma once

#include "ilistener.hpp"

class ConsoleListener : public IListener
{
public:
    virtual Coord OnCellClicked(const Board& board) override;
    virtual bool OnExitRequested() override;
};