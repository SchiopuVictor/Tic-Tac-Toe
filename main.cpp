#include "Game.hpp"
#include <iostream>
#include <string>

/**
 * @file main.cpp
 * @brief Punctul de intrare în aplicația Tic-Tac-Toe
 *
 * Proiect: Tic-Tac-Toe
 * Autor: [Schiopu Victor]
 * An: 2025
 *
 * Programul inițiază jocul, citește numele jucătorilor de la consolă
 * și pornește bucla principală a jocului.
 */

int main()
{
    std::string name1;
    std::string name2;

    std::cout << "Introdu numele jucătorului 1: ";
    std::cin >> name1;

    std::cout << "Introdu numele jucătorului 2: ";
    std::cin >> name2;

    Game game(name1, name2);
    game.Start();

    return 0;
}
