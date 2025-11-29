#include "RaylibListener.hpp"
#include "raylib.h"

Coord RaylibListener::OnCellClicked(const Board& board)
{
    Coord coord {-1, -1};
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        std::cout << "[debug] Mouse button pressed!\n";
        Vector2 mousePos = GetMousePosition();
        coord = Coord(static_cast<int>(mousePos.x) / CELL_SIZE, static_cast<int>(mousePos.y) / CELL_SIZE);
    }

    return coord;
}


bool RaylibListener::OnExitRequested()
{
    return WindowShouldClose();
}