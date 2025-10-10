#pragma once
#include <string>

class Player
{
public:
    std::string name;
    Player(char symbol, std::string &name);
    bool operator==(const Player &other) const;

    char symbol;
    char GetSymbol();
    void GetName();
};
std::ostream &operator<<(std::ostream &out, const Player &player);
std::istream &operator>>(std::istream &in, Player &player);
