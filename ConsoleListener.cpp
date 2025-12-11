#include "ConsoleListener.hpp"
#include <iostream>

/**
 * @file ConsoleListener.cpp
 * @brief Implementarea clasei ConsoleListener pentru interacțiunea cu utilizatorul
 * Clasa ConsoleListener permite utilizatorului să interacționeze cu jocul
 * prin consola standard, citind mutările și gestionând cererile de ieșire.
 */

/**
 * @brief Gestionează click-ul pe o celulă de către utilizator.
 * @param board Tabla curentă de joc
 * @return Coord Coordonatele mutării alese de utilizator
 *
 * Solicită utilizatorului să introducă coordonatele mutării până când
 * acestea sunt valide conform stării tablei.
 */
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

/**
 * @brief Verifică dacă utilizatorul a cerut să iasă din joc.
 * @return bool Întotdeauna returnează false în această implementare
 */
bool ConsoleListener::OnExitRequested()
{
    return false;
}
