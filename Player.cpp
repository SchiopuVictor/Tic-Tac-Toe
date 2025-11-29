#include "Player.hpp"
#include <iostream>
#include "ConsoleListener.hpp"
#include "RaylibListener.hpp"

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
    std::shared_ptr<IListener> listener = std::make_shared<RaylibListener>();
    return listener->OnCellClicked(board);
}