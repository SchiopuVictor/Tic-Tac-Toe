#include "Player.hpp"
#include <iostream>

Player::Player(char symbol, std::string &name) : symbol(symbol), name(name) {}

bool Player::operator==(const Player &other) const
{
    return symbol == other.symbol && name == other.name;
}

char Player::GetSymbol()
{
    return symbol;
}

void Player::GetName()
{
    std::cout << "Player name: " << name << "\n";
}

std::ostream &operator<<(std::ostream &out, const Player &player)
{
    out << "Player: " << player.name << " (Symbol: " << player.symbol << ")";
    return out;
}

std::istream &operator>>(std::istream &in, Player &player)
{
    std::cout << "Enter player name: ";
    in >> player.name;
    std::cout << "Enter player symbol: ";
    in >> player.symbol;
    return in;
}
