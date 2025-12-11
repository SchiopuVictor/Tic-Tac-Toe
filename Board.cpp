#include "Board.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

/**
 * @file Board.cpp
 * @brief Implementarea clasei Board pentru jocul Tic-Tac-Toe
 * Clasa Board reprezintă tabla de joc pentru Tic-Tac-Toe.
 * Aceasta gestionează plasarea simbolurilor, verificarea câștigului, remizei și starea tablei.
 */

/**
 * @brief Constructor cu dimensiuni personalizate.
 * @param _width Lățimea tablei
 * @param _height Înălțimea tablei
 *
 * Inițializează tabla cu spații goale.
 */
Board::Board(int _width, int _height) : position(_width * _height, ' ') {}

/**
 * @brief Constructor cu poziție inițială.
 * @param pos String care reprezintă starea tablei
 */
Board::Board(const std::string &pos) : position(pos) {}

/**
 * @brief Constructor de copiere.
 * @param other Obiectul Board de copiat
 */
Board::Board(const Board &other) : position(other.position) {}

/**
 * @brief Operator de atribuire.
 * @param other Obiectul Board de atribuit
 * @return Referința către obiectul curent
 */
Board &Board::operator=(const Board &other)
{
    if (this != &other)
    {
        position = other.position;
    }
    return *this;
}

/**
 * @brief Operator de comparare.
 * @param other Obiectul Board cu care se compară
 * @return true dacă pozițiile tablei sunt egale, altfel false
 */
bool Board::operator==(const Board &other) const
{
    return position == other.position;
}

/**
 * @brief Plasează un simbol pe tablă.
 * @param x Coordonata x
 * @param y Coordonata y
 * @param symbol Simbolul de plasat
 * @return true dacă plasarea a fost reușită, false dacă poziția era ocupată
 */
bool Board::PlaceSymbol(int x, int y, const std::string &symbol)
{
    if (IsFree(x, y))
    {
        position[y * GetWidth() + x] = symbol[0];
        return true;
    }
    return false;
}

/**
 * @brief Verifică dacă o mutare este validă.
 * @param x Coordonata x
 * @param y Coordonata y
 * @return true dacă mutarea este validă și poziția liberă, altfel false
 */
bool Board::IsValidMove(int x, int y) const
{
    return x >= 0 && x < GetWidth() && y >= 0 && y < GetHeight() && IsFree(x, y);
}

/**
 * @brief Verifică dacă o poziție este liberă.
 * @param x Coordonata x
 * @param y Coordonata y
 * @return true dacă poziția este liberă, altfel false
 */
bool Board::IsFree(int x, int y) const
{
    return position[y * GetWidth() + x] == ' ';
}

/**
 * @brief Resetează tabla, golind toate pozițiile.
 */
void Board::Reset()
{
    std::fill(position.begin(), position.end(), ' ');
}

/**
 * @brief Verifică dacă un simbol a câștigat.
 * @param symbol Simbolul de verificat
 * @return true dacă simbolul a câștigat, altfel false
 */
bool Board::CheckWin(const std::string &symbol) const
{
    if (symbol.empty())
        return false;
    char s = symbol[0];
    int n = GetWidth();

    for (int y = 0; y < n; ++y)
    {
        bool rowWin = true;
        for (int x = 0; x < n; ++x)
        {
            if (position[y * n + x] != s)
            {
                rowWin = false;
                break;
            }
        }
        if (rowWin)
            return true;
    }

    for (int x = 0; x < n; ++x)
    {
        bool colWin = true;
        for (int y = 0; y < n; ++y)
        {
            if (position[y * n + x] != s)
            {
                colWin = false;
                break;
            }
        }
        if (colWin)
            return true;
    }

    bool diag1Win = true;
    for (int i = 0; i < n; ++i)
    {
        if (position[i * n + i] != s)
        {
            diag1Win = false;
            break;
        }
    }
    if (diag1Win)
        return true;

    bool diag2Win = true;
    for (int i = 0; i < n; ++i)
    {
        if (position[i * n + (n - 1 - i)] != s)
        {
            diag2Win = false;
            break;
        }
    }
    return diag2Win;
}

/**
 * @brief Verifică dacă jocul s-a terminat remiză.
 * @return true dacă tabla este plină și nu există câștigător, altfel false
 */
bool Board::CheckDraw() const
{
    for (char c : position)
    {
        if (c == ' ')
            return false;
    }
    return true;
}

/**
 * @brief Obține lățimea tablei.
 * @return Lățimea tablei
 */
int Board::GetWidth() const { return static_cast<int>(sqrt(position.size())); }

/**
 * @brief Obține înălțimea tablei.
 * @return Înălțimea tablei
 */
int Board::GetHeight() const { return static_cast<int>(sqrt(position.size())); }

/**
 * @brief Convertește tabla într-un string.
 * @return String care reprezintă starea tablei
 */
std::string Board::ToString() const
{
    return position;
}

/**
 * @brief Operator de intrare din stream.
 * @param in Stream-ul de intrare
 * @param board Obiectul Board care va fi citit
 * @return Referința către stream-ul de intrare
 */
std::istream &operator>>(std::istream &in, Board &board)
{
    std::string str;
    in >> str;
    board = Board(str);
    return in;
}

/**
 * @brief Operator de ieșire în stream.
 * @param out Stream-ul de ieșire
 * @param board Obiectul Board care va fi scris
 * @return Referința către stream-ul de ieșire
 */
std::ostream &operator<<(std::ostream &out, const Board &board)
{
    out << board.ToString();
    return out;
}
