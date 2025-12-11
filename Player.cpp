#include "Player.hpp"
#include <iostream>
#include "ConsoleListener.hpp"
#include "RaylibListener.hpp"

/**
 * @file Player.cpp
 * @brief Implementarea clasei Player pentru un jucător uman în Tic-Tac-Toe
 * Clasa Player reprezintă un jucător uman care poate face mutări
 * prin intermediul unui listener (interfață de input).
 */

/**
 * @brief Constructorul clasei Player.
 * @param symbol Simbolul jucătorului ("X" sau "O")
 * @param name Numele jucătorului
 */
Player::Player(const std::string &symbol, const std::string &name)
    : symbol(symbol), name(name) {}

/**
 * @brief Operator de comparare între doi jucători.
 * @param other Jucătorul cu care se compară
 * @return true dacă simbolul și numele sunt egale, altfel false
 */
bool Player::operator==(const Player &other) const
{
    return symbol == other.symbol && name == other.name;
}

/**
 * @brief Obține simbolul jucătorului.
 * @return Simbolul jucătorului ("X" sau "O")
 */
std::string Player::GetSymbol() const
{
    return symbol;
}

/**
 * @brief Obține numele jucătorului.
 * @return Numele jucătorului
 */
std::string Player::GetName() const
{
    return name;
}

/**
 * @brief Operator de ieșire în stream pentru Player.
 * @param out Stream-ul de ieșire
 * @param player Obiectul Player care va fi scris
 * @return Referința către stream-ul de ieșire
 */
std::ostream &operator<<(std::ostream &out, const Player &player)
{
    out << "Player: " << player.GetName() << " (Symbol: " << player.GetSymbol() << ")";
    return out;
}

/**
 * @brief Determină mutarea jucătorului pe tabla de joc.
 * @param board Tabla curentă de joc
 * @return Coord Coordonatele mutării alese de jucător
 *
 * Folosește un listener (RaylibListener) pentru a obține input-ul de la jucător.
 */
Coord Player::MakeMove(const Board &board) const
{
    std::shared_ptr<IListener> listener = std::make_shared<RaylibListener>();
    return listener->OnCellClicked(board);
}
