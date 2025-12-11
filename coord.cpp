#include "coord.hpp"

/**
 * @file coord.cpp
 * @brief Implementarea operatorilor de intrare/ieșire pentru structura Coord
 * Structura Coord reprezintă coordonatele unei celule pe tabla de joc.
 * Operatorii permit citirea și afișarea coordonatelor din/în fluxuri.
 */

/**
 * @brief Operator de intrare pentru Coord.
 * @param in Stream-ul de intrare
 * @param coord Obiectul Coord care va fi citit
 * @return Referința către stream-ul de intrare
 *
 * Citește valorile x și y din stream și le atribuie coord.
 */
std::istream &operator>>(std::istream &in, Coord &coord)
{
    in >> coord.x >> coord.y;
    return in;
}

/**
 * @brief Operator de ieșire pentru Coord.
 * @param out Stream-ul de ieșire
 * @param coord Obiectul Coord care va fi scris
 * @return Referința către stream-ul de ieșire
 *
 * Scrie valorile x și y în stream, separate printr-un spațiu.
 */
std::ostream &operator<<(std::ostream &out, const Coord &coord)
{
    out << coord.x << " " << coord.y;
    return out;
}
