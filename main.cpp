#include "Game.hpp"
#include <iostream>
#include <string>

int main()
{
    std::string name1;
    std::string name2;

    std::cout << "Introdu numele jucătorului 1: ";
    std::cin >> name1;

    std::cout << "Introdu numele jucătorului 2: ";
    std::cin >> name2;

    Game game(name1, name2);

    game.Start();

    return 0;
}
