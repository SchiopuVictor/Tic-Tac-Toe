#pragma once
#include <iostream>
#include <string>

class Player
{
public:
    std::string name;
    std::string symbol;

    Player(const std::string &symbol, const std::string &name);

    bool operator==(const Player &other) const;

    std::string GetSymbol();
    void GetName();
};
std::ostream &operator<<(std::ostream &out, const Player &player);
std::istream &operator>>(std::istream &in, Player &player);
