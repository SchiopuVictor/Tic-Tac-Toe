#include "Game.hpp"
#include <iostream>

int main() {
    std::string name1 = "Alice";
    std::string name2 = "Bob";

    Game game(name1, name2);  
    game.Start();
    
    return 0;
}
