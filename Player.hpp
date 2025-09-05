#pragma once
#include <string>

class Player {
    std::string name;

public:
    Player(char symbol, const std::string &name);
    char symbol;   
    char GetSymbol();
    void GetName();
};
