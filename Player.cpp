#include "Player.hpp"
#include <iostream>

Player::Player(const std::string &symbol, const std::string &name)
    : symbol(symbol), name(name) {}

bool Player::operator==(const Player &other) const
{
    return symbol == other.symbol && name == other.name;
}

std::string Player::GetSymbol() const
{
    return symbol;
}

std::string Player::GetName() const
{
    return name;
}

std::ostream &operator<<(std::ostream &out, const Player &player)
{
    out << "Player: " << player.GetName() << " (Symbol: " << player.GetSymbol() << ")";
    return out;
}

Coord Player::MakeMove(const Board& board) const{
    int x, y;
    while (true) {
        std::cout << GetName() << ", enter your move (x y): ";
        std::cin >> x >> y;
        if (board.IsValidMove(x, y)) {
            return Coord(x, y);
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
}