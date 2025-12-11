#pragma once
#include "../IListener.hpp"
#include "../Coord.hpp"
#include "../Board.hpp"

class ListenerStub : public IListener
{
public:
    Coord OnCellClicked(const Board &board) override
    {
        (void)board;
        return Coord{0, 0};
    }

    bool OnExitRequested() override
    {
        return false;
    }
};
