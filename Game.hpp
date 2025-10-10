#pragma once
#include "Board.hpp"
#include "Player.hpp"

class Game
{

public:
    Board board;
    Player player1;
    Player player2;
    Game(std::string &name1, std::string &name2);
    bool operator==(const Game &other) const;

    void Start();
    void SwitchTurn();
    bool IsGameOver();
    void GetWinner();
};
std::ostream &operator<<(std::ostream &out, const Game &game);
