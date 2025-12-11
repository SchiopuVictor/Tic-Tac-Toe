#include "AI.hpp"
#include <iostream>
#include <fstream>

/**
 * @file AI.cpp
 * @brief Implementarea clasei AI pentru un jucător automat de Tic-Tac-Toe
 * Clasa AI reprezintă un jucător automat care poate efectua mutări
 * pe baza unei baze de cunoștințe sau aleatoriu dacă mutarea nu este
 * înregistrată.
 */

/**
 * @brief Constructor implicit.
 *
 * Inițializează simbolul AI la "O" și încarcă baza de cunoștințe.
 */
AI::AI() : symbol("O")
{
    srand(time(nullptr));
    LoadKnowledgeBase();
}

/**
 * @brief Constructor cu simbol personalizat.
 * @param symbol Simbolul folosit de AI
 *
 * Creează un AI care folosește simbolul dat și încarcă baza de cunoștințe.
 */
AI::AI(const std::string &symbol) : symbol(symbol)
{
    LoadKnowledgeBase();
}

/**
 * @brief Constructor de copiere.
 * @param other Obiectul AI de copiat
 */
AI::AI(const AI &other) : symbol(other.symbol)
{
    LoadKnowledgeBase();
}

/**
 * @brief Operator de atribuire.
 * @param other Obiectul AI de atribuit
 * @return Referința către obiectul curent
 */
AI &AI::operator=(const AI &other)
{
    if (this != &other)
    {
        symbol = other.symbol;
    }
    return *this;
}

/**
 * @brief Operator de comparare.
 * @param other Obiectul AI cu care se compară
 * @return true dacă simbolurile sunt egale, altfel false
 */
bool AI::operator==(const AI &other) const
{
    return symbol == other.symbol;
}

/**
 * @brief Determină mutarea pe care o va face AI-ul.
 * @param board Tabla curentă de joc
 * @return Coordonatele mutării alese
 *
 * Dacă tabla curentă există în baza de cunoștințe, se folosește mutarea optimă.
 * În caz contrar, se alege o mutare aleatorie pe o poziție liberă.
 */
Coord AI::MakeMove(const Board &board) const
{
    if (knowledgeBase.find(board.ToString()) != knowledgeBase.end())
    {
        return knowledgeBase.at(board.ToString());
    }
    int x, y;
    do
    {
        x = rand() % board.GetWidth();
        y = rand() % board.GetHeight();
    } while (!board.IsFree(x, y));
    return Coord(x, y);
}

/**
 * @brief Obține numele AI-ului.
 * @return Stringul "AI Player"
 */
std::string AI::GetName() const
{
    return "AI Player";
}

/**
 * @brief Obține simbolul folosit de AI.
 * @return Simbolul AI ("X" sau "O")
 */
std::string AI::GetSymbol() const
{
    return symbol;
}

/**
 * @brief Operator de intrare din stream.
 * @param in Stream-ul de intrare
 * @param ai Obiectul AI care va fi citit
 * @return Referința către stream-ul de intrare
 */
std::istream &operator>>(std::istream &in, AI &ai)
{
    std::string dummy;
    in >> dummy;
    ai = AI(dummy);
    return in;
}

/**
 * @brief Operator de ieșire în stream.
 * @param out Stream-ul de ieșire
 * @param ai Obiectul AI care va fi scris
 * @return Referința către stream-ul de ieșire
 */
std::ostream &operator<<(std::ostream &out, const AI &ai)
{
    out << ai.GetSymbol();
    return out;
}

/**
 * @brief Încarcă baza de cunoștințe dintr-un fișier extern.
 *
 * Dacă fișierul "database.txt" există, acesta va fi citit și
 * stările tablei și mutările corespunzătoare vor fi stocate în knowledgeBase.
 */
void AI::LoadKnowledgeBase()
{
    std::ifstream file("database.txt");
    if (file.is_open())
    {
        std::string position;
        Coord move;
        while (file >> position >> move)
        {
            knowledgeBase[position] = move;
        }
        file.close();
    }
}
