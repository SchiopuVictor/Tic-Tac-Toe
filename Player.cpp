#include "Player.hpp"
#include <iostream>

Player::Player(char symbol, std::string &name) : symbol(symbol), name(name) {}

char Player::GetSymbol() {
    return symbol;
}

void Player::GetName() {
    std::cout << "Player name: " << name << "\n";
}
