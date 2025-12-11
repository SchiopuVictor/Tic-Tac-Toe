#include "RaylibListener.hpp"
#include "raylib.h"
#include <iostream>

/**
 * @file RaylibListener.cpp
 * @brief Implementarea clasei RaylibListener pentru gestionarea input-ului prin mouse și fereastră
 * Clasa RaylibListener implementează interfața IListener și permite
 * utilizatorului să interacționeze cu jocul prin mouse și să ceară ieșirea.
 */

/**
 * @brief Gestionează click-ul pe o celulă de către utilizator.
 * @param board Tabla curentă de joc
 * @return Coord Coordonatele mutării alese de utilizator sau {-1, -1} dacă nu s-a apăsat mouse-ul
 *
 * Detectează apăsarea butonului stâng al mouse-ului și calculează
 * coordonatele celulei corespunzătoare poziției mouse-ului.
 */
Coord RaylibListener::OnCellClicked(const Board &board)
{
    Coord coord{-1, -1};

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << "[debug] Mouse button pressed!\n";
        Vector2 mousePos = GetMousePosition();
        coord = Coord(static_cast<int>(mousePos.x) / CELL_SIZE, static_cast<int>(mousePos.y) / CELL_SIZE);
    }

    return coord;
}

/**
 * @brief Verifică dacă utilizatorul a cerut să iasă din joc.
 * @return true dacă fereastra trebuie închisă, altfel false
 */
bool RaylibListener::OnExitRequested()
{
    return WindowShouldClose();
}
