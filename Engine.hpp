#pragma once
#include "Board.hpp"
#include "Player.hpp"

class Game {
    Board board;
    Player player1;
    Player player2;

public:
    Game(const std::string& name1, const std::string& name2);

    void Start();
    void SwitchTurn();
    bool IsGameOver() const;
    void GetWinner() const;
};
