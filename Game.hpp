#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <vector>

class Game
{
public:
    std::shared_ptr<Board> board;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;

    Game(const std::string &name1, const std::string &name2);
    bool operator==(const Game &other) const;

    void Start();
    void SwitchTurn();
    bool IsGameOver();
    void GetWinner();
};

std::ostream &operator<<(std::ostream &out, const Game &game);
