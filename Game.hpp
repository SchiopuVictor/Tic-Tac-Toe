#pragma once
#include "Board.hpp"
#include "Player.hpp"

class Game {
    Board board;
    Player player1;
    Player player2;

public:
    Game( std::string& name1, std::string& name2);

    void Start();
    void SwitchTurn();
    bool IsGameOver() ;
    void GetWinner();
};
