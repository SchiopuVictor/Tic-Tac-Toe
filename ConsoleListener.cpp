#include "ConsoleListener.hpp"
#include <iostream>

Coord ConsoleListener::OnCellClicked(const Board &board)
{
    int x, y;
    while (true)
    {
        std::cout << "Enter your move (x y): ";
        std::cin >> x >> y;
        if (board.IsValidMove(x, y))
        {
            return Coord(x, y);
        }
        else
        {
            std::cout << "Invalid move. Try again.\n";
        }
    }
    return Coord{-1, -1};
}

bool ConsoleListener::OnExitRequested()
{
    return false;
}